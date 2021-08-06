#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this -> val = val;
		left = right = NULL;
	}
};

bool findPaths(Node* root, int sum) {
	if(root -> val == NULL) return false; 

	if(root -> val == sum && root -> left == NULL && root -> right == NULL) 
		return true;
	return findPaths(root->left, sum - root -> val) || 
		   findPaths(root->right, sum - root -> val);
}

void findPathsII(Node* node, int sum, vector<int> &path, vector<vector<int> >&paths) {
	if(!node) return;
	path.push_back(node -> val);
	if(!(node -> left) && !(node -> right) && sum == node -> val)
		paths.push_back(path);
	findPaths(node -> left, sum - node -> val, path, paths);
	findPaths(node -> right, sum - node -> val, path, paths);
	path.pop_back();
}

vector<vector<int> > pathSum(Node* root, int sum) {
	vector<vector<int> > paths;
	vector<int> path;
	findPaths(root, sum, path, paths);
	return paths;
}


int main() {



	return 0;
}