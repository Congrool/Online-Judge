#pragma once
#include<stack> 
#include<iostream>
using namespace std;
template<typename T>
class Node {
public:
	T data;
	Node*left, *right;
	Node(T d, Node* l = NULL,Node* r  = NULL) {
		data = d;
		left = l;
		right = l;
	}
};
template<typename T>
class BinaryTree {
	typedef Node<T>* Nodep;
private:
	Node<T> * root;
	int TreeSize;
public:
	BinaryTree() {
		root = NULL;
		TreeSize = 0;
	}
	void TreeCreat(Nodep* curnode);	//先序遍历建立二叉树
	Node<T>** Tree_root();
	void Pre_order_Traverse1(Node<T>* node);	//1是递归版本
	void In_order_Traverse1(Node<T>* node);
	void Post_order_Traverse1(Node<T>* node);
	void Pre_order_Traverse2(Node<T>* node);	//2是非递归版本
	void In_order_Traverse2(Node<T>* node);
	void Post_order_Traverse2(Node<T>* node);
};
template<typename T>
void BinaryTree<T>::TreeCreat(Nodep* curnode) {  //先序建立二叉树 
	T data;							
	cin >> data;						
	if (data == '#') {
		*curnode = NULL;
		return;
	}
	else {
		*curnode = new Node<T>(data);
		Nodep* left = &((*curnode)->left);
		Nodep* right = &((*curnode)->right);
		TreeCreat(left);
		TreeCreat(right);
	}
}

template<typename T>
Node<T>** BinaryTree<T>::Tree_root() {
	return &root;
}

template<typename T>
void BinaryTree<T>::Pre_order_Traverse1(Node<T>* node) { //递归先序遍历 
	if (node) {
		cout << node->data << " ";
		Pre_order_Traverse1(node->left);
		Pre_order_Traverse1(node->right);
	}
	else {
		return;
	}
}
template<typename T>
void BinaryTree<T>::In_order_Traverse1(Node<T>* node) {  //递归中序遍历 
	if (node) {
		In_order_Traverse1(node->left);
		cout << node->data << " ";
		In_order_Traverse1(node->right);
	}
}
template<typename T>
void BinaryTree<T>::Post_order_Traverse1(Node<T>* node) {  //递归后序遍历 
	if (node) {
		Post_order_Traverse1(node->left);
		Post_order_Traverse1(node->right);
		cout << node->data << " ";
	}
}
template<typename T>
void BinaryTree<T>::Pre_order_Traverse2(Node<T>* node) {  //非递归先序遍历 
	stack<Node<T>*> temp;
	temp.push(node);
	Node<T>* curnode;
	while (!temp.empty()) {
		curnode = temp.top();
		cout << curnode->data << " ";
		temp.pop();
		if (curnode->right)
			temp.push(curnode->right);
		if (curnode->left)
			temp.push(curnode->left);
	}
	printf("\n");
}
template<typename T>
void BinaryTree<T>::In_order_Traverse2(Node<T>* node) {  //非递归中序遍历 
	stack<Node<T>*> temp;
	Node<T>* curnode = node;
	while (!temp.empty() || curnode) {
		while (curnode) {
			temp.push(curnode);
			curnode = curnode->left;
		}
		curnode = temp.top();
		cout << curnode->data << " ";
		temp.pop();
		curnode = curnode->right;
	}
	printf("\n");
}
template<typename T>
void BinaryTree<T>::Post_order_Traverse2(Node<T>* node) {  //非递归后序遍历 
	stack<Node<T>*>temp;
	Node<T>* curnode = node;
	Node<T>* prenode = NULL;
	temp.push(node);
	if (curnode == NULL) {
		printf("NULL");
		return;
	}
	while (!temp.empty()) {
		curnode = temp.top();
		if ((!curnode->left && !curnode->right) ||
			(prenode && (prenode == curnode->left || prenode == curnode->right))){
			cout << curnode->data << " ";
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
