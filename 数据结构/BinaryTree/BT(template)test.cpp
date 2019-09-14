#include<iostream>
#include"BT.h"
using namespace std;
int main() {
	
	BinaryTree<char> bt;
	cout << "creat binary tree" <<endl;
	cout << "import characters (end the subtree with '#') :" << endl;
	bt.TreeCreat(bt.Tree_root());
	cout << "In_order_Traverse: "<< endl;
	bt.In_order_Traverse1(*bt.Tree_root());
	printf("\n");
	bt.In_order_Traverse2(*bt.Tree_root());
	cout << "Pre_order_Traverse: "<<endl;
	bt.Pre_order_Traverse1(*bt.Tree_root());
	printf("\n");
	bt.Pre_order_Traverse2(*bt.Tree_root());
	
	cout << "Post_order_Traverse: "<< endl;
	bt.Post_order_Traverse1(*bt.Tree_root());
	printf("\n");
	bt.Post_order_Traverse2(*bt.Tree_root());
	
} 
