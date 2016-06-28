#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>
#include<malloc.h>
#define PSIZE 4096 /*�ܵ��ļ��Ĵ�С*/
#define BSIZE 128  /*Ĭ�ϻ������Ĵ�С*/
#define NOFILE 20  /*u_ofile1121��ɷ���ĸ���*/
#define NFILE 20   /*file��ɷ���ĸ���*/
#define NPIPE 20   /*pipecb1121�ɷ���ĸ���*/
/*���̵�u_file��*/
int u_ofile1121[NOFILE];
/*ģ��file��*/
struct
{
    char f_flag;/*��д��־��'w'��ʾд��'r'��ʾ��*/
    int f_count;/*��ʾ�˱����״̬��=0��ʾ�˱���û��ʹ�ã��ɷ��䣻=1��ʾ�˱����ڱ�ʹ�ã������ٷ���*/
    int f_inode;/*��Ӧ��pipecb1121���±�*/
    long f_offset;/*��дָ�룬��ǰ�Ѷ�����д����*/
}file[NFILE];
/*�ܵ����ƿ�*/
struct
{
    char *p_addr;/*�ܵ��ļ�����ַ*/
    int p_size;/*�ܵ��ļ���С��PSIZE*/
    int p_count;/*=2��ʾ��д���ڱ����У�=1��ʾ�ڱ�����д��=0��ʾ�ܵ�û��ʹ�ã��ɷ���*/
}pipecb1121[NPIPE];
/*ģ��ܵ��ļ�*/
char *pfile;
/*�ܵ���д��д����*/
int fd[2];
/*�����ƣ�ʵ�ֻ���*/
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
/*���̼�ͨ�ţ�ʵ��ͬ��*/
pthread_cond_t rflag = PTHREAD_COND_INITIALIZER;/*���ź���*/
pthread_cond_t wflag = PTHREAD_COND_INITIALIZER;/*д�ź���*/
/*�̴߳�������ֻ�ܴ�һ���������ýṹ������װ���в���*/
struct arg_set
{
    char *fname;       /*�ļ���*/
    int f;             /*����fdp[]*/
};
/*u_ofile1121���ʼ��*/
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
/*�����ܵ�*/
int pipe_simulate1121(int a[])
{
    printf("start to create a pipe\n");
    int i;
    for(i=0;i<NOFILE;i++)
    {
       if(u_ofile1121[i]==-1)
       {
          a[0] = i;/*��*/
          u_ofile1121[i] = 0;/*����*/
          break;
       }
    }
    for(i;i<NOFILE;i++)
    {
       if(u_ofile1121[i]==-1)
       {
          a[1] = i;/*д*/
          u_ofile1121[i] = 1;/*д��*/
          break;
       }
    }
    if(i>=NOFILE)
    {
        printf("u_ofile1121����ʧ��,failure to create a pipe\n");
        return -2;
    }
    pfile = (char *)malloc(PSIZE*sizeof(char));/*����ģ��ܵ��õ��ڴ�ռ�*/
    if(pfile==NULL)/*������ܲ��ɹ�*/
    {
        printf("failure to create a pipe\n");
        return -1;
    }
    for(i=0;i<NFILE;i++)
    {
        if(file[i].f_count!=1)
        {
          file[i].f_flag = 'r';/*����־*/
          //file[i].f_inode = 0;/*����Ӧpipecb1121���±�*/
          file[i].f_count = 1;/*file[0]��������ڱ�ʹ�ã������ٷ���*/
          file[i].f_offset = 0;/*��ָ��*/
          u_ofile1121[a[0]] = i;/*����*/
          break;
        }
    }
    for(i=0;i<NFILE;i++)
    {
        if(file[i].f_count!=1)
        {
          file[i].f_flag = 'w';/*д��־*/
          //file[i].f_inode = 0;/*д��Ӧpipecb1121���ƿ��±�*/
          file[i].f_count = 1;/*file[1]��������ڱ�ʹ�ã������ٷ���*/
          file[i].f_offset = 0;/*дָ��*/
          u_ofile1121[a[1]] = i;/*д��*/
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
          pipecb1121[i].p_addr = pfile;/*���ܵ��ļ�����ַ��ֵ*/
          pipecb1121[i].p_size = PSIZE;/*�ܵ��ļ���С*/
          pipecb1121[i].p_count = 2;/*��д���ڽ��У���pipecb1121������ٷ�*/
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
    return 0;/*����ɹ�*/
}
/*�رչܵ�*/
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
            free(p); //�ͷŹܵ��ڴ�
        */
        pipecb1121[file[u_ofile1121[a[i]]].f_inode].p_count = 0; /*�ܵ����ƿ��������*/
        file[u_ofile1121[a[i]]].f_count = 0; /*file�����������*/
        u_ofile1121[a[i]] = -1; /*u_ofile1121�������*/
        a[i] = -1; /*fdp[]���?*/
    }
    printf("secceed close the pipe\n");
    return 0;
}
/*д�ܵ�*/
int numwrite_simulate1121;
int write_simulate1121(int fd,char *ca,int n)//���ڴ�ca����д��n���ַ����ܵ�fd��
{
    printf("(memory---->pipe)input data in memory *ca into pipe\n");
    numwrite_simulate1121++;
    long offr,offw;/*��дָ�룬ʵ���Ƕ�д�ַ�����*/
    int r;/*�ܵ��ļ�����*/
    int m;/*��ca�е��ַ�����һ��д�꣬m������ʾһ�ο�д����ַ��������*/
    int w = u_ofile1121[fd];/*�ܵ��ļ�д��*/
    int pf = file[w].f_inode;/*���ܵ���Ӧ��pipecb1121����±�*/
    int n1 = n;/*һ��Ӧ��д����ַ�����*/
    int wstart = 0;/*��������д���ַ�����*/
    int i = 0;
    for(i;i<NFILE;i++)/*Ѱ��д�ܵ���Ӧ�Ķ��ܵ��Ķ���*/
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
//    pthread_mutex_lock(&lock);/*���������൱�ڽ����ٽ���*/
    offr = file[r].f_offset;/*��ֵ��ָ��*/
    offw = file[w].f_offset;/*��ֵдָ��*/
    if((offw+n1-PSIZE)>offr)/*����һ��д��*/
    {
        if(pipecb1121[pf].p_count==0)/*���ļ��ĸ��Ʋ����ѽ��н������ܵ��ļ����ͷ�*/
        {
            printf("���ļ��ĸ��Ʋ����ѽ��н������ܵ��ļ����ͷ�\n");
            return 0;
        }
        else
        {
            m = PSIZE+offr-offw;/*����д����*/
            for(wstart=0;wstart<m;wstart++)
        	{
                *(pipecb1121[pf].p_addr+offw%PSIZE) = *ca;
                ca++;
                offw++;
        	}
            file[w].f_offset = offw;/*�ض�λдָ��λ��*/
            n1 = n1-m;/*ʣ����Ҫ�����ַ�����*/
            printf("weak up the read thread , pipe is readable\n");
            pthread_cond_signal(&rflag);/*���Ѷ��̣߳��ܵ��ɶ�*/
            printf("write thread is blocked and under the statement of waiting\n");
//            pthread_cond_wait(&wflag,&lock);/*д�̷߳����ȴ�*/
        }
    }
    /*һ���Կɽ�ca������ȫ��д��ܵ�*/
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
    return n;/*����д���ַ�����*/
}
/*���ܵ�*/
int numread_simulate1121;//read_simulate1121 diaoyongshu
int read_simulate1121(int fd,char *ca,int n)//���ܵ�fd���ݶ�ȡn���ַ����ڴ�ca��
{
    printf("(pipe---->memory)output data from pipe into memory *ca\n");
    numread_simulate1121++;
    long offr,offw;/*��дָ�룬ʵ���Ƕ�д�ַ�����*/
    int w;/*�ܵ��ļ�д��*/
    int m;/*��ca�е��ַ�����һ�ζ��꣬m������ʾһ�οɶ������ַ��������*/
    int r = u_ofile1121[fd];/*�ܵ��ļ�����*/
    int pf = file[r].f_inode;/*���ܵ���Ӧ��pipecb1121����±�*/
    int rstart = 0;/*�������������ַ�����*/
    int i = 0;

    for(i;i<NFILE;i++)/*Ѱ�Ҷ��ܵ���Ӧ�Ķ��ܵ��Ķ�*/
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
//    pthread_mutex_lock(&lock);/*���������൱�ڽ����ٽ���*/

    offr = file[r].f_offset;/*��ֵ��ָ��*/
    offw = file[w].f_offset;/*��ֵдָ��*/
    if(offr==offw)/*�ܵ��գ������ݿɶ�*/
    {
        printf("pipe is empty , nothing to output\n");
        if(pipecb1121[pf].p_count==1)/*д�˹ر�*/
        {
            pipecb1121[pf].p_count--;/*�ļ��ĸ�������ɣ��ͷŹܵ��ļ��Ŀռ�*/
            printf("the write point is closed,the copy of the file is finished\n");
            return 0;
        }
        else
        {
            printf("weak up the write thread , make the pipe writable\n");
//            pthread_cond_signal(&wflag);/*����д�̣߳��ܵ���д*/
            printf("read thread is blocked and under the statement of waiting\n");
//            pthread_cond_wait(&rflag,&lock);/*���̷߳����ȴ�*/
        }
    }
    offr = file[r].f_offset;
    offw = file[w].f_offset;
    m = n<=(offw-offr)?n:(offw-offr);/*�õ��ɶ��ַ�����*/
    for(rstart=0;rstart<m;rstart++)
    {
        *ca = *(pipecb1121[pf].p_addr+offr%PSIZE);
        ca++;
        offr++;
    }
    file[r].f_offset = offr;/*�ض�λ��ָ��λ��*/

    printf("weak the write thread , make the pipe writable\n");
//    pthread_cond_signal(&wflag);

    printf("----release the lock\n");
//    pthread_mutex_unlock(&lock);

    printf("Secceed (pipe---->memory)output data from the pipe into memory *ca\n");
    return m;
}
/*�̵߳��ã���Դ�ļ���д�ܵ�*/
void *pwrite1121(void *a)//��Դ�ļ�a����д��ܵ���
{
    printf("(file---->pipe)input data from the original file into pipe\n");
    char abuf1[BSIZE];
    struct arg_set *args=(struct arg_set *)a;/*��Ҫ����������ʱ���ýṹ�崫*/
    int fdr;
    int n_r;/*�ܵ��ļ�д���ַ���*/
    if((fdr=open(args->fname,O_RDONLY))!=-1)
    {
        while((n_r=read(fdr,abuf1,BSIZE))>0)/*���ļ���д�ܵ�*/
        {
            printf("(file---->memory)input data in original file into memory *ca\n");
            printf("Secceed (file---->memory)input data in original file into memory *ca\n");
            //printf("(memory---->pipe)input data in memory *ca into pipe\n");
            write_simulate1121(args->f,abuf1,n_r);
            //printf("Secceed (memory---->pipe)input\n");
        }
        pipecb1121[file[u_ofile1121[args->f]].f_inode].p_count--;/*�ļ��Ѷ��꣬�رչܵ�д��*/
    }
    else
    {
        perror(args->fname);/*��Դ�ļ����ܲ��ɹ�*/
        return NULL;
    }
    printf("Secceed (file---->pipe)input data from the original file into pipe\n");
    return NULL;
}
/*�̵߳��ã�дĿ���ļ������ܵ�*/
void *pread1121(void *a)//��ȡ�ܵ�������������д���½��ļ���
{
    printf("(pipe---->file)output data from the pipe into new file\n");
    char abuf2[BSIZE];/*������*/
    struct arg_set *args=(struct arg_set *)a;/*��Ҫ����������ʱ���ýṹ�崫*/
    int fdw;
    int n_w;/*�ܵ��ļ������ַ���*/
    if((fdw=open(args->fname,O_CREAT|O_RDWR,0777))!=-1)
    {
        while((n_w=read_simulate1121(args->f,abuf2,BSIZE))>0)/*���ܵ���д�ļ�*/
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
        perror(args->fname);/*��Ŀ���ļ����ܳ���*/
        return NULL;
    }
    printf("Secceed (pipe---->file)output data from the pipe into new file\n");
    return NULL;
}

/*������*/
int main(int argc,char *argv[])
{
    int x;
    u_ofile_init1121();
    while((x=pipe_simulate1121(fd))==-1);/*�����ܵ���������ռ�*/
    if(x==-2)
        return -1;
    pthread_t t;//thread ID
    struct arg_set args[2];/*�ýṹ�崫д�߳���Ҫ�Ĳ���:�ļ���,�ܵ��ļ���д��*/
    args[0].fname=argv[1];/*Դ�ļ���*/
    args[0].f=fd[1];/*�ܵ��ļ�д��*/
    args[1].fname=argv[2];/*Ŀ���ļ���*/
    args[1].f=fd[0];/*�ܵ��ļ�����*/
//    pthread_create(&t,NULL,pwrite1121,(void *)&args[0]);/*�������߳�,д�ܵ�*/
    pread1121((void *)&args[1]);/*���̵߳���,���ܵ�*/
//    pthread_join(t,NULL);/*�ȴ�д�߳̽���*/
    close_simulate1121(fd);
    printf("\nnum of read_simulate1121 = %d\n",numread_simulate1121);
    printf("num of write_simulate1121 = %d\n",numwrite_simulate1121);
    return 0;
}

