/*
  int范围内，支持+，-，*，/（整除）运算
  不知道为什么在oj上一直runtime error
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<map>
#include<stack> 
using namespace std;
map<char, int> priority;
void getvalue(stack<int> &num, stack<char> &opera) {
	char op = opera.top();
	if(op == '\0')
		return;
	opera.pop();
	int num1 = num.top();
	num.pop();
	int num2 = num.top();
	num.pop();
	int res = 0;
	switch (op) {
	case '+':
		res = num2 + num1;
		break;
	case '-':
		res = num2 - num1;
		break;
	case '*':
		res = num2 * num1;
		break;
	case '/':
		res = num2 / num1;
		break;
	}
	num.push(res);
}
int todigit(char num) {
	return num - '0';
}
int getnum(string expr, int &pos) {
	int res = 0, jin = 1;
	stack<int> temp;
	for (; pos < expr.length()&&isdigit(expr[pos]); pos++) {
		temp.push(todigit(expr[pos]));
	}
	while (!temp.empty()) {
		res += temp.top()*jin;
		jin *= 10;
		temp.pop();
	}
	return res;
}
void oper_push(char &op, char &pre_op,stack<int> &num, stack<char> &opera) {
	while (priority[pre_op] >= priority[op] && pre_op != '(') {
		getvalue(num, opera);
		pre_op = opera.top();
	}
	opera.push(op);
	pre_op = op;
}
int valueOfExpression(string expr) {
	stack<int> num;
	stack<char> opera;
	opera.push('\0');
	int cur_num;
	char op, pre_op = '\0';
	for(int i = 0; i < expr.length();){
		if (isdigit(expr[i])) {
			cur_num = getnum(expr, i);
			num.push(cur_num);
		}
		while(i < expr.length() && !isdigit(expr[i])){
			op = expr[i];
			switch (op) {
			case '(':
				opera.push(op);
				pre_op = op;
				break;
			case ')':
				while (pre_op != '(') {
					getvalue(num, opera);
					pre_op = opera.top();
				}
				opera.pop();
				pre_op = opera.top();
				break;
			default:
				oper_push(op, pre_op, num, opera);
			}
			i++;
		}
	}
	getvalue(num, opera);
	return num.top();
}
int main()
{
	priority['\0'] = -1;
	priority['+'] = 1;
	priority['-'] = 1;
	priority['*'] = 2;
	priority['/'] = 2;
	priority['('] = 3;
	string expr;
	while (cin >> expr) {
		cout << valueOfExpression(expr) << endl;
	}
}
