//cp244搜索与回溯素数环（以4个数为例）
/*
（const int n = 4）
<1>1 2 3 4
<2>1 4 3 2
<3>2 1 4 3
<4>2 3 4 1
<5>3 2 1 4
<6>3 4 1 2

<1> <4> <6> 一样  1 2 3 4
<2> <3> <5> 一样  4 3 2 1
1234 4321 本质上也一样
（const int n = 20）
输出太多
*/
#include <iostream>
using namespace std;
#include <cmath>
const int n = 4;

int a[n + 1] = {0};  //a[i] 第i次选出的数字
bool b[n + 1] = {0}; //b[i] 数字i是否被选过，0 没被选过，1 被选过
int total = 0;  //总方案数
void search(int t);
void print();
bool pd(int, int);

int main(int argc, char **argv) {
	search(1);

	return 0;
}

void search(int t) {
	int i;
	for (i = 1; i <= n; i++) {
		if ((!b[i]) && pd(a[t - 1], i)) {
			a[t] = i;
			b[i] = 1;
			if (t == n) {
				if (pd(a[n], a[1])) {
					print();
					//break;
				}
			} else
				search(t + 1);
			b[i] = 0;
		}
	}
}

void print() {
	int j;
	total++;
	cout << "<" << total << ">";

	for (j = 1; j <= n; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
}

bool pd(int x, int y) {
	int k = 2, i = x + y;
	while (k <= sqrt(i) && i % k != 0) {
		k++;
	}
	if (k > sqrt(i))
		return 1;
	else
		return 0;
}