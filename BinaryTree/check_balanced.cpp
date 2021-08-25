#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
		left = right = NULL;
	}
};

Node* buildTree() {
	int d;
	cin>>d;

	if(d == -1) {
		return NULL;
	}
	Node* root = new Node(d);
	root -> left = buildTree();
	root -> right = buildTree();
	return root;
}

int height(Node* root) {
	if(root == NULL) {
		return 0;
	}
	//rec case
	int ls = height(root -> left);
	int rs = height(root -> right);
	return max(ls, rs) + 1;
}

bool isBalanced(Node* root) {
	if(root == NULL) {
		return true;
	}
	int heightDiff = height(root->left) - height(root->right);
	if(abs(heightDiff) > 1) {
		return false;
	}else {
		return isBalanced(root->left) && isBalanced(root->right);
	}
}

void print(Node* root) {
	if(root == NULL) {
		return;
	}
	cout<<root->data<<",";
	print(root->left);
	print(root->right);
	return;
}

int main() {

	Node* root = buildTree();
	print(root);
	cout<<endl;
	cout<<height(root);
	cout<<endl;
	if(isBalanced(root)) {
		cout<<"balanced";
	}else {
		cout<<"not balanced";
	}
	return 0;
}