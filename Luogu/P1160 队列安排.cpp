#include<iostream>
#include<cstdio>
using namespace std;
int N,M;
class NODE{
	public:
		int num;
		NODE *pre,*next;
};
NODE *pos[100000+4],*head,*tail;
int main()
{
	scanf("%d",&N);
	pos[1]=new NODE;
	pos[1]->num=1;
	head=pos[1];
	tail=pos[1];
	for(int i=2,k,p;i<=N;++i)
	{
		scanf("%d%d",&k,&p);
		pos[i]=new NODE;
		pos[i]->num=i;
		switch(p)
		{
			case 0:
			{
				if(pos[k]==head)
				{
					pos[i]->pre=NULL;
					pos[i]->next=head;
					head=pos[i];
					pos[k]->pre=pos[i];
				}
				else
				{
					pos[i]->pre=pos[k]->pre;
					pos[i]->next=pos[k];
					pos[k]->pre->next=pos[i];
					pos[k]->pre=pos[i];
				}
				break;
			}
			case 1:
			{
				if(pos[k]==tail)
				{
					pos[i]->next=NULL;
					pos[i]->pre=tail;
					tail=pos[i];
					pos[k]->next=pos[i];
				}
				else
				{
					pos[i]->pre=pos[k];
					pos[i]->next=pos[k]->next;
					pos[k]->next->pre=pos[i];
					pos[k]->next=pos[i];
				}
				break;
			}	
		}
	}
	scanf("%d",&M);
	for(int i=1,x;i<=M;++i)
	{
		scanf("%d",&x);
		if(pos[x]!=NULL)
		{
			if(pos[x]==head)
			{
				head=pos[x]->next;
				delete pos[x];
				pos[x]=NULL;
				head->pre=NULL;
			}
			else if(pos[x]==tail)
			{
				tail=pos[x]->pre;
				delete pos[x];
				pos[x]=NULL;
				tail->next=NULL;
			}
			else
			{
				pos[x]->pre->next=pos[x]->next;
				pos[x]->next->pre=pos[x]->pre;
				delete pos[x];
				pos[x]=NULL;
			}
		}
	}
	for(NODE *it=head;it!=tail;it=it->next)
		printf("%d ",it->num);
	printf("%d\n",tail->num);
	return 0;
}
