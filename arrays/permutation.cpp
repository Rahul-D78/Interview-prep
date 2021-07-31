#include<iostream>
#include<vector>
using namespace std;

void permutationRecursive(vector<int> &num, int begin, vector<vector<int> > &result) {
	if(begin >= num.size()) {
		//one permutation instance
		result.push_back(num);
		return;
	}
	for(int i=begin; i < num.size(); i++) {
		swap(num[begin], num[i]);
		permutationRecursive(num, begin+1, result);
		//reset
		swap(num[begin], num[i]);
	}
}

int main() {

	return 0;
}