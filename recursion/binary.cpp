#include <iostream>
using namespace std;

/*
1, 2, 3, 4, 5
6, 7, 8, 9, 10
key = 2
*/

bool binary(int *a, int n, int key) {
	int s = 0;
	int e = n;

	while(s < e) {
		int mid = (s+e)/2;
		if(a[mid] == key) {
			return true;
		}else if(a[mid] > key){
			e = mid -1;
			e--; 
		}else if(a[mid] < key) {
			s = mid + 1;
			s++;
		}	
	}
	return false;

}


int main() {

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(arr)/sizeof(int);

	if(binary(arr, n, 2)) {
		cout<<"yes it is present";
	}else {
		cout<<"No it is not present";
	}

	return 0;
}