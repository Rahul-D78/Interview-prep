#include <iostream>
#include <vector>

using namespace std;

int knapsackTD(vector<int> wts, vector<int> prices, int N, int W) {
	//base case
	if(N == 0 or W == 0) {
		return 0;
	}

	/*
	you have 2 options for every items either I include the last item 
	if i include that item the value will be 
	inc = price[n-1]
	*/

	//rec case
	int inc =0, exc =0;
	if(wts[N-1] <= W) {
		inc = prices[N-1] + knapsackTD(wts, prices, N-1, W - wts[N-1]);
	}
	exc = knapsackTD(wts, prices, N, W);
	return max(inc, exc);
}

int knapsackBU(vector<int> wts, vector<int> prices, int N, int W) {
	vector<vector<int> > dp(N+1, vector<int>(W+1, 0));

	for(int n =1; n <=N; n++) {
		for(int w=1; w<=W; w++) {
			int inc, exc = 0;

			//at any point of time our wt should not increase the current wt
			if(wts[n-1] <= w) {
				//if i include this item then profit that i am going to make will 
				//be equal to price of this item and profit that i am making from the 
				//sub problem 
				//sub problem is already computed and store inside the dp array

				//making a call on the previous row on some col that col is nothing
				//but the remaining capacity of the bag

				//if your currnt capacity is 7 kg and your item wt is 3 kg
				//so your index will be 7 - 3 = 4 and you are making a call 
				//on the 4th index   


				inc = prices[n-1] + dp[n-1][w- wts[n-1]];
			}
			//we are making a call on the item which is in the same col but in the
			//prev row
			//we dont reduce the capacity of the bag 
			//in order to compute a cell we need to know all the values in the 
			//prev row 
			//the prev cell values are always computed because we are comming in 
			//row by row fashion 
			exc = dp[n-1][w];
		}
	}
	return dp[N][W];
}

int main() {

	vector<int> wts({2, 7, 3, 4});
	vector<int> prices({5, 20, 20, 10});

	int N = 4;
	int W = 11;	

	cout<<knapsackTD(wts, prices, N, W);

	return 0;
}