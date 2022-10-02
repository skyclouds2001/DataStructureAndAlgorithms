#include<stdio.h>
struct student{
	char name[50];
	short age;
	short score;
};
int main()
{
	short n=0;
	scanf("%hd",&n);
	struct student stu[n];
	short i=0;
	double t=0;
	for(i=0;i<n;i++)  scanf("%s %hd %hd",stu[i].name,&stu[i].age,&stu[i].score);
	for(i=0;i<n;i++)
	{
		stu[i].age++;
		t=((1.2)*(double)(stu[i].score));
		if(t<=600)  stu[i].score=(short)t;
		else  stu[i].score=600;
	}
	for(i=0;i<n;i++)  printf("%s %hd %hd\n",stu[i].name,stu[i].age,stu[i].score);
	return 0;
}
