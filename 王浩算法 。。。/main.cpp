#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_L 5
int i=0;
int stepcount=1;

enum type{
	and,or,detrusion,equal,level,variable
};

struct node{
	char *s;
	type kind;
	int polar;
	node *next;
	node *child;
	int start;
};


struct step{
	step *child;
	step *brother;
	node *lhead;
	node *rhead;
	int count;
	char name[30];
};



int inite(char *s,node *head){
	int len=strlen(s);
	int j=0,polar=1;
	node *current=NULL;
	node *last=NULL;

	if(s==NULL)return 0;

	last=head;

	while(i<len){
		if(s[i]=='|'){
			if(!(s[i+1]<='Z'&&s[i+1]>='A'||s[i+1]<='z'&&s[i+1]>='a')&&s[i+1]!='1'&&s[i+1]!='0'&&s[i+1]!='('&&s[i+1]!='!'||i==0)return 0;
			current=(node*)malloc(sizeof(node));
			current->kind=or;
			current->s=NULL;
			current->next=NULL;
			current->child=NULL;
			current->polar=polar;
			current->start=0;

			if(last->kind==level&&last->child==NULL){
				last->child=current;
			}
			else{
				last->next=current;
			}
			last=current;
			i++;
		}
		else if(s[i]=='&'){
			if(!(s[i+1]<='Z'&&s[i+1]>='A'||s[i+1]<='z'&&s[i+1]>='a')&&s[i+1]!='1'&&s[i+1]!='0'&&s[i+1]!='('&&s[i+1]!='!'||i==0)return 0;
				current=(node*)malloc(sizeof(node));
				current->kind=and;
				current->s=NULL;
				current->next=NULL;
				current->child=NULL;
				current->polar=polar;
				current->start=0;

				if(last->kind==level&&last->child==NULL){
					last->child=current;
				}
				else{
					last->next=current;
				}
				last=current;
				i++;
		}
		else if(s[i]=='!'){
			if(!(s[i+1]<='Z'&&s[i+1]>='A'||s[i+1]<='z'&&s[i+1]>='a')&&s[i+1]!='1'&&s[i+1]!='0'&&s[i+1]!='('&&s[i+1]!='!')return 0;
				polar=1-polar;
				i++;
		}
		else if(s[i]=='-'){
			if(s[i+1]!='>'||(s[i+2]!='!'&&s[i+2]!='('&&!(s[i+2]<='Z'&&s[i+2]>='A'||s[i+2]<='z'&&s[i+2]>='a'))||i==0)return 0;
				current=(node*)malloc(sizeof(node));
				current->kind=detrusion;
				current->s=NULL;
				current->next=NULL;
				current->child=NULL;
				current->polar=polar;
				current->start=0;

				if(last->kind==level&&last->child==NULL){
					last->child=current;
				}
				else{
					last->next=current;
				}
				last=current;
				i=i+2;
		}
		else if(s[i]=='<'){
			if((s[i+1]!='-'||s[i+2]!='>')||(s[i+3]!='!'&&s[i+3]!='('&&!(s[i+3]<='Z'&&s[i+3]>='A'||s[i+3]<='z'&&s[i+3]>='a')||i==0)&&s[i+3]!='1'&&s[i+3]!='0')return 0;
				current=(node*)malloc(sizeof(node));
				current->kind=equal;
				current->s=NULL;
				current->next=NULL;
				current->child=NULL;
				current->polar=polar;
				current->start=0;

				if(last->kind==level&&last->child==NULL){
					last->child=current;
				}
				else{
					last->next=current;
				}
				last=current;
				i=i+3;
		}
		else if(s[i]<='Z'&&s[i]>='A'||s[i]<='z'&&s[i]>='a'){
				current=(node*)malloc(sizeof(node));
				current->kind=variable;
				current->next=NULL;
				current->child=NULL;
				current->polar=polar;
				current->start=0;
				current->s=(char*)malloc(MAX_L*sizeof(char));

				if(last->kind==level&&last->child==NULL){
					last->child=current;
				}
				else{
					last->next=current;
				}
				last=current;

				j=0;
			while((s[i]<='Z'&&s[i]>='A'||s[i]<='z'&&s[i]>='a')||(s[i]<='9'&&s[i]>='0')){
				(current->s)[j]=s[i];
				i++;
				j++;
			}
			if(s[i]!='|'&&s[i]!='&'&&s[i]!='-'&&s[i]!='<'&&s[i]!='\0'&&s[i]!=')')return 0;
			(current->s)[j]='\0';
			polar=1;

		}
		else if(s[i]=='1'||s[i]=='0'){
			if(s[i+1]!='<'&&s[i+1]!='-'&&s[i+1]!='&'&&s[i+1]!='|'&&s[i+1]!=')'&&s[i+1]!='\0')return 0;
				current=(node*)malloc(sizeof(node));
				current->kind=equal;

				current->s=(char*)malloc(2*sizeof(char));
				(current->s)[0]=s[i];
				(current->s)[1]='\0';

				current->next=NULL;
				current->child=NULL;
				current->polar=polar;
				current->start=0;

				if(last->kind==level&&last->child==NULL){
					last->child=current;
				}
				else{
					last->next=current;
				}
				last=current;
				i++;
		}
		else if(s[i]=='('){
			if(!(s[i+1]<='Z'&&s[i+1]>='A'||s[i+1]<='z'&&s[i+1]>='a')&&s[i+1]!='1'&&s[i+1]!='0'&&s[i+1]!='!'&&s[i+1]!='(')return 0;
				current=(node*)malloc(sizeof(node));
				current->kind=level;
				current->s=NULL;
				current->next=NULL;
				current->child=NULL;
				current->polar=polar;
				current->start=0;

				if(last->kind==level&&last->child==NULL){
					last->child=current;
				}
				else{
					last->next=current;
				}
				last=current;
				i++;
				polar=1;
				if(!inite(s,last))return 0;

		}
		else if(s[i]==')'){
			if(s[i+1]!='P'&&s[i+1]!='1'&&s[i+1]!='0'&&s[i+1]!='-'&&s[i+1]!='<'&&s[i+1]!='&'&&s[i+1]!='|'&&s[i+1]!='\0'&&s[i+1]!=')')return 0;
				i++;
				return 1;
		}
		else return 0;
	}
	return 1;
}

