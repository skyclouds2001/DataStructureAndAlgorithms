#include<stdio.h>
typedef struct{
	char name[20];
	short num[5];
	int time[5];
}TEAM;
int main()
{
	int n=0,k=0;
	scanf("%d",&n);
	TEAM team[n];
	int i=0,j=0;
	for(i=0;i<n;i++)
		scanf("%s %d %d %d %d %d %d %d %d",team[i].name,&team[i].num[1]\
		,&team[i].time[1],&team[i].num[2],&team[i].time[2],&team[i].num[3]\
		,&team[i].time[3],&team[i].num[4],&team[i].time[4]);
	for(i=0;i<n;i++)
	{
		team[i].num[0]=0;	team[i].time[0]=0;
		for(j=1;j<=4;j++)
		{
			if(team[i].time[j])
			{
				team[i].num[0]++;
				team[i].time[0]+=(team[i].time[j]+(team[i].num[j]-1)*20);
			}
		}
		if(team[i].num[0]>team[k].num[0]||team[i].num[0]==team[k].num[0]\
		&&team[i].time[0]<team[k].time[0])	k=i;	
	}
	printf("%s %d %d",team[k].name,team[k].num[0],team[k].time[0]);
	return 0;
}
