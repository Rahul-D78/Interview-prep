#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;

class Node {
public:
	int key;
	Node* left;
	Node* right;

	Node(int key) {
		this -> key = key;
		left = right = NULL;
	}
};

Node* insert(Node* root, int key) {
	if(root == NULL) {
		return new Node(key);
	}
	//rec case
	if(key < root -> key) {
		root -> left = insert(root->left, key);
	}else{
		root -> right = insert(root->right, key);
	}
	return root;
}

bool search(Node* root, int key) {

	if(key == root -> key) {
		return true;
	}
	if(key < root -> key) {
		return search(root -> left, key);
	}
	if(key > root -> key) {
		return search(root -> right, key);
	}
	return false;
}


//build the bst in case of a given sorted array 
Node* sortedArryToBst(int arr[], int s, int e) {
	if(s > e) {
		return NULL;
	}
	//rec case
	int mid = (s+e)/2;

	Node* root = new Node(arr[mid]);
	//create left and right subtree recursively
	root -> left = sortedArryToBst(arr, s, mid-1);
	root -> right = sortedArryToBst(arr, mid+1, e);

	return root;
}

int closestInBst(Node* root, int target) {
	
	int closest;
	int diff = INT_MAX;

	Node* temp = root;

	while(temp != NULL) {
		int cur_dif = abs(temp->key - target);
	
		if(cur_dif == 0) {
			return temp->key;
		}

		if(cur_dif < diff) {
			diff = cur_dif;
			closest = temp -> key;
		}
		if(temp -> key < target) {
			temp = temp -> right;
		}else {
			temp = temp -> left;
		}
	}
	return closest;
}

bool isBst(Node* root, int minV = INT_MIN, int maxV = INT_MAX) {
	if(root == NULL) {
		return true;
	}

	if(
		root -> key > minV and
		root -> key < maxV and 
		isBst(root -> left, minV, root -> key) and
		isBst(root -> right, root -> key, maxV)
	)
		return true;
}

void printTree(Node* root) {
	if(root==NULL) {
		return;
	}
	//left root right inore
	cout<<root->key<<",";
	printTree(root->left);
	printTree(root->right);
}

int main() {

	Node* root = NULL;

	vector<int> arr = {8, 3, 10, 1, 6, 14, 7, 13};


	for(int x : arr) {
		root = insert(root, x);
	}
	
	// printTree(root);


	// if(search(root, 7)) {
	// 	cout<<"present";
	// }else {
	// 	cout<<"Not Present";
	// }

	// cout<<endl;

	// Node* root = sortedArryToBst(arr, 0, n-1);
	// printTree(root);
	// cout<<endl;
	// cout<<closestInBst(root, 11)<<endl;

	cout<<INT_MIN<<" "<<INT_MAX<<endl;

	return 0;
}