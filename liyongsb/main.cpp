#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>
#include<malloc.h>
#define PSIZE 4096 /*管道文件的大小*/
#define BSIZE 128  /*默认缓冲区的大小*/
#define NOFILE 20  /*u_ofile1121表可分配的个数*/
#define NFILE 20   /*file表可分配的个数*/
#define NPIPE 20   /*pipecb1121可分配的个数*/
/*进程的u_file表*/
int u_ofile1121[NOFILE];
/*模拟file表*/
struct
{
    char f_flag;/*读写标志，'w'表示写，'r'表示读*/
    int f_count;/*表示此表项的状态，=0表示此表项没被使用，可分配；=1表示此表项在被使用，不可再分配*/
    int f_inode;/*对应的pipecb1121表下标*/
    long f_offset;/*读写指针，当前已读或已写个数*/
}file[NFILE];
/*管道控制块*/
struct
{
    char *p_addr;/*管道文件基地址*/
    int p_size;/*管道文件大小，PSIZE*/
    int p_count;/*=2表示读写都在被进行，=1表示在被读或被写，=0表示管道没被使用，可分配*/
}pipecb1121[NPIPE];
/*模拟管道文件*/
char *pfile;
/*管道的写入写出端*/
int fd[2];
/*锁机制，实现互斥*/
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
/*进程间通信，实现同步*/
pthread_cond_t rflag = PTHREAD_COND_INITIALIZER;/*读信号量*/
pthread_cond_t wflag = PTHREAD_COND_INITIALIZER;/*写信号量*/
/*线程创建函数只能传一个参数，用结构体来封装所有参数*/
struct arg_set
{
    char *fname;       /*文件名*/
    int f;             /*传递fdp[]*/
};
/*u_ofile1121表初始化*/
int u_ofile_init1121()
{
    printf("init the u_ofile1121\n");
    int i;
    for(i=0;i<NOFILE;i++)
        u_ofile1121[i] = -1;
    u_ofile1121[0]=0;
    u_ofile1121[1]=0;
    u_ofile1121[2]=0;
    return 0;
}
/*创建管道*/
int pipe_simulate1121(int a[])
{
    printf("start to create a pipe\n");
    int i;
    for(i=0;i<NOFILE;i++)
    {
       if(u_ofile1121[i]==-1)
       {
          a[0] = i;/*读*/
          u_ofile1121[i] = 0;/*读端*/
          break;
       }
    }
    for(i;i<NOFILE;i++)
    {
       if(u_ofile1121[i]==-1)
       {
          a[1] = i;/*写*/
          u_ofile1121[i] = 1;/*写端*/
          break;
       }
    }
    if(i>=NOFILE)
    {
        printf("u_ofile1121分配失败,failure to create a pipe\n");
        return -2;
    }
    pfile = (char *)malloc(PSIZE*sizeof(char));/*申请模拟管道用的内存空间*/
    if(pfile==NULL)/*申请可能不成功*/
    {
        printf("failure to create a pipe\n");
        return -1;
    }
    for(i=0;i<NFILE;i++)
    {
        if(file[i].f_count!=1)
        {
          file[i].f_flag = 'r';/*读标志*/
          //file[i].f_inode = 0;/*读对应pipecb1121表下标*/
          file[i].f_count = 1;/*file[0]这个表项在被使用，不可再分配*/
          file[i].f_offset = 0;/*读指针*/
          u_ofile1121[a[0]] = i;/*读端*/
          break;
        }
    }
    for(i=0;i<NFILE;i++)
    {
        if(file[i].f_count!=1)
        {
          file[i].f_flag = 'w';/*写标志*/
          //file[i].f_inode = 0;/*写对应pipecb1121控制块下标*/
          file[i].f_count = 1;/*file[1]这个表项在被使用，不可再分配*/
          file[i].f_offset = 0;/*写指针*/
          u_ofile1121[a[1]] = i;/*写端*/
          break;
        }
    }
    if(i>=NFILE)
    {
        printf("failure to create a pipe\n");
        return -1;
    }
    for(i=0;i<NPIPE;i++)
    {
        if(pipecb1121[i].p_count==0)
        {
          pipecb1121[i].p_addr = pfile;/*给管道文件基地址赋值*/
          pipecb1121[i].p_size = PSIZE;/*管道文件大小*/
          pipecb1121[i].p_count = 2;/*读写都在进行，此pipecb1121表项不可再分*/
          file[u_ofile1121[a[0]]].f_inode = i;
          file[u_ofile1121[a[1]]].f_inode = i;
          break;
        }
    }
    if(i>=NPIPE)
    {
        printf("failure to create a pipe\n");
        return -1;
    }
    printf("Secceed create the pipe\n");
    return 0;/*分配成功*/
}
/*关闭管道*/
int close_simulate1121(int a[])
{
    printf("start to close the pipe you have created\n");
    char *p;
    int i;
    for(i=0;i<2;i++)
    {
        p=pipecb1121[file[u_ofile1121[a[i]]].f_inode].p_addr;
        /*
        if(p!=NULL)
            free(p); //释放管道内存
        */
        pipecb1121[file[u_ofile1121[a[i]]].f_inode].p_count = 0; /*管道控制块计数清零*/
        file[u_ofile1121[a[i]]].f_count = 0; /*file表项计数清零*/
        u_ofile1121[a[i]] = -1; /*u_ofile1121表项清空*/
        a[i] = -1; /*fdp[]清空?*/
    }
    printf("secceed close the pipe\n");
    return 0;
}
/*写管道*/
int numwrite_simulate1121;
int write_simulate1121(int fd,char *ca,int n)//将内存ca内容写入n个字符到管道fd里
{
    printf("(memory---->pipe)input data in memory *ca into pipe\n");
    numwrite_simulate1121++;
    long offr,offw;/*读写指针，实际是读写字符个数*/
    int r;/*管道文件读端*/
    int m;/*若ca中的字符不能一次写完，m用来表示一次可写入的字符的最大数*/
    int w = u_ofile1121[fd];/*管道文件写端*/
    int pf = file[w].f_inode;/*读管道对应的pipecb1121表的下标*/
    int n1 = n;/*一次应该写入的字符个数*/
    int wstart = 0;/*计数器，写入字符个数*/
    int i = 0;
    for(i;i<NFILE;i++)/*寻找写管道对应的读管道的读端*/
    {
        if((file[i].f_flag=='r')&&(file[i].f_inode==pf))
        {
            r = i;
            break;
        }
        else
        {
            continue;
        }
    }
    printf("----add the lock\n");
//    pthread_mutex_lock(&lock);/*互斥锁，相当于进入临界区*/
    offr = file[r].f_offset;/*赋值读指针*/
    offw = file[w].f_offset;/*赋值写指针*/
    if((offw+n1-PSIZE)>offr)/*不能一次写完*/
    {
        if(pipecb1121[pf].p_count==0)/*对文件的复制操作已进行结束，管道文件被释放*/
        {
            printf("对文件的复制操作已进行结束，管道文件被释放\n");
            return 0;
        }
        else
        {
            m = PSIZE+offr-offw;/*最多可写入数*/
            for(wstart=0;wstart<m;wstart++)
        	{
                *(pipecb1121[pf].p_addr+offw%PSIZE) = *ca;
                ca++;
                offw++;
        	}
            file[w].f_offset = offw;/*重定位写指针位置*/
            n1 = n1-m;/*剩余需要读的字符个数*/
            printf("weak up the read thread , pipe is readable\n");
            pthread_cond_signal(&rflag);/*唤醒读线程，管道可读*/
            printf("write thread is blocked and under the statement of waiting\n");
//            pthread_cond_wait(&wflag,&lock);/*写线程封锁等待*/
        }
    }
    /*一次性可将ca中内容全部写入管道*/
    offr = file[r].f_offset;
    offw = file[w].f_offset;
    for(wstart=0;wstart<n1;wstart++)
    {
        /*printf("%d\n",pipecb1121[pf].p_addr);*/
        *(pipecb1121[pf].p_addr+offw%PSIZE) = *ca;
        /*printf("%d\n",wstart);*/
        ca++;
        offw++;
    }
    file[w].f_offset = offw;
//    pthread_cond_signal(&rflag);
    printf("----release the lock\n");
//    pthread_mutex_unlock(&lock);
    printf("Secceed (memory---->pipe)input data in memory *ca into pipe\n");
    return n;/*返回写入字符个数*/
}
/*读管道*/
int numread_simulate1121;//read_simulate1121 diaoyongshu
int read_simulate1121(int fd,char *ca,int n)//将管道fd内容读取n个字符到内存ca里
{
    printf("(pipe---->memory)output data from pipe into memory *ca\n");
    numread_simulate1121++;
    long offr,offw;/*读写指针，实际是读写字符个数*/
    int w;/*管道文件写端*/
    int m;/*若ca中的字符不能一次读完，m用来表示一次可读出的字符的最大数*/
    int r = u_ofile1121[fd];/*管道文件读端*/
    int pf = file[r].f_inode;/*读管道对应的pipecb1121表的下标*/
    int rstart = 0;/*计数器，读出字符个数*/
    int i = 0;

    for(i;i<NFILE;i++)/*寻找读管道对应的读管道的端*/
    {
        if((file[i].f_flag=='w')&&(file[i].f_inode==pf))
        {
            w = i;
            break;
        }
        else
        {
            continue;
        }
    }

    printf("----add the lock\n");
//    pthread_mutex_lock(&lock);/*互斥锁，相当于进入临界区*/

    offr = file[r].f_offset;/*赋值读指针*/
    offw = file[w].f_offset;/*赋值写指针*/
    if(offr==offw)/*管道空，无内容可读*/
    {
        printf("pipe is empty , nothing to output\n");
        if(pipecb1121[pf].p_count==1)/*写端关闭*/
        {
            pipecb1121[pf].p_count--;/*文件的复制以完成，释放管道文件的空间*/
            printf("the write point is closed,the copy of the file is finished\n");
            return 0;
        }
        else
        {
            printf("weak up the write thread , make the pipe writable\n");
//            pthread_cond_signal(&wflag);/*唤醒写线程，管道可写*/
            printf("read thread is blocked and under the statement of waiting\n");
//            pthread_cond_wait(&rflag,&lock);/*读线程封锁等待*/
        }
    }
    offr = file[r].f_offset;
    offw = file[w].f_offset;
    m = n<=(offw-offr)?n:(offw-offr);/*得到可读字符个数*/
    for(rstart=0;rstart<m;rstart++)
    {
        *ca = *(pipecb1121[pf].p_addr+offr%PSIZE);
        ca++;
        offr++;
    }
    file[r].f_offset = offr;/*重定位读指针位置*/

    printf("weak the write thread , make the pipe writable\n");
//    pthread_cond_signal(&wflag);

    printf("----release the lock\n");
//    pthread_mutex_unlock(&lock);

    printf("Secceed (pipe---->memory)output data from the pipe into memory *ca\n");
    return m;
}
/*线程调用，读源文件，写管道*/
void *pwrite1121(void *a)//将源文件a内容写入管道中
{
    printf("(file---->pipe)input data from the original file into pipe\n");
    char abuf1[BSIZE];
    struct arg_set *args=(struct arg_set *)a;/*需要传入多个参数时，用结构体传*/
    int fdr;
    int n_r;/*管道文件写入字符数*/
    if((fdr=open(args->fname,O_RDONLY))!=-1)
    {
        while((n_r=read(fdr,abuf1,BSIZE))>0)/*读文件，写管道*/
        {
            printf("(file---->memory)input data in original file into memory *ca\n");
            printf("Secceed (file---->memory)input data in original file into memory *ca\n");
            //printf("(memory---->pipe)input data in memory *ca into pipe\n");
            write_simulate1121(args->f,abuf1,n_r);
            //printf("Secceed (memory---->pipe)input\n");
        }
        pipecb1121[file[u_ofile1121[args->f]].f_inode].p_count--;/*文件已读完，关闭管道写端*/
    }
    else
    {
        perror(args->fname);/*打开源文件可能不成功*/
        return NULL;
    }
    printf("Secceed (file---->pipe)input data from the original file into pipe\n");
    return NULL;
}
/*线程调用，写目标文件，读管道*/
void *pread1121(void *a)//读取管道，将其中内容写入新建文件中
{
    printf("(pipe---->file)output data from the pipe into new file\n");
    char abuf2[BSIZE];/*缓冲区*/
    struct arg_set *args=(struct arg_set *)a;/*需要传入多个参数时，用结构体传*/
    int fdw;
    int n_w;/*管道文件读出字符数*/
    if((fdw=open(args->fname,O_CREAT|O_RDWR,0777))!=-1)
    {
        while((n_w=read_simulate1121(args->f,abuf2,BSIZE))>0)/*读管道，写文件*/
        {
            //printf("(pipe---->memory)output data from pipe into memory *ca\n");
            //printf("Secceed (pipe---->memory)output data from pipe into memory *ca\n");
            printf("(memory---->file)output data in memory *ca into file\n");
            write(fdw,abuf2,n_w);
            printf("Secceed (memory---->file)output data from the pipe into new file\n");
        }
    }
    else
    {
        perror(args->fname);/*打开目标文件可能出错*/
        return NULL;
    }
    printf("Secceed (pipe---->file)output data from the pipe into new file\n");
    return NULL;
}

/*主函数*/
int main(int argc,char *argv[])
{
    int x;
    u_ofile_init1121();
    while((x=pipe_simulate1121(fd))==-1);/*创建管道，即申请空间*/
    if(x==-2)
        return -1;
    pthread_t t;//thread ID
    struct arg_set args[2];/*用结构体传写线程需要的参数:文件名,管道文件读写端*/
    args[0].fname=argv[1];/*源文件名*/
    args[0].f=fd[1];/*管道文件写端*/
    args[1].fname=argv[2];/*目标文件名*/
    args[1].f=fd[0];/*管道文件读端*/
//    pthread_create(&t,NULL,pwrite1121,(void *)&args[0]);/*创建子线程,写管道*/
    pread1121((void *)&args[1]);/*主线程调用,读管道*/
//    pthread_join(t,NULL);/*等待写线程结束*/
    close_simulate1121(fd);
    printf("\nnum of read_simulate1121 = %d\n",numread_simulate1121);
    printf("num of write_simulate1121 = %d\n",numwrite_simulate1121);
    return 0;
}

