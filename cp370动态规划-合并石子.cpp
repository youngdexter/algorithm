//370动态规划-合并石子
//https://blog.csdn.net/weixin_51147313/article/details/143828610
/*
the number of stone(n):7
1 stone:13
2 stone:7
3 stone:8
4 stone:16
5 stone:21
6 stone:4
7 stone:18
239
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int s[101]; //前i堆石头的数量总和
int n;  //共n堆石子
int i, j, k; //循环变量
int x; //分别读取每堆石子数量

int f[101][101]; //把第i堆到第j堆的石头合并成一堆的最优值

int min(int a, int b) {
	return a > b ? b : a;
}

int main(int argc, char **argv) {
	printf("the number of stone(n):");
	scanf("%d", &n);

	s[0] = 0; //前0堆石头的数量总和 0

	for (i = 1; i <= n; i++) {
		printf("%d stone:", i);
		scanf("%d", &x);
		s[i] = s[i - 1] + x;
	}

	//memset(f,127,sizeof(f));
	//4个字节整数，每个字节赋值 01111111011111110111111101111111
	//赋值127是很大正数，想不超范围，可/3；//通过分析，和实际验证，可以不/3
	//cout<<f[1][2];
	memset(f, 127 / 3, sizeof(f));
	for (i = 1; i <= n; i++)
		f[i][i] = 0;

	for (i = n - 1; i >= 1; i--)
		for (j = i + 1; j <= n; j++)

			for (k = i; k <= j - 1; k++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
			}

	printf("%d\n", f[1][n]);
	return 0;
}