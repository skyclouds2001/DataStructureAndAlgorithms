#include<iostream>

int num[10][10] = {{}, {0, 3}, {0, 6, 7}, {0, 3, 4, 5}, {0, 6, 9, 3, 1}, {0, 2, 9, 1, 4, 3}};
int dp[10][10];
int ans = 0;

int main() {
	
	for(int i = 1; i <= 5; ++i) {
		for(int j = 1; j <= i; ++j) {
			
			dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1]) + num[i][j];	
			ans = std::max(ans, dp[i][j]);
			
			std::cout <<"dp[" << i << "][" << j << "] = " << dp[i][j] << std::endl;
			
		}
	}
	
	std::cout << ans;
	
	return 0;
} 
