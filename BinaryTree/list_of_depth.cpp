#include <iostream>
#include <list>
#include<iterator>
using namespace std;

list<int> l;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this -> data = data;
		left = right = NULL;
	}
};

int height(Node* root) {
	if(root == NULL) {
		return 0;
	}

	//rec case
	int ls = height(root->left);
	int rs = height(root->right);
	return max(ls, rs) + 1;
}

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

void printKthLevel(Node* root, int k) {
	if(root == NULL) {
		return;
	}
	if(k == 1) {
		cout<<root -> data<<" ";
		l.push_back(root->data);
		return;
	}
	printKthLevel(root -> left, k-1);
	printKthLevel(root -> right, k-1);
}

void printAllLevels(Node* root) {
	int H = height(root);
	for(int i =1; i <= H; i++) {
		printKthLevel(root, i);
		cout<<endl;
	}
	return;
}

void print(Node* root) {
	if(root == NULL) {
		return;
	}
	//rec
	cout<<root->data<<",";
	print(root->left);
	print(root->right);
	return;
}

void showList() {
	list<int> :: iterator it;
	for(it = l.begin(); it != l.end(); it++) {
		cout<<*it<<"-->";
	}
	cout<<"NULL";
}

int main() {

	Node* root = buildTree();
	print(root);
	// cout<<endl;
	// cout<<height(root);
	// cout<<endl;
	// printKthLevel(root, 2);
	cout<<endl;
	printAllLevels(root);
	cout<<endl;
	showList();
	return 0;
}