//cp363背包问题的方案总数-货币系统2
/*
组成面值:10
货币种类数:3
货币面值 a[1]:1
货币面值 a[2]:2
货币面值 a[3]:5
f[m]:10
*/
#include <iostream>
using namespace std;

int m; //组成面值 10
int n; //货币面值数 3
int a[11]; //货币面值

long long f[101];  //f[j]表示面值为j的最大方案数

int i, j, k; //循环变量

int main(int argc, char **argv) {

	cout << "组成面值:";
	cin >> m;
	cout << "货币种类数:";
	cin >> n;


	for (i = 1; i <= n; i++) {
		cout << "货币面值 a[" << i << "]:";
		cin >> a[i];
	}

	f[0] = 1;
	for (i = 1; i <= n; i++)  //n种货币
		for (j = a[i]; j <= m ; j++) //面值数
			f[j] += f[j - a[i]];

	cout << "f[m]:" << f[m] << endl;
	return 0;
}