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
	int dist() {
		return x*x + y*y; //square of the dist
	}
};


class CarCompare {
	//operator overloading
	bool operator()(const Car A, const Car B){
		return A.dist() < B.dist(); //max heap
	}
}

void printNearestCars(vector<Car> cars, int k) {


	//create a max heap of size k
	priority_queue<Car, vector<Car>, CarCompare> maxheap(cars.begin(), cars.begin()+k);

	//remaining cars
	for(int i=k; i < cars.size(); i++) {
		auto car = cars[i];

		if(car.size) {

		}
	}
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