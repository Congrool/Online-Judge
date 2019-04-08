#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n){
		int arr[n+1],b[n+1];
		for(int i = 0; i <= n; i++){
			cin >> arr[i];
			b[i] = n-i;
		}
		int cur;
		for(int i = 0; i <= n; i++)
			if(arr[i] != 0){
				cur = i;
				break;
			}
			
		if(arr[cur] == 1)
			cout << "x^" << b[cur];
		else if(arr[cur] == -1)
			cout << "-x^"<< b[cur];
		else
			cout << arr[cur] << "x^" << b[cur];
		for(int i = cur+1; i < n-1; i++){
			if(arr[i] == 0){
				continue;
			}
			else if(arr[i] > 0){
				cout << "+";
				if(arr[i] == 1)
					cout << "x^" << b[i];
				else
					cout << arr[i] << "x^" << b[i];
			}
			else if(arr[i] < 0){
				if(arr[i] == -1)
					cout << "-x^" << b[i];
				else
					cout << arr[i] << "x^" << b[i];
			}
		}
		if(arr[n-1] == 0)
			;
		else if(arr[n-1] > 0){
			cout << "+";
			if(arr[n-1] == 1)
				cout << "x";
			else
				cout << arr[n-1] <<"x";
		}
		else if(arr[n-1] < 0){
			if(arr[n-1] == -1)
				cout << "-x";
			else
				cout << arr[n-1] << "x";
		}
		
		
		if(arr[n] == 0)
			;
		else if(arr[n] > 0) {
			cout << "+" << arr[n];
		}
		else if(arr[n] < 0){
			cout << arr[n];
		}
		cout << endl;
	}
}
