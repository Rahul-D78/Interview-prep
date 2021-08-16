#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void setZero(vector<vector<int> >&matrix) {

	int R = matrix.size();
	int C = matrix[0].size();
	unordered_set<int> rows;
	unordered_set<int> cols;

	for(int i =0; i<R;i++) {
		for(int j =0; j < C; j++) {
			if(matrix[i][j] == 0) {
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	//iterate and update
	for(int i =0; i<R;i++) {
		for(int j =0; j < C;j++) {
			if(rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
				matrix[i][j] = 0;
			}
		}
	}
}

int main() {

	vector<vector<int> > matrix 
	{
		{1, 0, 1},
		{1, 1, 1},
		{1, 1, 1}
	};

	for(int i =0;i< matrix.size();i++) {
		for(int j =0; j< matrix[0].size();j++) {
			cout<<matrix[i][j];
		}
		cout<<endl;
	}	

	cout<<endl;

	setZero(matrix);

	for(int i =0;i< matrix.size();i++) {
		for(int j =0; j< matrix[0].size();j++) {
			cout<<matrix[i][j];
		}
		cout<<endl;
	}

	return 0; 	
}