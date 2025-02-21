//356混合背包问题
/*
m:10
n:3
w[1] c[1] p[1]:2 1 0
w[2] c[2] p[2]:3 3 1
w[3] c[3] p[3]:4 5 4
11
*/
#include <iostream>
#include <cstdio>

using namespace std;

int m; //背包容量
int n; //物品数量

int w[31]; //物品的重量
int c[31]; //物品的价值
int p[31]; //物品的数量 0 不限数量（完全背包） 1 限1个（01背包）  4 上限4个（多重背包）
//物品数量 n<=30
int f[201]; //f[j]表示总价不超过j的最优价值 f[j]=max(f[j],f[j-w[i]]+c[i])

//背包容量m<=200
int max(int x, int y) {
	if (x < y)
		return y;
	else
		return x;
}

int main(int argc, char **argv) {
	printf("m:");
	scanf("%d", &m);
	printf("n:");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		printf("w[%d] c[%d] p[%d]:", i, i, i);
		scanf("%d%d%d", &w[i], &c[i], &p[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (p[i] == 0) { //完全背包
			for (int j = w[i]; j <= m; j++)
				f[j] = max(f[j], f[j - w[i]] + c[i]);
		} else {
			for (int k = 1; k <= p[i]; k++) //01背包或多重背包
				for (int j = m; j >= w[i]; j--)
					f[j] = max(f[j], f[j - w[i]] + c[i]);
		}
	}

	printf("%d", f[m]);
	return 0;
}