//cp352完全背包问题2
/*
背包的容量（重量）：10
物品的数量：4
重量 w[1] 价值 c[1] :2 1
重量 w[2] 价值 c[2] :3 3
重量 w[3] 价值 c[3] :4 5
重量 w[4] 价值 c[4] :7 9
f[2]=1 f[3]=1 f[4]=2 f[5]=2 f[6]=3 f[7]=3 f[8]=4 f[9]=4 f[10]=5
f[3]=3 f[4]=3 f[5]=4 f[6]=6 f[7]=6 f[8]=7 f[9]=9 f[10]=9
f[4]=5 f[5]=5 f[6]=6 f[7]=8 f[8]=10 f[9]=10 f[10]=11
f[7]=9 f[8]=10 f[9]=10 f[10]=12
f[m]:12
*/
#include <iostream>
using namespace std;
const int maxm = 201; //背包的最大容量200，应用下标1-200
const int maxn = 31; //物品的最大数量30，应用下标1-30
int w[maxn];//每件物品重量
int c[maxn];//每件物品的价值

int f[maxm];//f[v] 总重量不超过v的最优价值
//f[v]=max(f[v],f[v-w[i]]+c[i]
int m;//背包容量 10
int n;//物品数量 4

int main(int argc, char **argv) {
	int i, v;
	cout << "背包的容量（重量）：";
	cin >> m;
	cout << "物品的数量：";
	cin >> n;

	for (i = 1; i <= n; i++) {
		cout << "重量 w[" << i << "] 价值 c[" << i << "] :";
		cin >> w[i] >> c[i];
	}

	for (i = 1; i <= n; i++) { //数量
		for (v = w[i]; v <= m; v++) { //重量
			if (f[v - w[i]] + c[i] > f[v]) {
				f[v] = f[v - w[i]] + c[i];
			}
			cout << "f[" << v << "]=" << f[v] << " ";
		}
		cout << endl;
	}
	cout << "f[m]:" << f[m] << endl;
	return 0;
}