node* clone(node *parent){
	node *son=NULL;

	if(parent==NULL)return NULL;

	son=(node*)malloc(sizeof(node));
	son->kind=parent->kind;
	son->polar=parent->polar;
	son->s=parent->s;
	son->start=parent->start;
	if(parent->next!=NULL){
		son->next=clone(parent->next);
	}
	else{
		son->next=NULL;
	}
	if(parent->child!=NULL){
		son->child=clone(parent->child);
	}
	else{
		son->child=NULL;
	}
	return son;
}

void remove(node *head){
	node *current=NULL;
	current=head;
	if(current==NULL)return;
	if(current->kind==level&&current->child->kind==variable&&current->child->next==NULL){
		current->polar=(current->child->polar==current->polar);
		current->child->polar=1;
	}
	while(current->kind==level&&current->child->kind==level&&current->child->next==NULL){
		current->polar=(current->polar==current->child->polar);
		current->child=current->child->child;
	}
	if(current->next!=NULL)remove(current->next);
	if(current->child!=NULL)remove(current->child);
}

void restruct(node* head){
	node *current=NULL;
	node *last=NULL;
	node *newone=NULL,*newtwo=NULL,*newthree=NULL,*newfour=NULL,*newcurrent=NULL;
	int order=1;

	while(order<=4){
		last=head;
		current=last->child;
		while(current!=NULL){
			if((current->kind==variable||current->kind==level)&&order==1){
				if(current->next!=NULL&&current->next->kind==and){
					newone=(node*)malloc(sizeof(node));
					newone->child=NULL;
					newone->kind=level;
					newone->next=NULL;
					newone->polar=0;
					newone->s=NULL;
					newone->start=0;
					if(last->kind==level){
						last->child=newone;
					}
					else{
						last->next=newone;
					}

					newone->next=current->next->next->next;
					newone->child=current;
					current->next->next->polar=1-current->next->next->polar;
					current->next->kind=detrusion;
					current->next->next->next=NULL;

					current=newone;
				}
				else{
					last=current;
					current=current->next;
				}
			}
			else if((current->kind==variable||current->kind==level)&&order==2){
				if(current->next!=NULL&&current->next->kind==or){
				    newone=(node*)malloc(sizeof(node));
					newone->child=NULL;
					newone->kind=level;
					newone->next=NULL;
					newone->polar=1;
					newone->s=NULL;
					newone->start=0;
					if(last->kind==level){
						last->child=newone;
					}
					else{
						last->next=newone;
					}

					newone->next=current->next->next->next;
					newone->child=current;
					current->polar=1-current->polar;
					current->next->kind=detrusion;
					current->next->next->next=NULL;

					current=newone;
				}
				else{
					last=current;
					current=current->next;
				}
			}
			else if((current->kind==variable||current->kind==level)&&order==3){
				if(current->next!=NULL&&current->next->kind==equal){
					newone=(node*)malloc(sizeof(node));
					newone->child=NULL;
					newone->kind=level;
					newone->next=NULL;
					newone->polar=0;
					newone->s=NULL;
					newone->start=0;

					newtwo=(node*)malloc(sizeof(node));
					newtwo->child=NULL;
					newtwo->kind=level;
					newtwo->next=NULL;
					newtwo->polar=1;
					newtwo->s=NULL;
					newtwo->start=0;

					newthree=(node*)malloc(sizeof(node));
					newthree->child=NULL;
					newthree->kind=detrusion;
					newthree->next=NULL;
					newthree->polar=1;
					newthree->s=NULL;
					newthree->start=0;

					newfour=(node*)malloc(sizeof(node));
					newfour->child=NULL;
					newfour->kind=level;
					newfour->next=NULL;
					newfour->polar=0;
					newfour->s=NULL;
					newfour->start=0;

					if(last->kind==level){
						last->child=newone;
					}
					else{
						last->next=newone;
					}

					newone->next=current->next->next->next;
					newone->child=newtwo;

					current->next->kind=detrusion;
					newtwo->child=current;
					current->next->next->next=NULL;

					newtwo->next=newthree;
					newthree->next=newfour;
					newfour->next=NULL;

					newcurrent=clone(current);
					newcurrent->next->kind=detrusion;

					newfour->child=newcurrent->next->next;
					newcurrent->next->next->next=newcurrent->next;
					newcurrent->next->next=newcurrent;
					newcurrent->next=NULL;

					current=newone;
				}
				else{
					last=current;
					current=current->next;
				}
			}
			else if(current->kind==level&&order==4){
				restruct(current);
				last=current;
				current=current->next;
			}
			else{
				last=current;
				current=current->next;
			}
		}
		order++;
	}
}


