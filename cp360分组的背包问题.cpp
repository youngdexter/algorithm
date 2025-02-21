//cp360分组的背包问题
/*
背包容量:10
物品数量:6
物品最大组号:3
重量 w[1] 价值 c[1] 组号 p:2 1 1
重量 w[2] 价值 c[2] 组号 p:3 3 1
重量 w[3] 价值 c[3] 组号 p:4 8 2
重量 w[4] 价值 c[4] 组号 p:6 9 2
重量 w[5] 价值 c[5] 组号 p:2 8 3
重量 w[6] 价值 c[6] 组号 p:3 9 3
f[v]:20
*/
#include <iostream>
using namespace std;

int v; //背包容量 10
int n; //物品数量 6
int maxP; //物品最大组号 3
int p; //物品组号

int w[31];  //w[31]第i件物品重量
int c[31];  //c[31]第i件物品价值
int a[11][32];	//a[p][p[0]] 表示p组的第p[0]件物品的编号 = i
int f[201];  //f[j]表示重量不超过j的最优价值

int i, j; //循环变量
int main(int argc, char **argv) {

	cout << "背包容量:";
	cin >> v;
	cout << "物品数量:";
	cin >> n;
	cout << "物品最大组号:";
	cin >> maxP;

	for (i = 1; i <= n; i++) {
		cout << "重量 w[" << i << "] 价值 c[" << i << "] 组号 p:";
		cin >> w[i] >> c[i] >> p;
		a[p][++a[p][0]] = i; //a[p][0]：p组计数器  i:物品编号
	}

	int t;

	for (p = 1; p <= maxP; p++)  //组号
		for (j = v; j >= 0; j--) //容量 j>=0 因为对于p组 组内物品若干，重量不唯一，所以>=0

			for (i = 1; i <= a[p][0]; i++) { //重量
				t = a[p][i]; // p组 第i件 物品编号
				if (j >= w[t]) {
					if (f[j] < f[j - w[t]] + c[t])
						f[j] = f[j - w[t]] + c[t];
				}
			}

	cout << "f[v]:" << f[v] << endl;
	return 0;
}