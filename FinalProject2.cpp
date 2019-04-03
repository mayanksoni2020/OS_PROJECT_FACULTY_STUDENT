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

	printf("\t\nHello Sudesh Today You have %d process to process    \n",stuc+facc);
	printf("\t\nWith %d are from student and %d from faculty         \n",stuc,facc);
	printf("\t Your new process time for rest Process are  %d\n",per);
	//sum=0;
	
	if(facc>0 && tim<120)
	{
	for(i=0;i<facc/2;i++)
	{
		swap(bf[i],bf[facc-i-1]);
		swap(rf[i],rf[facc-i-1]);
		swap(wtf[i],wtf[facc-i-1]);
	}
	for(i=0;i<facc;i++)
	{
		wtf[i]=ti(wtf[i]);
	}
	int x;
	i=0;
	m:
	x=tim;
	for(int i=0;i<facc;i++)
	{
		x+=bf[i];
	}
	if(x>120)
	{
		facc--;
		printf("F[%d] time exceed\n",facc+1);
		goto m;
	}
	
	int bff[facc],rff[facc],wtff[facc];
	for(int j=0;j<facc;j++)
	{
		bff[j]=bf[j];
		rff[j]=rf[j];
		wtff[j]=wtf[j];
	}
	
	int k=facc,e;
	tot(k);
	for(tim=0,e=0;facc!=0;)
	{
		if(bff[e]<=per && bff[e]>0)
		{
			
			tim+=bff[e];
			bff[e]=0;
			flag=1;
		}
		else if(bff[e]>0)
		{
			bff[e]-=per;
			tim+=per;
		}
		if(bff[e]==0 && flag==1)
		{
			facc--;
			printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
			printf("F[%d]\t|\t%d\t|\t%d\n",e+1,tim+wtff[e],tim-rff[e]+wtff[e]);
			waitf +=tim-rff[e]+wtff[e];
			turnf +=tim+wtff[e];
			flag=0;
		}
		if(e==k-1)
		e=0;
		else
		e++;
	}
}
	int po;
	//for new faculty process.
	q:if(tim<120)
	{
	int cutt = cut(tim);
	printf("\nCURRENT TIME is %d\t",cutt);
	printf("\nAny Faculty waitng or Student waiting  press 1 for faculty or press 2 for student  \t");
	printf("\n If No process Waiting the press 3 \t");
	printf("\n To Quit press 4");
	scanf("%d",&po);
	if(po==1)
	{
		printf("\nHow many are waiting \t");
		int op;
		scanf("%d",&op);
		int b[op],a[op];
		for(int i=0;i<op;i++)
		{
			printf("\n Enter the ARRIVAL time and BUST time %d  ",i+1);
			scanf("%d %d",&a[i],&b[i]);
			t:if(a[i]>cutt || a[i]>1200)
			{
				printf("ERROR!!! Enter the Time again\n ");
				printf("Enter the corect arrival time \n");
				scanf("%d",&a[i]);
				goto t;
			}
			a[i]=ti1(a[i]);
		}
		per=(int)(120-tim)/(stuc+op);
		printf("\n Your new process time for rest Process are %d",per);
		m3:
	int x=tim;
	for(int i=0;i<op;i++)
	{
		x+=b[i];
	}
	if(x>120)
	{
		op--;
		printf("F[%d] time exceed\n",op+1);
		goto m3;
	}
	int bff[op],rff[op],wtff[op];
	for(int j=0;j<op;j++)
	{
		bff[j]=b[j];
		rff[j]=b[j];
		wtff[j]=a[j];
	}
	
	int k=op,u;
	tot(k);
	for(u=0;op!=0;)
	{
		if(bff[u]<=per && bff[u]>0)
		{
			
			tim+=bff[u];
			bff[u]=0;
			flag=1;
		}
		else if(bff[u]>0)
		{
			bff[u]-=per;
			tim+=per;
		}
		if(bff[u]==0 && flag==1)
		{
			op--;
			printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
			printf("F[%d]\t|\t%d\t|\t%d\n",u+1,tim-wtff[u],tim-rff[u]-wtff[u]);
			waitff +=tim-rff[u]-wtff[u];
			turnff +=tim-wtff[u];
			flag=0;
		}
		if(u==k-1)
		u=0;
		else
		u++;
	}
	}
	else if(po==3)
	{
		if(stuc==0)
		{
		tim+=5;
		goto final;
		}
		else
		goto w;
	}
	else if(po==4)
	{
	printf("\n Average Waiting Time is %f       ",(float)(waitf+waits+waitff+waitfs)/totalp);
	printf("\n Average processing time is %f    ",(float)tim/totalp);
	int kj;
	cin>>kj;
	exit(0);
	}
	else if(po==2)
	{
	int cutt = cut(tim);
	printf("Current Time is %d\n",cutt);
	printf("\nAny Studnt waitng  press 1 \t");
	if(stuc==0)
	{
	int po;
	scanf("%d",&po);
	if(po==1)
	{
		printf("\nHow many are waiting \t");
		int op;
		scanf("%d",&op);
		int b[op],a[op];
		for(int i=0;i<op;i++)
		{
			printf("\n Enter the ARRIVAL time and BUST time %d  ",i+1);
			scanf("%d %d",&a[i],&b[i]);
			t1:if(a[i]>cutt || a[i]>=1200)
			{
				printf("ERROR enter the Time again\n ");
				printf("enter the corect arrival time \n");
				scanf("%d",&a[i]);
				goto t1;
			}
			a[i]=ti1(a[i]);
		}
		per=(int)(120-tim)/(op);
		printf("\n Your new process time for rest Process are %d",per);
		m4:
	int x=tim;
	for(int i=0;i<op;i++)
	{
		x+=b[i];
	}
	if(x>120)
	{
		op--;
		printf("S[%d] time exceed\n",op+1);
		goto m4;
	}
	int bff[op],rff[op],wtff[op];
	for(int j=0;j<op;j++)
	{
		bff[j]=b[j];
		rff[j]=b[j];
		wtff[j]=a[j];
	}

	int k=op,l;
	tot(k);
	for(l=0;op!=0;)
	{
		if(bff[l]<=per && bff[l]>0)
		{
			
			tim+=bff[l];
			bff[l]=0;
			flag=1;
		}
		else if(bff[l]>0)
		{
			bff[l]-=per;
			tim+=per;
		}
		if(bff[l]==0 && flag==1)
		{
			op--;
			printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
			printf("F[%d]\t|\t%d\t|\t%d\n",l+1,tim-wtff[l],tim-rff[l]-wtff[l]);
			waitfs +=tim-rff[l]-wtff[l];
			turnss +=tim-wtff[l];
			flag=0;
		}
		if(l==k-1)
		l=0;
		else
		l++;
	}
	}
	}
	else
	{
	printf("\n \t\tWAIT \n");
	goto w;
	}
	}
	else
	{
		goto w;
	}
	}
	else
	{
		goto final;
	}
	
	goto q;
	w:if(stuc>0 && tim<120)
	{
		for(i=0;i<stuc/2;i++)
	{
		swap(bs[i],bs[stuc-i-1]);
		swap(rs[i],rs[stuc-i-1]);
		swap(wts[i],wts[stuc-i-1]);
	}
	for(i=0;i<stuc;i++)
	{
		wts[i]=ti(wts[i]);
	}
	int x;
	i=0;
	m1:
	x=tim;
	for(int i=0;i<stuc;i++)
	{
		x+=bs[i];
	}
	if(x>120)
	{
		stuc--;
		printf("\nS[%d]time exceed\n",stuc+1);
		goto m1;
	}
	int bff[stuc],rff[stuc],wtff[stuc];
	for(int j=0;j<stuc;j++)
	{
		bff[j]=bs[j];
		rff[j]=rs[j];
		wtff[j]=wts[j];
	}
	
	int k=stuc,v;
	tot(k);
	for(v=0;stuc!=0;)
	{
		if(bff[v]<=per && bff[v]>0)
		{
			
			tim+=bff[v];
			bff[v]=0;
			flag=1;
		}
		else if(bff[v]>0)
		{
			bff[v]-=per;
			tim+=per;
		}
		if(bff[v]==0 && flag==1)
		{
			stuc--;
			printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
			printf("S[%d]\t|\t%d\t|\t%d\n",v+1,tim+wtff[v],tim-rff[v]+wtff[v]);
			waits +=tim-rff[v]+wtff[v];
			turns +=tim+wtff[v];
			flag=0;
		}
		if(v==k-1)
		v=0;
		else
		v++;
	}
	}
	goto q;
	final:
	if(tim>=120)
	{
	printf("\n Average Waiting Time is %f     ",(float)(waitf+waits+waitff+waitfs)/totalp);
	printf("\n Average processing time is %f  ",(float)tim/totalp);
	exit(0);
	}
	else
	{
		goto q;
	}
}