void show(node *head){
	node *current=NULL;
	current=head;
	while(current!=NULL){
		if(current->kind==level){
			if(current->polar==0)printf("!");
			if(current->start!=1||(current->polar==0&&current->child->next!=NULL))printf("(");
			show(current->child);
			if(current->start!=1||(current->polar==0&&current->child->next!=NULL))printf(")");
			current=current->next;
			if(current!=NULL&&current->start==1)putchar(',');
		}
		else if(current->kind==and){
			printf("&");
			current=current->next;
		}
		else if(current->kind==or){
			printf("|");
			current=current->next;
		}
		else if(current->kind==detrusion){
			printf("->");
			current=current->next;
		}
		else if(current->kind==equal){
			printf("<->");
			current=current->next;
		}
		else if(current->kind==variable){
			if(current->polar==0)printf("!");
			printf("%s",current->s);
			current=current->next;
		}
	}
	return;
}

int searching(step *one){
	node *current=NULL;
	node *last=NULL;
	node *newlev=NULL;
	node *ncurrent=NULL;
	node *nlast=NULL;
	step *nextone=NULL;
	step *nexttwo=NULL;
	int key=0;
	int mark=0;
	int re1=1;
	int re2=1;

	nextone=(step*)malloc(sizeof(step));
	nextone->brother=NULL;
	nextone->child=NULL;
	nextone->lhead=NULL;
	nextone->rhead=clone(one->rhead);
	nextone->lhead=clone(one->lhead);
	strcpy(nextone->name,"");


	one->child=nextone;

	current=nextone->rhead;
	last=current;
	while(current!=NULL){
		if(current->polar==0){
			if(current==nextone->rhead)nextone->rhead=current->next;
			else last->next=current->next;

			current->next=NULL;
			remove(current);

			current->next=nextone->lhead;
			nextone->lhead=current;
			current->polar=1-current->polar;
			current->start=1;

			current=last->next;

			strcpy(one->name,"根据规则1");

			mark=1;
			key=1;
			break;
		}
		else if(current->child->next!=NULL&&current->child->next->kind==detrusion){
			nlast=current->child;
			ncurrent=current->child->next;
			while(ncurrent->next->next!=NULL&&ncurrent->next->next->kind==detrusion){
				nlast=ncurrent->next;
				ncurrent=ncurrent->next->next;
			}
			current->polar=1-current->polar;


			newlev=(node*)malloc(sizeof(node));
			newlev->child=ncurrent->next;
			newlev->kind=level;
			newlev->polar=1;
			newlev->next=NULL;
			newlev->start=1;
			nlast->next=NULL;

			remove(newlev);
			newlev->next=current->next;
			current->next=NULL;
			remove(current);
			current->next=newlev;

			strcpy(one->name,"根据规则4");

			mark=1;
			key=1;
			break;
		}
		else{
			last=current;
			current=current->next;
		}
	}
	current=nextone->lhead;
	last=current;
	while(current!=NULL&&key!=1){
		if(current->polar==0){
			if(current==nextone->lhead)nextone->lhead=current->next;
			else last->next=current->next;

			current->next=NULL;
			remove(current);

			current->next=nextone->rhead;
			nextone->rhead=current;
			current->polar=1-current->polar;
			current->start=1;

			current=last->next;

			strcpy(one->name,"根据规则2");

			mark=1;
			key=1;
			break;
		}
		else if(current->child->next!=NULL&&current->child->next->kind==detrusion){
			nexttwo=(step*)malloc(sizeof(step));
			nexttwo->brother=NULL;
			nexttwo->child=NULL;
			nexttwo->lhead=NULL;
			nexttwo->rhead=clone(nextone->rhead);
			nexttwo->lhead=clone(nextone->lhead);
			strcpy(nexttwo->name,"");

			nlast=current->child;
			ncurrent=current->child->next;
			while(ncurrent->next->next!=NULL&&ncurrent->next->next->kind==detrusion){
				nlast=ncurrent->next;
				ncurrent=ncurrent->next->next;
			}
			current->polar=1-current->polar;
			current->start=1;
			nlast->next=NULL;

			remove(current);

			current=nexttwo->lhead;
			last=current;
			while(current->child->next==NULL||current->child->next->kind!=detrusion){
				last=current;
				current=current->next;
			}
			nlast=current->child;
			ncurrent=current->child->next;
			while(ncurrent->next->next!=NULL&&ncurrent->next->next->kind==detrusion){
				nlast=ncurrent->next;
				ncurrent=ncurrent->next->next;
			}


			newlev=(node*)malloc(sizeof(node));
			newlev->child=ncurrent->next;
			newlev->kind=level;
			newlev->polar=1;
			newlev->next=NULL;
			newlev->start=1;
			nlast->next=NULL;

			if(current==nexttwo->lhead){
				newlev->next=current->next;
				nexttwo->lhead=newlev;
			}
			else{
				newlev->next=current->next;
				last->next=newlev;
			}
			remove(newlev);

			nextone->brother=nexttwo;

			strcpy(one->name,"根据规则3");

			mark=1;
			key=1;
			break;
		}
		else{
			last=current;
			current=current->next;
		}
	}
	if(mark==0){
		one->child=NULL;
		current=one->lhead;
		ncurrent=one->rhead;
		while(current!=NULL){
			ncurrent=one->rhead;
			while(ncurrent!=NULL){
				if(!strcmp(current->child->s,ncurrent->child->s))break;
				ncurrent=ncurrent->next;
			}
			if(ncurrent!=NULL)break;
			current=current->next;
		}
		if(current==NULL){
			return 0;
		}
		else{
			return 1;
		}
	}
	re1=searching(nextone);
	if(nextone->brother!=NULL)re2=searching(nextone->brother);
	if(re1&&re2){
		return 1;
	}
	else{
		return 0;
	}

}


