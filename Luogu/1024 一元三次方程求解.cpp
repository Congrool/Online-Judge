#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
double a, b, c, d;
double f(double x) {
	return a * x*x*x + b * x*x + c * x + d;
}
double fd(double x) {
	return 3 * a*x*x + 2 * b*x + c;
}
double fdd(double x) {
	return 6 * a*x + 2 * b;
}
double solve(double lo, double hi, double (*fun)(double x)){
	double st = lo, te = hi, mid = 101;
	if (fun(st) == 0)  st += 0.002;
	if (fun(te) == 0)  te -= 0.002;
	int times = 100;
	for (int i = 0; i < times; i++) {
		double ans1 = fun(st), ans2 = fun(te);
		mid = st + (te - st) / 2;
		if (fun(mid)*fun(st) < 0)  te = mid;
		else if (fun(mid)*fun(te) < 0) st = mid;
	}
	return mid;
}

int main() {
	while (cin >> a >> b >> c >> d) {
		double lo = -100, hi = 100;
		double fdd0 = solve(lo, hi, fdd);
		double fd1 = solve(lo, fdd0, fd), fd2 = solve(fdd0, hi, fd);
		double x1 = solve(lo, fd1, f), x2 = solve(fd1, fd2, f), x3 = solve(fd2, hi, f);
		printf("%.2f %.2f %.2f\n", x1, x2, x3);
	}
}