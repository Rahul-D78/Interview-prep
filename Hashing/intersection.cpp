#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> m(nums1.begin(), nums2.begin());
	vector<int> res;
	for(auto a: nums2)
		if(m.count(a)) {
			res.push_back(a);
			m.erase(a);
		}
	return res;
}

int main() {

	vector<int> m({1, 2, 3, 4, 5, 6});
	return 0;
}