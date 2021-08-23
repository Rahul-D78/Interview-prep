#include<iostream>
#include <unordered_set>
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

Node* insert(Node* root, int data) {
	if(root == NULL) {
		return new Node(data);
	}
	//rec case
	if(data < root -> val) {
		root -> left = insert(root -> left, data);
	}else {
		root -> right = insert(root -> right, data);
	}
	return root;
}

bool dfs(Node* root, unordered_set<int>& set, int k){
    if(root == NULL)return false;
    if(set.count(k - root->val))return true;
    set.insert(root->val);
    return dfs(root->left, set, k) || dfs(root->right, set, k);
}

bool findTarget(Node* root, int k) {
    unordered_set<int> set;
    return dfs(root, set, k);
}

void printTree(Node* root) {
	if(root ==NULL) {
		return;
	}
	cout<<root->val<<",";
	printTree(root->left);
	printTree(root->right);
}

int main() {

	Node* root = NULL;

	findTarget(root, 3);

	return 0;
}