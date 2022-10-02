#include<stdio.h>
#include<string.h>
typedef struct{
	char name[20];
	int y;
	int m;
	int d;
	int f;
}S;
int main()
{
	int n=0,i=0,j=0;
	scanf("%d",&n);
	S stu[n],t;
	for(i=0;i<n;i++)
	{
		memset(stu[i].name,'\0',20*sizeof(char));
		scanf("%s %d %d %d",stu[i].name,&(stu[i].y),&(stu[i].m),&(stu[i].d));
		stu[i].f=i;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(stu[j].y>stu[j+1].y||stu[j].y==stu[j+1].y&&stu[j].m>stu[j+1].m||\
			stu[j].y==stu[j+1].y&&stu[j].m==stu[j+1].m&&stu[j].d>stu[j+1].d||\
			stu[j].y==stu[j+1].y&&stu[j].m==stu[j+1].m&&stu[j].d==stu[j+1].d&&\
			stu[j].f<stu[j+1].f)
			{
				t=stu[j];	stu[j]=stu[j+1];	stu[j+1]=t;
			}
		}
	}
	for(i=0;i<n;i++)	printf("%s\n",stu[i].name);
	return 0;
}
