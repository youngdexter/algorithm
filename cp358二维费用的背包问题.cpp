//358二维费用的背包问题
/*
v:5
u:60
k:5
a[1] b[1] c[1]:3 36 120
a[2] b[2] c[2]:10 25 129
a[3] b[3] c[3]:5 50 250
a[4] b[4] c[4]:1 45 130
a[5] b[5] c[5]:4 20 119
249
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int v; //氧气需求量
int u; //氮气需求量
int k; //物品数量

int a[101]; //第i个气缸氧气的容量
int b[101]; //第i个气缸氮气的容量
int c[101]; //第i个气缸的重量
//物品数量（气缸数量） n<=100
int f[101][101]; //f[j][i] 氧气>=j 氮气>=i 时，最小重量
//背包容量（氧气容量<=100 氮气容量<=100）

int main(int argc, char **argv) {
	memset(f,127,sizeof(f)); //初始化一个很大的整数  01111111 01111111 01111111 01111111
	//最大的整数  01111111 11111111 11111111 11111111
	f[0][0] = 0;
	printf("v:");
	scanf("%d",&v);
	printf("u:");
	scanf("%d",&u);
	printf("k:");
	scanf("%d",&k);
	
	for(int i =1;i<=k;i++)
	{
		printf("a[%d] b[%d] c[%d]:",i,i,i);
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	
	for(int i=1;i<=k;i++)
		for(int j=v;j>=0;j--) //v 氧气需求量
			for(int l=u;l>=0;l--) //u 氮气需求量
			{
				int t1=j+a[i],t2=l+b[i];
				if(t1>v) t1=v; //需求是固定的，提供的数量要超出才可以，
				if(t2>u) t2=u; //为了计算，可以替换，  t1->v       t2->u
				if(f[t1][t2]>f[j][l]+c[i])
					f[t1][t2]=f[j][l]+c[i];
			}
	
	printf("%d",f[v][u]);
	return 0;
}