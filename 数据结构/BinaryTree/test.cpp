#include<iostream>
#include<cstdlib>
using namespace std;
#include"BST.h"
int main()
{
	int a[9] = { 4,9,1,6,7,8,2,3,0};
	BST T;
	for (int i = 0; i < 9; i++)
		T.Tinsert(a[i]);
	Node* n = T.seek(4);
	T.prewalk(T.getroot()); cout << "\n";
	T.cenwalk(T.getroot()); cout << "\n";
	T.aftwalk(T.getroot()); cout << "\n";
}
