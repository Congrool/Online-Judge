#pragma once
#include<stack> 
#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node*left, *right;
	Node(int d = 0, Node* l = NULL,Node* r  = NULL) {
		data = d;
		left = l;
		right = l;
	}
};
typedef Node* Nodep; 
class BinaryTree {
private:
	Node * root;
	int TreeSize;
public:
	BinaryTree() {
		root = NULL;
		TreeSize = 0;
	}
	void TreeCreat(Nodep* curnode);	//先序遍历建立二叉树
	Nodep* Tree_root();
	void Pre_order_Traverse1(Node* node);	//1是递归版本
	void In_order_Traverse1(Node* node);
	void Post_order_Traverse1(Node* node);
	void Pre_order_Traverse2(Node* node);	//2是非递归版本
	void In_order_Traverse2(Node* node);
	void Post_order_Traverse2(Node* node);
};
void BinaryTree::TreeCreat(Nodep* curnode) {  //这个bug修了我两三个小时，这参数不能是Node*，应该是Node**，否则就算
	int data;								//把curnode(Node*)置为NULL，curnode所代表的Node*指针并不会变为NULL，还算是按值传递
	cin >> data;							//导致前一个结点的right和left的指针并没有置为NULL，在后续步骤中会产生错误
	if (data == -1) {
		*curnode = NULL;
		return;
	}
	else {
		*curnode = new Node();
		(*curnode)->data = data;
		Nodep* left = &((*curnode)->left);
		Nodep* right = &((*curnode)->right);
		TreeCreat(left);
		TreeCreat(right);
	}
}
Nodep* BinaryTree::Tree_root() {
	return &root;
}
void BinaryTree::Pre_order_Traverse1(Node* node) {
	if (node) {
		printf("%d ", node->data);
		Pre_order_Traverse1(node->left);
		Pre_order_Traverse1(node->right);
	}
	else {
		return;
	}
}
void BinaryTree::In_order_Traverse1(Node* node) {
	if (node) {
		In_order_Traverse1(node->left);
		printf("%d ", node->data);
		In_order_Traverse1(node->right);
	}
	else {
		return;
	}
}
void BinaryTree::Post_order_Traverse1(Node* node) {
	if (node) {
		Post_order_Traverse1(node->left);
		Post_order_Traverse1(node->right);
		printf("%d ", node->data);
	}
	else {
		return;
	}
}
void BinaryTree::Pre_order_Traverse2(Node* node) {
	stack<Node*> temp;
	temp.push(node);
	Node* curnode;
	while (!temp.empty()) {
		curnode = temp.top();
		printf("%d ", curnode->data);
		temp.pop();
		if (curnode->right)
			temp.push(curnode->right);
		if (curnode->left)
			temp.push(curnode->left);
	}
	printf("\n");
}
void BinaryTree::In_order_Traverse2(Node* node) {
	stack<Node*> temp;
	Node* curnode = node;
	while (!temp.empty() || curnode) {
		while (curnode) {
			temp.push(curnode);
			curnode = curnode->left;
		}
		curnode = temp.top();
		printf("%d ", curnode->data);
		temp.pop();
		curnode = curnode->right;
	}
	printf("\n");
}
void BinaryTree::Post_order_Traverse2(Node* node) {
	stack<Node*>temp;
	Node* curnode = node;
	Node* prenode = NULL;
	temp.push(node);
	if (curnode == NULL) {
		printf("NULL");
		return;
	}
	while (!temp.empty()) {
		curnode = temp.top();
		if ((!curnode->left && !curnode->right) ||
			(prenode && (prenode == curnode->left || prenode == curnode->right))){
			printf("%d ", curnode->data);
			prenode = curnode;
			temp.pop();
		}
		else {
			if(curnode->right){
				temp.push(curnode->right);
			}
			if (curnode->left) {
				temp.push(curnode->left);
			}
		}
	}
	printf("\n");
}