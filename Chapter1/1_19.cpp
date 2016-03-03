//Algorithm Design 1.19

#include <iostream>

const int ARRSIZE = 20;
const int MAXINT  = 65535;

using namespace std;

//a[i - 1] = i! * 2 ^ i 

void function(int n, int *a)
{
	string errResOverFlow = "ResultOverFlow";
	if(n > ARRSIZE)
		throw errResOverFlow;
	for(int i = 1; i <= n; ++i)
	{
		int res = 1;
		for(int j = i; j > 0; --j)
		{
			res *= 2 * j;
		}
		if(res > MAXINT)
			throw errResOverFlow;
		a[i -1] = res;
	}
	for(int i = 0; i < n; ++i)
		cout << a[i] << " " <<endl;
}
int main(int argc, char **argv)
{
	int N;
	int a[ARRSIZE];
	cout << "Please Input N" << endl;
	cin >> N;
	try
	{
		function(N, a);
	}
	catch(string &estr)
	{
		cout << estr <<endl;
	}
	return 0;
}



