#include<stdio.h>
#include<math.h>
int main()
{
	double point[3][2]={0};
	double len[4]={0};
	scanf("%lf%lf%lf%lf%lf%lf",point[0],point[0]+1,point[1],point[1]+1,point[2],point[2]+1);
	len[0]=sqrt(pow(point[0][0]-point[1][0],2)+pow(point[0][1]-point[1][1],2));
	len[1]=sqrt(pow(point[0][0]-point[2][0],2)+pow(point[0][1]-point[2][1],2));
	len[2]=sqrt(pow(point[2][0]-point[1][0],2)+pow(point[2][1]-point[1][1],2));
	len[3]=len[1]+len[0]+len[2];
	printf("%.2f",len[3]);
	return 0;
 } 
