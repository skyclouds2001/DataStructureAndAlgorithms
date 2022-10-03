#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAXN = 1000;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int n;
int p[MAXN];
int bp[MAXN];

void init() {
	n = (int)(rand() * MAXN);
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			a[i][j] = (int)(rand() * 10);
		}
	}
}

void greedyAlgorithm() {
	int ip = 0;
	int bms = a[0][0];
	printf("\ngreedy path: ");
	printf("%d ", ip);
	
	for(int i = 1; i < n; i++)
	{
		ip = (a[i][ip] >= a[i][ip + 1]) ? ip : (ip + 1);
		bms += a[i][ip];
		printf("%d ", ip);
	}
	
	printf("\n");
	printf("\nsum=%ld\n", bms);
}

void exhaustiveSearchAlgorithm() {
	int bms = 0;
	
	for(int i = 0; i < n; i++) {
		p[i] = 0;
		bp[i] = 0;
		bms += a[i][0];
	}
	
	int go = 1;
	while(go)
	{
		//next
		go = 0;
		for(int i = n - 1; i > 0; i--)
		{
			if(p[i] < i && p[i] <= p[i - 1])
			{
				++p[i];
				for(int k = i + 1; k < n; k++)
					p[k] = p[k - 1];
				go = 1;
				break;
			}
		}

		if(!go)
			break;

		//calculate sum
		int ms = 0;
		for(int i = 0; i < n; i++) {
			ms += a[i][p[i]];
		}

		//copy the best
		if(ms > bms)
		{
			for(int i = 0; i < n; i++) {
				bp[i] = p[i];
			}
			bms = ms;
		}
	}

	printf("\nbms=%ld\n", bms);
	printf("best path:");
	for(int i = 0; i < n; i++) {
		printf("%d ", bp[i]);
	}
	printf("\n");
}

void dynamicProgrammingAlgorithm() {
	// calculate matrix b
	b[0][0] = a[0][0];
	int i = 1;
	int j = 0;

	while(i < n) {
		if(j == 0)
			b[i][j] = a[i][j]+b[i - 1 ][j];
		else if(j == i)
			b[i][j] = a[i][j]+b[i - 1][j - 1];
		else
			b[i][j] = max((a[i][j] + b[i - 1][j - 1]),
					(a[i][j] + b[i - 1][j]));

		if(++j > i) {
			i++;
			j = 0;
		}
	}

	// find maximal in the last row of b
	int ms = b[n - 1][0];
	int jm = 0;

	for(int j=1;j<n;j++)
	{
		if(b[n - 1][j] > ms) {
			ms = b[n - 1][j];
			jm = j;
		}
	}

	// recover the path
	p[n-1]=jm;
	for(int i=n-1;i>=1;i--) {
		if(p[i]==0) 
			p[i-1]=0;
		else if(p[i]==i)
			p[i-1]=i-1;
		else
		{
			int pr=b[i][p[i]];
			
			if(pr==a[i][p[i]]+b[i-1][p[i]-1])
				p[i-1]=p[i]-1;
			else
				p[i-1]=p[i];
		}
	}

	// print results
	printf("sum=%ld\nmax patk: ", ms);
	for(int i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");
}

int main() {
	init();
	
	double t1_1 = clock();
	greedyAlgorithm();
	double t1_2 = clock();
	printf("passTime: %.2fms", (double)(t1_2 - t1-1) / CLOCKS_PER_SEC * 1000);

	double t2_1 = clock();
	exhaustiveSearchAlgorithm();
	double t2_2 = clock();
	printf("passTime: %.2fms", (double)(t2_2 - t2-1) / CLOCKS_PER_SEC * 1000);

	double t3_1 = clock();
	dynamicProgrammingAlgorithm();
	double t3_2 = clock();
	printf("passTime: %.2fms", (double)(t3_2 - t3-1) / CLOCKS_PER_SEC * 1000);

	return 0;
}
