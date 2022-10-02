#include<cstdio>
#include<cstring>
using namespace std;

char u[1000000+3], v[1000000+3], s[1000000+3];
int n, x, y, num, count1, count2, score;

int main(){
	
	while((scanf("%d", &n)) != EOF) {
		
		scanf("%s", u);
		scanf("%s", v);
		num = strlen(u);
		
		for(int i = 1; i <= n; ++i) {
			scanf("%s", s);
			count1 = 0;
			count2 = 0;
			
			for(int j = 0; j < n; ++j) {
				if(u[j] == s[j])
					++count1;
				if(v[j] == s[j])
					++count2;
			}
			
			score = (count1 > count2)?count1:count2;
			printf("%d", score);
		}
	}
	return 0;
} 
