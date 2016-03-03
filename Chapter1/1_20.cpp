//Algorithm Design 1.20
//Pn(x) = i = 0 to n (ai * x^i)
#include <iostream>

using namespace std;
const int ARRSIZE = 20;
int compute(int x, int n, int *a)
{
	int p = 0, temp = 1;
	for(int i = 0; i <= n; ++i)
		cin >> a[i];
	for(int j = 0; j <= n; ++j)
	{
		p += a[j] * temp;
	}
	return p;
}

int main(int argc, char **argv)
{
	int x, n, *arr;
	cout << "Input X: " << endl;
	cin >> x;
	cout << "Input N: " << endl;
	cin >> n;
	cout << "Input a[1 .. n]: " << endl;
	arr = new int[ARRSIZE];
	cout << compute(x, n, arr) << endl;
	
	return 0;
}
