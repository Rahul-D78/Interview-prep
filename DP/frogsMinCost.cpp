#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//Bottom Up solution
//slightly optimised than top down
int getMinCost(vector<int> stones) {
	//base case

	int n = stones.size();
	vector<int> dp(n, 0);

	///lock up
	dp[1] = abs(stones[1]-stones[0]);

	//rec case

	for(int i=2; i<n; i++) {
		int op1 = abs(stones[i] - stones[i-1] + dp[i-1]);
		int op2 = abs(stones[i] - stones[i-2] + dp[i-2]);
		dp[i] = min(op1, op2);
	}

	//retriving
	return dp[n-1];
}

int main() {

/*Sample Input
6
30 10 60 10 60 50
*/

	int n;
	cin>>n;

	vector<int > stones(n);

	for(int i =0;i < n;i++) {
		cin>>stones[i];
	}

	cout<<getMinCost(stones)<<endl;
	return 0;
}