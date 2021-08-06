#include <iostream>
#include <vector>
using namespace std;

 bool searchMatrix(vector<vector<int>>& matrix, int R, int C, int target) {
        int i = 0, j = C-1;
        
        /* In case of matrix
		   i/c tells which row we are in 
		   i%c tells which col we are in
        */

        while(i < R && j >= 0) {
        	if(a[i][j] == key) {
        		cout<<"found";
        		return;
        	}
        	else if(a[i][j] > key) {
        		j--;
        	}else {
        		i++;
        	}
        }
        cout<<"ele not found";
}

int main() {

	int n = 4;
	int m = 4;

	vector<vector<int> >v(n, vector<int> (m, 0));

	for(int i=0; i< n; i++) {
		for(int j =0; j < m; j++) {
			v[i][j] = j + i + 1;
		} 
	}

	int r = v.size();
	int c = v[0].size();
	int l = 0, s = m * n -1;

	// for(int i = 0; i<  n; i++) {
	// 	for(int j =0; j < m; j++) {
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int mid = (l + s - 1) >> 1;


	cout<<v.size()<<endl;
	cout<<mid%c<<endl;
	cout<<v[mid/c][mid%c]<<endl;

	return 0;
}