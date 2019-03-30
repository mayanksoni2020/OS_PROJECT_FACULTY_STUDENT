#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int waitf=0,turnf=0;
int waitff=0,turnff=0;
int waitfs=0,turnss=0;
int waits=0,turns=0;
int tim=0,flag;
int kf=0,ks=0;
int totalp;
void tot(int a)
{
	totalp=totalp+a;
}


int ti(int a)
{
	int i=1000-a-40;
	i=((i/100)*60)+(i%100);
	if(i<0)
	return 0;
	else
	return i;
}

int ti1(int b)
{
	b=b%1000;
	return (((b/100)*60)+b%100);
}

int cut( int a)
{
	if(a-60<0)
	return 1000+a;
	else
	{
		return 1000+100+a-60;	
	}	
}

struct st
{
	int bust;
	int ariv;
	struct st *next;
}*start,*rep;
struct ft
{
	int bust;
	int ariv;
	struct ft *next;
}*start1,*rep1;

ft* fc(int b,int a)
{
	struct ft *temp;
	temp= new struct ft;
	temp->bust=b;
	temp->ariv=a;
	temp->next=NULL;
	return temp;
}

st* sc(int b,int a)
{
	struct st *temp;
	temp= new struct st;
	temp->bust=b;
	temp->ariv=a;
	temp->next=NULL;
	return temp;
}

void inStudent(int b,int a)
{
	struct st *node1,*p;
	node1=sc(b,a);
	if(start == NULL)
	{
		start =node1;
		start->next=NULL;
	}
	else
	{
		p=start;
		start = node1;
		start->next=p;
	}
}
void inFaculty(int b,int a)
{
	struct ft *node1,*p;
	node1=fc(b,a);
	if(start1 == NULL)
	{
		start1 =node1;
		start1->next=NULL;
	}
	else
	{
		p=start1;
		start1 = node1;
		start1->next=p;
	}
}

int main()
{
	printf("\t\tWelcome to process menagement\n");
	int p,facc=0,stuc=0;
	printf("Any process Before 10:00 AM if yes press 1 else press 0   ");
	scanf("%d",&p);
	while(p!=0)
	{
		system("cls");
		printf("\n\n1.student and 2. Faculty\n Enter your respone:- ");
		int q,b,a;
		scanf("%d",&q);
		if(q==1)
		{
			printf("Enter the bust time: ");
			scanf("%d",&b);
			printf("Enter Arival time: ");
			scanf("%d",&a);
			if(a>=1000)
			{
			printf("\nError enter the arival time again   ");
			scanf("%d",&a);
			}
			inStudent(b,a);
			stuc++;
		}
		else if(q==2)
		{
			printf("\nEnter the bust tim: ");
			scanf("%d",&b);
			printf("\nEnter Arival time: ");
			scanf("%d",&a);
			if(a>=1000)
			{
			printf("\nError enter the arival time again   ");
			scanf("%d",&a);
			}
			inFaculty(b,a);
			facc++;
		}
		else
		printf("choose wisely\n");
		printf("\nPRESS 1 TO CONTINUE else PRESS 0\t");
		scanf("%d",&p);
	}
	
	if(p==0)
	{
		facc++;
		stuc++;
	}
	int i=0,j=0;
	int bs[stuc],as[stuc],rs[stuc],wts[stuc];
	int bf[facc],af[facc],rf[facc],wtf[facc];
	if(p==0)
	{
		facc--;
		stuc--;
	}
	
	if(stuc)
	{
	while(start!=NULL)
	{
		bs[i]=start->bust;
		wts[i]=start->ariv;
	//	wts[i]=ti(wts[i]);
		rs[i]=bs[i];
		start=start->next;
		i++;
	}
	}
	
	if(facc)
	{
	while(start1!=NULL)
	{
		bf[j]=start1->bust;
		wtf[j]=start1->ariv;
		//wtf[j]=ti(wtf[i]);
		rf[j]=bf[j];
		start1=start1->next;
		j++;
	}}
	int per;
	if(stuc==0 && facc==0)
	per=0;
	else
	per=int(120/(stuc+facc));
