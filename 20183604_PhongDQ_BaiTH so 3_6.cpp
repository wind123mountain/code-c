#include <iostream>
using namespace std;

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
int gcd2(int a, int b){
	int temp = 0;
	int x = a;
	int y = b;
	while(y != 0){
		temp = x;
		x = y;
		y = temp%y;
	}
	return x;
}
int main() {
	int a, b;
	cout<<"Ho Va Ten: Dao Quoc Phong\nMSSV: 20183604\n\n";
	cout<<"input:\n";
	cin >> a >> b;
	cout<<"output:\n";
	cout<<"de quy:\n" << gcd(a, b) << endl <<"khu de quy:\n"<< gcd2(a, b);
	return 0;
}
