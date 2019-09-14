#include<queue>
#include<cstring>
#include<string>
#include<iostream>
#include<cctype>
#include<cstdlib>
using namespace std;
int Maxlength;
struct Node {
	char data;
	int wei;
	Node* left, *right;
	void init(char da, int w) {
		data = da;
		wei = w;
		left = NULL, right = NULL;
	}
	bool operator <(const Node& b) const { //重载 < ,在priority_queue中要用到
		return b.wei < wei;
	}
};

//初始化单个Node结点
void input(Node* huffman_Node) {
	for (int i = 0; i < Maxlength; i++) {
		char tmpc = getchar();
		while (isspace(tmpc)) {
			tmpc = getchar();
		}
		int tmpi;
		scanf("%d", &tmpi);
		huffman_Node[i].init(tmpc, tmpi);
	}
}
//创建哈夫曼树
Node* creat_huffman_tree(Node* huffman_Node, string res[]) {
	priority_queue<Node> pq;
	input(huffman_Node);
	for (int i = 0; i < Maxlength; i++) {
		pq.push(huffman_Node[i]);
		res[i] = "";
	}
	Node *a = NULL, *b = NULL;
	while (!pq.empty()) {
		a = (Node*)malloc(sizeof(Node));
		b = (Node*)malloc(sizeof(Node));
		*a = pq.top();
		pq.pop();
		if (pq.empty()) break;
		*b = pq.top();
		pq.pop();
		Node* nnode = (Node*)malloc(sizeof(Node));
		nnode->data = '\0';
		nnode->wei = a->wei + b->wei;
		nnode->left = a, nnode->right = b;
		pq.push(*nnode);
	}
	return a;
}

//前序遍历已经建立好的哈夫曼树，完成编码
void pre_order_traverse(Node* curnode, string &code, string* res) {
	if (curnode->left == NULL && curnode->right == NULL) {
		int pos = curnode->data - 'a';
		res[pos] = code;
		return;
	}
	code.append("0");
	pre_order_traverse(curnode->left, code, res);
	code.erase(code.length() - 1, 1);
	code.append("1");
	pre_order_traverse(curnode->right, code, res);
	code.erase(code.length() - 1, 1);
}
void solve(Node* root,string* res) {
	string code = "";
	pre_order_traverse(root, code, res);
}

//封装以上的函数，控制对外接口
string* huffman_code(int Maxlength) {
	Node* huffman_Node = new Node[Maxlength];
	string* res = new string[Maxlength];
	Node* hft = creat_huffman_tree(huffman_Node, res);
	solve(hft, res);
	free(huffman_Node);
	return res;
}
int main() {
	while (cin >> Maxlength) {
		string* res = huffman_code(Maxlength);
		for (int i = 0; i < Maxlength; i++) {
			printf("%c : ", 'a' + i);
			cout << res[i] << endl;
		}
	}
}
