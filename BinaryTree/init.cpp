#include<iostream>
#include<queue>
#include <algorithm>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
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
	int ls = height(root->left);
	int rs = height(root->right);
	return max(ls, rs) + 1;
}

int count(Node* root) {
	if(root == NULL) {
		return 0;
	}
	return 1 + count(root->left) + count(root->right);
}

void printKthLevel(Node* root, int k) {
	if(root == NULL) {
		return;
	}
	if(k == 1) {
		cout<< root->data<<" ";
		return;
	}
	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
	return;
}

//print all the levels
void printAllLevels(Node* root) {
	int H = height(root);
	for(int i = 1; i<=H; i++) {
		printKthLevel(root, i);
		cout<<endl;
	}
	return;
}

//print the tree level by level
void bfs(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* f = q.front();
		if(f == NULL) {
			cout<<endl;
			q.pop();
			if(!q.empty()) {
				q.push(NULL);
			}
		}else{
			q.pop();
			cout<<f->data<<",";

			if(f -> left) {
				q.push(f -> left);
			}
			if(f -> right) {
				q.push(f -> right);
			}
		}
	}
	return;
}

void print(Node* root) {
	//base
	if(root = NULL) {
		return;
	}

	//rec case
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
	return;
}

void printIn(Node* root) {
	if(root == NULL) {
		return;
	}
	printIn(root->left);
	cout<<root->data<<",";
	printIn(root->right);
	return;
}

void printPost(Node* root) {
	if(root == NULL) {
		return;
	}
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<",";
	return;
}

//largest distance between any two nodes in a tree
int diameter(Node* root) {
	if(root == NULL)  {
		return 0;
	}

	//at every node we are computing 
	//the height of the tree
	int h1 = height(root -> left);
	int h2 = height(root -> right);
	int op1 = h1 + h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1, max(op2, op3));
}	

int main() {

	Node* root = buildTree();
	bfs(root);
	cout<<endl;
	cout<<count(root);
	cout<<endl;
	printKthLevel(root, 1);
	cout<<endl;
	cout<<height(root);
	cout<<endl;
	printAllLevels(root);
	cout<<endl;
	cout<<diameter(root);
	cout<<endl;
	return 0;
}