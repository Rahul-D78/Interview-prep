#include <iostream>
#include <vector>
using namespace std;

/*
place n queens such that all queens are safe no queens cuts each other
 	we have check for if a queen cuts other in:  
		1. row wise
		2. col wise
		3. digonal 
*/

//is it safe to place the queen in the board at cell {i,j}

bool isSafe(vector<vector<int> >&board, int i, int j, int n) {
	
	//dont need to check the below cells because we are filling matrix 
	//row by row

	//check for col
	for(int row = 0; row < i; row++) {
		if(board[row][j] == 1) {
			return false;
		}
	}
	//left diagonal
	int X = i; //row 
	int Y = j; //col
	while(X >= 0 and Y >= 0) {
		if(board[X][Y] == 1) {
			return false;
		}
		X--;
		Y--;
	}
	//right diagonal
	X = i; Y = j;
	while(X >= 0 and Y < n) {
		if(board[X][Y] == 1) {
			return false;
		} 
		X--;
		Y++;
	}
	//The position is now safe col and digonals
	return true;
}

//i = current row
//n = how many nymber of rows

bool solveNqueen(vector<vector<int> > &board, int i, int n) {
	//base case
	if(i == n) {
		//you have sucessfully placed queens in n rows (0 .... row-1)
		//print the board
		for(int i = 0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(board[i][j] == 1) {
					cout<<"Q";
				}else{
					cout<<"_";
				}
			}
			cout<<endl;
		}
		return true;
	}
	// rec case
	//try to place the queen in the current row and call the subsequence parts
	for(int j =0; j < n; j++) {
		//condition if (i ,j) is safe to place 
		if(isSafe(board, i, j, n)) {
			//place the queen assuming (i, j) are in the right position
			board[i][j] = 1;
			bool nextQueenRakhPaye = solveNqueen(board, i+1, n);
			if(nextQueenRakhPaye) {
				return true;
			}
			//else board i,j is not in the right position
			board[i][j] = 0; //backtrack
		}
	}
	//tried for all the position in a curr row and could not place a queen
	return false;
}

int main() {
 
	int n;
	cin>>n;

	vector<vector<int> >board;

	solveNqueen(board, 0, n);

	return 0;
}