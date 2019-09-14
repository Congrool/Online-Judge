class Node
{
public:
	Node * left, *right;
	Node *par;
	int key;		//键
//	int N;			//以该节点为根节点的总节点数
	Node(int k, Node* l = NULL, Node*r = NULL, Node*p = NULL) {
		left = l;
		right = r;
		par = p;
		key = k;
	}
};
class BST
{
private:
	Node *root;
	int size;
	void transplant(Node *a, Node *b);
public:
	BST():root(NULL){}
	~BST() {};
	void prewalk(Node *);
	void cenwalk(Node *);
	void aftwalk(Node *);
	Node* getmin(Node * a);
	Node* getmax(Node * a);
	int getsize();
	Node *getroot();
	Node* seek(Node *a, int key);     //找到键为key的结点
	Node* seek(int x);
	void Tinsert(Node *);
	void Tinsert(int x);
	void Tdelete(Node *);

};

void BST::prewalk(Node* a)
{
	Node *now = a;
	if(now)
	{
		printf("%d ", now->key);
		prewalk(now->left);
		prewalk(now->right);
	}
}
void BST::cenwalk(Node* a)
{
	Node *now = a;
	if (now)
	{
		cenwalk(now->left);
		printf("%d ", now->key);
		cenwalk(now->right);
	}
}
void BST::aftwalk(Node* a)
{
	Node *now = a;
	if (now)
	{
		aftwalk(now->left);
		aftwalk(now->right);
		printf("%d ", now->key);

	}
}
Node* BST::getmin(Node * a) {
	Node* now = a;
	while (now->left)
		now = now->left;
	return now;
}
Node* BST::getmax(Node * a) {
	Node* now = a;
	while (now->right)
		now = now->right;
	return now;
}
int BST::getsize() {
	return size;
}
Node* BST::getroot() {
	return root;
}

Node* BST:: seek(Node *a, int key)
{
	if (key == a->key || a == NULL)
		return a;
	if (key > a->key)
	{
		return seek(a->right, key);
	}
	else
	{
		return seek(a->left, key);
	}
}
Node* BST:: seek(int key) {
	return seek(root, key);
}


void BST::Tinsert(Node* a)
{
	Node *now = root;
	Node *pre = NULL;
	while (now)
	{
		pre = now;
		if (a->key < now->key)
			now = now->left;
		else
			now = now->right;
	}
	if (pre == NULL)   //tree is empty
		root = a;
	else
	{
		a->par = pre;
		if (a->key < pre->key)
			pre->left = a;
		else
			pre->right = a;
	}
	size++;
}

void BST::Tinsert(int key) {
	Node * a = new Node(key);
	Tinsert(a);
}
void BST:: transplant(Node * a, Node *b)
{
	Node *pre = a->par;
	if (pre == NULL)				//a is root or not
		root = b;
	else if (a == pre->left)
		pre->left = b;
	else
		pre->right = b;
	if(b!=NULL)
		b->par = pre;
}

void BST::Tdelete(Node* aim) {
	if (aim->left == NULL)
		transplant(aim, aim->right);
	else if (aim->right == NULL)
		transplant(aim, aim->left);
	else
	{
		Node *y = getmin(aim->right);
		if (y->par != aim)
		{
			transplant(y, y->right);
			y->right = aim->right;
			y->right->par = y;
		}		
		transplant(aim, y);
		y->left = aim->left;
		y->left->par = y;
		delete(aim);
	}
}

