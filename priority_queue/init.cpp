#include <iostream>
#include<queue>
using namespace std;

/*
Explain: 

As the name suggests priority queue :

element with a certain priority will come out of the queue first
here it is the element with a bigger value should come out first

Here we are using inbuild queue function to implement such functionality .

*/

//we are writing our own custom compare function insted of using inbuild comparator
class Compare{
public:
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {

	int arr[] = {10, 2, 5, 7, 1, 3};
	int n = sizeof(arr)/sizeof(int);

	//by default it is a maxheap

	// priority_queue<int> heap;

	//we have to pass two more extraa parameaters to produce a minheap
	priority_queue<int, vector<int>, Compare > heap;

	for(int x: arr) {
		heap.push(x);
	}

	while(!heap.empty()) {
		cout<<heap.top()<<endl;
		heap.pop();
	}

	return 0;
}