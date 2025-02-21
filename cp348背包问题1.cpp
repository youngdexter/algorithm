//cp348背包问题1
/*
背包的容量（重量）：10
物品的数量：4
重量 w[1] 价值 c[1]:2 1
重量 w[2] 价值 c[2]:3 3
重量 w[3] 价值 c[3]:4 5
重量 w[4] 价值 c[4]:7 9
f[1][10]:1 f[1][9]:1 f[1][8]:1 f[1][7]:1 f[1][6]:1 f[1][5]:1 f[1][4]:1 f[1][3]:1 f[1][2]:1 f[1][1]:0
f[2][10]:4 f[2][9]:4 f[2][8]:4 f[2][7]:4 f[2][6]:4 f[2][5]:4 f[2][4]:3 f[2][3]:3 f[2][2]:1 f[2][1]:0
f[3][10]:9 f[3][9]:9 f[3][8]:8 f[3][7]:8 f[3][6]:6 f[3][5]:5 f[3][4]:5 f[3][3]:3 f[3][2]:1 f[3][1]:0
f[4][10]:12 f[4][9]:10 f[4][8]:9 f[4][7]:9 f[4][6]:6 f[4][5]:5 f[4][4]:5 f[4][3]:3 f[4][2]:1 f[4][1]:0
f[n][m]:12
*/
#include <iostream>
using namespace std;
const int maxm = 201; //背包的最大容量200，应用下标1-200
const int maxn = 31; //物品的最大数量30，应用下标1-30
int w[maxn];//每件物品重量
int c[maxn];//每件物品的价值
int f[maxn][maxm];//f[i][v] 前i件物品 ，总重量不超过v的最优价值

//f[i][v]=max{f[i-1][v],f[i-1][v-w[i]]+c[i]}

int m;//背包容量 10
int n;//物品数量 4

int max(int x, int y) {
	if (x < y)
		return y;
	else
		return x;
}

int main(int argc, char **argv) {
	int i, v;
	cout << "背包的容量（重量）：";
	cin >> m;
	cout << "物品的数量：";
	cin >> n;

	for (i = 1; i <= n; i++) {
		cout << "重量 w[" << i << "] 价值 c[" << i << "]:";
		cin >> w[i] >> c[i];
	}

	for (i = 1; i <= n; i++) { //数量
		for (v = m; v >= 1; v--) { //重量
			if (w[i] <= v) {
				f[i][v] = max(f[i - 1][v], f[i - 1][v - w[i]] + c[i]);
			} else {
				f[i][v] = f[i - 1][v];
			}
			cout << "f[" << i << "][" << v << "]:" << f[i][v] << " ";
		}
		cout << endl;
	}
	cout << "f[n][m]:" << f[n][m] << endl;
	return 0;
}