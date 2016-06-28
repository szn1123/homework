
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char letter;  //字符
	int weight;  //权值
	int parent,lchild,rchild;  //左右孩子及双亲指针
}HTNode;
typedef struct{
	char letter;
	int bit[10];
	int end;
}HCodeType;

void Initialization(HTNode HuffmanTree[100],int n);
void Encoding(HCodeType HCode[50],HTNode HTree[100],int n);
void Decoding(char code[50],HCodeType HuffCode[50],int l,int m);
void CreatNode(char String[50],HCodeType HCode[50],int l,int m);

int main(){
	char s,code[100];
	int n,l;
	HTNode HuffmanTree[100];
	HCodeType HuffCode[50];
    while(1){
		printf("I：初始化；E：哈夫曼编码；N：将正文转成01代码；D：译码；\n请选择：");
		scanf("%c",&s);
		switch (s) {
		case 'I':
			FILE *fp;
			int i;
			if((fp=fopen("d:\\quanzhi.txt","r"))==NULL)
{
				printf("cannot open file!\n");
				exit(0);
			}
			fscanf(fp,"%d",&n);
			getc(fp);
			for(i=1;i<=n;i++)
			{
				fread(&HuffmanTree[i].letter,sizeof(char),1,fp);
			}
			for(i=1;i<=n;i++){
				fscanf(fp,"%d",&HuffmanTree[i].weight);
			}
		    fclose(fp);
			Initialization(HuffmanTree,n);
			printf("初始化成功!\n");
			break;
		case 'E':
			Encoding(HuffCode,HuffmanTree,n);
			break;

		case 'D':
			char filename[20];
			FILE *fp1;
			printf("请输入0，1代码的文件名：");
			getchar();
			gets(filename);
            if((fp1=fopen(filename,"r"))==NULL){
				printf("cannot open file!\n");
				exit(0);
			}
			fscanf(fp1,"%s",code);
			fclose(fp1);
			l=strlen(code);
			Decoding(code,HuffCode,l,n);
			break;
		case 'N':
			char filename1[20],code1[50];
			FILE *fp2;
			printf("请输入正文的文件名:");
			getchar();
			gets(filename1);
			if((fp2=fopen(filename1,"r"))==NULL){
				printf("cannot open file!\n");
				exit(0);
			}
			fgets(code1,50,fp2);
			fclose(fp2);
			l=strlen(code1);
			puts(code1);
			CreatNode(code1,HuffCode,l,n);
			break;
		default:;
		}
		getchar();
	}

}

void Initialization(HTNode HTree[100],int n)
{
	int m1,m2,x1,x2;
	int i,j;
	for(i=1;i<2*n;i++)
	{
		HTree[i].parent=-1;
        HTree[i].lchild=-1;
		HTree[i].rchild=-1;
	}
	for(i=n+1;i<2*n;i++)
		HTree[i].weight=-1;
	for(i=1;i<n;i++)
	{
		m1=m2=1000;
		x1=x2=1;
		for(j=1;j<n+i;j++)
		{
			if(HTree[j].weight<m1 && HTree[j].parent==-1)
			{
				m2=m1; x2=x1;
				m1=HTree[j].weight; x1=j;
			}
			else if(HTree[j].weight<m2 && HTree[j].parent==-1)
			{
				m2=HTree[j].weight;
				x2=j;
			}
		}
		HTree[x1].parent=n+i;          HTree[x2].parent=n+i;
		HTree[n+i].weight=HTree[x1].weight+HTree[x2].weight;
		HTree[n+i].lchild=x1;          HTree[n+i].rchild=x2;
	}
	for(i=1;i<2*n;i++)
	{
		printf("%d\tweight: %d\tlchild: %d\trchild: %d\tparent: %d\t",i,HTree[i].weight,HTree[i].lchild,HTree[i].rchild,HTree[i].parent);
		printf("\n");
	}
}

void Encoding(HCodeType HCode[50],HTNode HTree[100],int n)
{
	int i,j,c,p,s;
	HCodeType cd;
	for(i=1;i<n+1;i++)
	{
	    c=i;  cd.end=0;  s=0;
		p=HTree[c].parent;
		while(p!=-1)
		{
			if(HTree[p].lchild==c) cd.bit[cd.end]=0;
			else cd.bit[cd.end]=1;
			cd.end++; c=p;
			p=HTree[c].parent;
		}
		for(j=cd.end-1;j>=0;j--)
		{
			HCode[i].letter=HTree[i].letter;
			HCode[i].bit[s++]=cd.bit[j];
			HCode[i].end=cd.end;
		}
	}
	for(i=1;i<n+1;i++)
	{
		putchar(HCode[i].letter);
		printf("\t");
		for(j=0;j<HCode[i].end;j++)
	        printf("%ld",HCode[i].bit[j]);
		printf("\n");
	}
	printf("编码成功！\n");
}

void CreatNode(char String[50],HCodeType HCode[50],int l,int m)
{
	int i,j,a;
	for(i=0;i<l;i++)
	{
		for(j=1;j<m+1;j++)
			if(String[i]==HCode[j].letter)
			{
				for(a=0;a<HCode[j].end;a++)
					printf("%ld",HCode[j].bit[a]);
			}
	}
	printf("\n");
}

void Decoding(char Code[50],HCodeType HCode[50],int n,int m)
{
	int i,j,b,start;
	for(i=0;i<n;i++)
	{
		b=i;
		for(j=1;j<m+1;j++ )
		{
			start=0;
			while((Code[i]-'0')==HCode[j].bit[start])
			{
				i++;
				start++;
			}
			if(start==(HCode[j].end)){
				putchar(HCode[j].letter);
		        i--;
				break;
			}
            else if(start!=(HCode[j].end) && start!=0)
				i=b;
		}
		if(j==m+1){
			printf("\n您输入的数字有误，请重新输入\n");
			break;}
	}
	printf("\n");
	return 0;
}
