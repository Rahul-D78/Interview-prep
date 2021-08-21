#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int lcsDP(string s1, string s2, int i, int j, vector<vector<int> >&dp) {
	//base case
	if(i == s1.length() or j == s2.length()) {
		return 0;
	}

	//check if a state is already computed or not 
	//lookup state
	if(dp[i][j]!=-1) {
		return dp[i][j];
	}

	//match
	if(s1[i] == s2[j]) {
		return 1 + lcsDP(s1, s2, i+1, j+1, dp);
	}

	//don't match
	int opt1 = lcsDP(s1, s2, i, j+1, dp);
	int opt2 = lcsDP(s1, s2, i+1, j, dp);
	return dp[i][j] = max(opt1, opt2);
}

int main() {

	string s1 = "ABCD";
	string s2 = "ABEDG";

	int n1 = s1.length();
	int n2 = s2.length();

	//we are declaring a 2d vector which is having n1 number of rows 
	//and each row would is a vector of integers and each row contains n2 number of cells
	//and each of them is initialized with a value -1 
	vector<vector<int> >dp(n1, vector<int>(n2, -1)); 

	cout<<lcsDP(s1, s2, 0, 0, dp)<<endl;

	for(int i =0; i< n1; i++) {
		for(int j =0; j< n2;j++) {
			cout<< dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}