void output(step *one){
	if(one->child!=NULL){
		output(one->child);
	}
	if(one->brother!=NULL){
		output(one->brother);
	}
	one->count=stepcount;
	stepcount++;
	printf("(%d)	",one->count);
	show(one->lhead);
	printf("=>");
	show(one->rhead);
	printf("		");
	if(one->child!=NULL&&one->child->brother==NULL){
		printf("由(%d)",one->child->count);
	}
	else if(one->child!=NULL&&one->child->brother!=NULL){
		printf("由(%d)(%d)",one->child->count,one->child->brother->count);
	}
	else{
		printf("公理");
	}
	puts(one->name);
	return;
}


void main(){
	char s[100];
	node head;
	step one;

	head.child=NULL;
	head.kind=level;
	head.next=NULL;
	head.polar=1;
	head.s=NULL;
	head.start=1;
	one.brother=NULL;
	one.child=NULL;
	one.lhead=NULL;
	one.rhead=&head;

	puts("王浩算法推理器");
	while(1){
		puts("请输入要证明的公式，变量符号可由大小写字母和数字组成:");
		scanf("%s",s);
	//	strcpy(s,"(a|(b2<->c3))->((a1->b2)->(a1->c3))");
		if(inite(s,&head)){
	//		show(&head);
			puts("\n化成蕴含式:");
			restruct(&head);
		//	show(&head);
		//	putchar('\n');
			remove(&head);
			show(&head);
			putchar('\n');
			if(searching(&one)){
				puts("推导结果为:");
				output(&one);
				break;
			}else {
				puts("无法推导出公式");
				break;
			}
		}
		else puts("输入的公式语法有错误");
		getchar();
	}
}
