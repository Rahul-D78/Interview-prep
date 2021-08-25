#include <iostream>
using namespace std;

bool isOdd(int n) {
	return (n&1);
}

//>> devide by 2
//<< multiply by 2
int getBit(int n, int i) {
	//find the ith bit(Right)
	int mask = (1<<i);
	int bit = (n&mask) > 0 ? 1 : 0;
	return bit;
}

int setBit(int n, int i) {
	int mask = (1 << i);
	int ans = n | mask;
	return ans;
}

void clearBit(int &n, int i) {
	int mask = ~(1 << i);
	cout<<"before"<<mask<<endl;
	n = n&mask;
	cout<<n<<endl;
}

void updateBit(int &n, int i, int v) {
	int mask = ~(1<<i);
	int clear_no = n&mask;
	n = clear_no | (v<<i);
	cout<<n; 
}
int main() {
	int n = 5;
	// cout<<getBit(5, 0);
	// cout<<setBit(5, 1);
	// clearBit(n, 1);
	updateBit(n, 1, 3);
	return 0;
}