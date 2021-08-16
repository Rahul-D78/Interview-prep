#include <iostream>
using namespace std;

#define ll long long int


bool isValid(ll books[], ll n, ll k, ll ans) {
	int students = 1;
	ll current_pages = 0;
	for(int i =0; i<n;i++) {

		 /*
		 	10 + 20 
			let's say number of pages right now is 10 + 20 and the max limit is 50
			10 + 20 + 30
			I can not add 30 
			I make the current pages as 30 and increases the current page to 2
		 */


		if(current_pages+ books[i] > ans) {
			current_pages = books[i];
			students++;
			if(students > k) {
				return false;
			}
		}else {
			//50 = 10 + 20 + 30
			//let's say the current mid is 50 and student is reading 10 pages 
			//he can read 20 more but he can not read 30 more 
			current_pages += books[i];
		}
	}
	return true;
}

ll binarySearchBooks(ll books[], ll n, ll k) {
	ll totalPages = 0;
	ll s =0, e =0;
	for(int i =0; i< n;i++) {
		//atleast one book each student will read and books containing
		//the max number of pages will be the minimum ans 
		totalPages += books[i];
		s = max(s, books[i]);
	}

	e = totalPages;
	int finalAns = s;

	while(s <= e) {
		ll mid = (s+e)/2;
		//we are passing the current mid because if current mid is the ans and I have to check if 
		//that is a valid configuration or not
		if(isValid(books, n, k, mid)) {
			// we have to search in the left part for true and viceversa
			//storing the lowest possible feasebile ans which is true
			finalAns = mid;
			e = mid - 1;
		}else {
			s = mid + 1;
		}
	}
	return finalAns;
}

int main() {

	//k for students and n for no of books

	ll n;
	ll k;

	ll books[100005];

	for(int i=0; i<n;i++) {
		cin>>books[i];
	}

	cout<<binarySearchBooks(books, n, k);

	return 0;
}