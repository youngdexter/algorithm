//cp212递推算法数塔问题
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
30
*/
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a[101][101];//数塔
	int n;//层数 
	int i,j;//循环变量
	
	cin>>n;
	for(i=1;i<=n;i++)  //行 
		for(j=1;j<=i;j++)//列
		{
			cin>>a[i][j]; 
		} 
	
	for(i=n-1;i>=1;i--)
		for(j=1;j<=i;j++)
		{
			if(a[i+1][j]>a[i+1][j+1])
				a[i][j] +=a[i+1][j];
			else
				a[i][j] +=a[i+1][j+1];
		}
	cout<<a[1][1]<<endl; 
	return 0;
}