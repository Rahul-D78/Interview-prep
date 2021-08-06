#include<iostream>
using namespace std;

/*
classical recursion problem
*/

void towerOfHanoi(int n, char src, char helper, char dest) {
	if(n == 0) {
		return;
	}

	//Rec case
	//1st step (N-1) disks move from src to helper
	towerOfHanoi(n-1, src, dest, helper);

	cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;

	towerOfHanoi(n-1, helper, dest, src);
}


int main() {

	int n;
	cin>>n;

	cout<<towerOfHanoi(n, 'A', 'C', 'B');

	return 0;

}