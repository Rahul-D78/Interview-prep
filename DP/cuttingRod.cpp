#include <iostream>
#include <algorithm>
using namespace std;

//recursive solution
int max_profit(int prices[], int n) {
	//base case
	if(n <= 0) return 0;

	//rec case
	//we have to find out the max value we can initialize our ans with - infinity
	int ans = INT_MIN;
	for(int i =0; i< n;i++) {
		int cut = i+1;
		int curr_ans = prices[i] + max_profit(prices, cut - n);
		ans = max(ans, curr_ans);
	}
	return ans;
}

//bottom up solution
int max_profit_dp(int *prices, int n) {
	int dp[n+1];
	dp[0] = 0;

	for(int len =1; len <= n; len++) {

		int ans = INT_MIN;

		for(int i =0; i<len; i++) {
			int cut = i+1;
			int curr_ans = prices[i] + dp[len-cut];
			ans = max(curr_ans, ans);
		}
		//compute the ans for dp[len]
		dp[len] = ans;
	}
	return dp[n];
}

int main() {
	int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(prices)/sizeof(int);

	cout<< max_profit(prices, n);
	
	return 0;
}