#include<cstdio>
#include<cstring>
using namespace std;
int T;
char s[1000 + 3];
int count;

int main() {
	
	scanf("%d", &T);
	
	for(int i = 1; i <= T; ++i) {
		
		scanf("%s", s);
		count = 0;
		
		for(int j = 0; j < strlen(s); ++j) {
			if(s[j] == '1') {
				++count;
				int k = j + 1;
				
				while(k < strlen(s) and s[k] == '1')
					++k;
				
				j = k - 1;
			}
		}
		
		printf("%d\n", count);
		memset(s, '\0', sizeof(s));
	}
	
	return 0;
}
