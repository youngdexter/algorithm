//多重背包问题二进制优化 -> 0 1背包
/*
奖品种数：5
拨款金额：1000
价格1  价值1  最大数量1:80 20 4
价格2  价值2  最大数量2:40 50 9
价格3  价值3  最大数量3:30 50 7
价格4  价值4  最大数量4:40 30 6
价格5  价值5  最大数量5:20 20 1
f[m]:1040
*/
#include <iostream>
using namespace std;
const int maxm = 6001; //奖品的 最大价格 6000，0-6000
const int maxn = 10001; //奖品的最大种类10000，1-10000（二进制优化，商品数增多）
int v[maxn];//每种奖品的价格
int w[maxn];//每种奖品的价值
//int s[maxn];//二进制优化后，新的每种奖品购买的最大数量为1，无需此数组变量
int f[maxm];//f[j] 表示总价不超过j的最优价值
//f[j]=max(f[j],f[j-v[i]]+w[i]  //新的每种奖品购买的最大数量为1


int n;//希望购买奖品的总数 5
int m;//拨款金额 1000
int n1;//二进制化后，希望购买奖品的总数

int max(int x, int y) {
	return x > y ? x : y;
}
int main(int argc, char **argv) {
	cout << "奖品种数：";
	cin >> n;
	cout << "拨款金额：";
	cin >> m;

	int x, y, s, t;
	n1 = 0; //构建新的奖品，初始值为0

	for (int i = 1; i <= n; i++) {
		cout << "价格" << i << "  价值" << i << "  最大数量" << i << ":";
		cin >> x >> y >> s;
		t = 1;
		while(s>=t)
		{
			v[++n1] = x*t;
			w[n1]=y*t;
			s-=t;
			t=t*2;
		}
		if(s)
		{
			v[++n1] = x*s;
			w[n1]=y*s;	
		}

	}

	for (int i = 1; i <= n1; i++) { //哪种奖品
		for (int j = m; j >= v[i]; j--) { //金额
			f[j] = max(f[j], f[j - v[i]] + w[i]);
			//cout << "f[" << j << "]:" << f[j] << " ";
			//if(j%10==0)
			//	cout << endl;
		}
		//cout << endl;
	}
	cout << "f[m]:" << f[m] << endl;
	return 0;
}