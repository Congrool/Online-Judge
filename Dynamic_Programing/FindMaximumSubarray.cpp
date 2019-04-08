#include<iostream>
#include<climits>
#include<ctime>
using namespace std;
int FMCS(int a[], int low, int mid, int hi)
{
	int leftSum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= low; i--)
	{
		sum += a[i];
		if (sum > leftSum)
			leftSum = sum;
	}
	int rightSum = INT_MIN;
	sum = 0;
	for (int i = mid + 1; i <= hi; i++)
	{
		sum += a[i];
		if (sum > rightSum)
			rightSum = sum;
	}
	return rightSum + leftSum;
}

int FMS(int a[], int low, int hi)
{
	if (hi == low)
		return a[hi];
	int mid = (low + hi) / 2;
	int leftsum = FMS(a, low, mid);
	int rightsum = FMS(a, mid + 1, hi);
	int crossingsum = FMCS(a, low, mid, hi);
	if (leftsum > rightsum && leftsum > crossingsum)
		return leftsum;
	if (rightsum > leftsum && rightsum > crossingsum)
		return rightsum;
	else
		return crossingsum;
}

int main()
{
	time_t now;
	time(&now);
	srand((unsigned)time(NULL));
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = 10 - (rand() % 20);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << FMS(a, 0, 9);
}
