#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int p;
	int l;
	int r;
}TREE;
void make(TREE arr[], int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    make(arr, begin, mid);
    make(arr, mid + 1, end);
}
int main()
{
	short n=0;
	scanf("%hd",&n);
	short l=0,r=0;
	
	return 0;
}
