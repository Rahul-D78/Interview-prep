#include <iostream>
#include <string>
using namespace std;

int lcs(string s1, string s2, int i, int j) {
	//base case
	if(i==s1.length() or j==s2.length()) {
		return 0;
	}

	//if both the letters match we have add 1 and call on the remaining part
	if(s1[i] == s2[j]) {
		return 1 + lcs(s1, s2, i+1, j+1);
	}

	//if both of the string dont match we have two options in that case 
	/*
	1 + 1 + (CD   ---> D
					   EDG

			 EDG) ---> CD 
					   DG
	*/
	int opt1 = lcs(s1, s2, i+1, j);
	int opt2 = lcs(s1, s2, i, j+1);
	return max(opt1, opt2);
}


int main() {

	string s1 = "ABCD";
	string s2 = "ABEDG";

	cout<<lcs(s1,s2, 0, 0);

	return 0;
}