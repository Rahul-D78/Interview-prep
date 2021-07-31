#include <iostream>
#include <vector>
using namespace std;

/*Max Non Adjacent Sum
given an array of positive integers, find the max sum
of non adjacent element in the array .
input
[6, 10, 12, 7, 9, 14]
output
32 
*/

int maxSubsetSumNoAdj(vector<int> arr) {
	
	int n = arr.size();
	vector<int> dp(n+1, 0);	

	//corner case
	//we can return the max of 0th element and 0 
	//if the element is -ve
	if(n == 1) {
		return max(arr[0], 0);
	}
	//in case of 2 elements 
	//find the largest ele we have to find the largest ele either it will be
	//arr [0] or arr[1] or you can return 0 in case of -ve element 
	else if(n==2) {
		return max(0, max(arr[0], arr[1]));
	}
	//Bottom up logic
	//either we include the 0th element or we dont include
	//similar thing for dp[1]
	dp[0] = max(arr[0], 0);
	dp[1] = max(0, max(arr[0], arr[1]));

	//we are going to every cell and figuring out what should be the answer here 

	for(int i =2; i < n;i++) {
		//if we include the curr ele and the sum we have is   
 		//the curr ele and the sum till before the prev ele
		int inc = arr[i] + dp[i-2];
		//if we execlude the sum will be till just the prev  ele
		int exc = dp[i-1];
		//dp[i] is the max of inc and exc  
		dp[i] = max(inc, max);
	}
	return dp[n-1];
}

int main() {

	vector<int> arr({6, 10, 12, 7, 9, 14});
	cout<< maxSubsetSumNoAdj(arr);
	
	return 0;
}