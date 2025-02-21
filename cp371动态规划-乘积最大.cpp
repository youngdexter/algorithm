//371动态规划-乘积最大
/*
the length of number(n):4
the number of *(k1):2
the number(s):1231
62
*/
#include <iostream>
#include <cstring>

using namespace std;

long long a[11][11],f[11][11];
long long s;

int n;//n位数
int k1;// * 乘号数
int i,j,k;//循环变量
int max(int a, int b) {
	return a > b ? a : b;
}

int main(int argc, char **argv) {
	
	printf("the length of number(n):");
	scanf("%d",&n);
	
	printf("the number of *(k1):");
	scanf("%d",&k1);
	
	printf("the number(s):");
	scanf("%lld",&s);
	
	for(i=n;i>=1;i--)
	{
		a[i][i] = s%10;
		s /= 10;
	}
	
	
	for(i=2;i<=n;i++)
		for(j=i-1;j>=1;j--)
			a[j][i]= a[j][i-1]*10 + a[i][i];
	
	for(i=1;i<=n;i++)
		f[i][0] = a[1][i];
		
	for(k=1;k<=k1;k++)	
		for(i=k+1;i<=n;i++)
			for(j=k;j<i;j++)
			{
				f[i][k]=max(f[i][k],f[j][k-1]*a[j+1][i]);
			}
			
	printf("%lld\n",f[n][k1]);
	
	return 0;
}