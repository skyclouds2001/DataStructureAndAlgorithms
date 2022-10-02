#include<iostream> 
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include <algorithm>
using namespace std;
typedef struct{
	char name[32];
	short grade;
	bool sex;			//0 male	1 female
	int id;
}STU;
STU stu[100005];
int name[100005],grade[100005];
int fsex(bool flag)
{
	if(flag)	return 2;
	else	return 1;
}
int main()
{
	int N,M;
	scanf("%d",&N);
	for(int i=1,t;i<=N;i++)
	{
		scanf("%s %hd %d %d",&(stu[i].name),&(stu[i].grade),&t,&(stu[i].id));
		if(t==1)	stu[i].sex=false;
		else if(t==2)	stu[i].sex=true;
		name[i]=i;	grade[i]=i;
	}
	//fname(N);
	//fgrade(N);
	scanf("%d",&M);
	int T,gradet;
	char namet[32]={'\0'};
	for(int k=1;k<=M;k++)
	{
		scanf("%d",&T);
		if(T==1)
		{
			scanf("%s",namet);
			int i=1,j=N,mid;
			while(i<=j)
			{
				mid=(i+j)/2;
				if(strcmp(stu[name[mid]].name,namet)==0)
					break;
				else if(strcmp(stu[name[mid]].name,namet)>0)
					j=mid-1;
				else
					i=mid+1;
			}
			cout<<stu[name[mid]].grade<<' '<<stu[name[mid]].id<<' '<<fsex(stu[name[mid]].sex)<<endl;
		}
		else if(T==2)
		{
			scanf("%d",&gradet);
			int i=1,j=N,mid;
			while(i<=j)
			{
				mid=(i+j)/2;
				if(stu[grade[mid]].grade>=gradet)
					j=mid-1;
				else
					i=mid+1;
			}
			if(stu[grade[j]].grade==gradet)
			{
				int pre=j,end=j;
				while(stu[grade[pre]].grade==gradet)	pre--;
				while(stu[grade[end]].grade==gradet)	end++;
				for(int i=pre+1;i<=end-1;i++)
				{
					printf("%s\n",stu[grade[i]].name);
				}
			}
		}
	}
	return 0;
}
