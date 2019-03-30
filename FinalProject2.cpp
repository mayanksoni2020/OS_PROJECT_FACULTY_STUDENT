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

