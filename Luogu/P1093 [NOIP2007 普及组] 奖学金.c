#include<stdio.h>
struct student{
	short id;
	short C;
	short M;
	short E;
	short all;
};
int main()
{
	short n=0;
	scanf("%hd",&n);
	struct student stu[n+1];
	short i=0,j=0;
	for(i=0;i<n;i++)
	{
		scanf("%hd%hd%hd",&((stu+i)->C),&((stu+i)->M),&((stu+i)->E));
		(stu+i)->all=(stu+i)->C+(stu+i)->M+(stu+i)->E;
		(stu+i)->id=i+1;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((stu+j)->all<(stu+j+1)->all||(stu+j)->all==(stu+j+1)->all&&(stu+j)->C<(stu+j+1)->C||\
			(stu+j)->all==(stu+j+1)->all&&(stu+j)->C==(stu+j+1)->C&&(stu+j)->id>(stu+j+1)->id)
			{
				stu[n]=stu[j];  stu[j]=stu[j+1];  stu[j+1]=stu[n];
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%hd %hd\n",(stu+i)->id,(stu+i)->all);
	}
	return 0;
 } 
