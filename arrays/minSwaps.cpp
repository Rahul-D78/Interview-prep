#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of size N, find the minimum number of swaps needed to 
sort the array .

sample Input
a1 = [5, 4, 3, 2, 1]

sample output
2
*/

int countMinSwaps(vector<int> arr) {

	//Know the actual positions of elements (sorting)
	//store the current indices

	int n = arr.size();

	pair<int, int> ap[n];
	for(int i=0;i<n;i++) {
		ap[i].first = arr[i];
		ap[i].second = i;
	}

	//sorting
	sort(ap, ap+n);

	//build the main logic
	vector<bool> visited(n, false);

	int ans;

	for(int i=0;i<n;i++) {
		//if element is visited
		int old_pos = ap[i].second; 
		if(visited[i] == true or old_pos==i) {
			continue;
		} 

		//visiting the element for the first time
		int node = i;
		int cycle = 0;

		while(!visited[node]) {
			visited[node] = true;
			int next_node = ap[node].second;
			node = next_node;
			cycle += 1;
		}
		ans += (cycle-1);
	}

	return ans;
}

int main() {

	vector<int> arr({5, 4, 3, 2, 1});

	cout<<countMinSwaps(arr);

	return 0;
}