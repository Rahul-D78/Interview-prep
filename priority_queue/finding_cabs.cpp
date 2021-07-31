#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;

//Given N cartecian positions in a 2D plane each represents the location
//of the cabs you are standing at the origin you want to know
//names of the nearest cabs

class Car {
public:
	string id;
	int x,y;
	Car(string id, int x, int y) {
		this -> id = id;
		this -> x = x;
		this -> y = y;
	}
};

void printNearestCars(vector<Car> cars, int k) {

}

int main() {

	int N,K;
	cin>>N>>K;

	string id;
	int x,y;

	vector<Car> cars;

	for(int i=0; i<N;i++) {
		cin>>id>>x>>y;
		Car car(id, x, y);
		cars.push_back(car);
	}


	printNearestCars(cars, k);

	return 0;
}