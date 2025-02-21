//cp354多重背包问题1
/*
购买奖品的总数：5
拨款金额：1000
价格v[1]  价值w[1]  最大数量s[1]:80 20 4
价格v[2]  价值w[2]  最大数量s[2]:40 50 9
价格v[3]  价值w[3]  最大数量s[3]:30 50 7
价格v[4]  价值w[4]  最大数量s[4]:40 30 6
价格v[5]  价值w[5]  最大数量s[5]:20 20 1
f[m]:1040
*/
#include <iostream>
using namespace std; 
const int maxm=6001;//奖品的 最大价格 6000，0-6000 
const int maxn=6001;//奖品的最大种类6000，1-6000
int v[maxn];//每种奖品的价格
int w[maxn];//每种奖品的价值
int s[maxn];//每种奖品购买的最大数量
int f[maxm];//f[j] 表示总价不超过j的最优价值
			//f[j]=max(f[j],f[j-k*v[i]]+k*w[i] 
//5 1000
//80 20 4
//40 50 9
//30 50 7
//40 30 6
//20 20 1

int n;//希望购买奖品的总数 5 
int m;//拨款金额 1000 
int max(int x,int y)
{
	if(x<y)
		return y;
    return x;
}
int main(int argc, char** argv) {
	cout<<"购买奖品的总数：";
	cin>>n;
	cout<<"拨款金额：";
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cout<<"价格v["<<i<<"]  价值w["<<i<<"]  最大数量s["<<i<<"]:";
		cin>>v[i]>>w[i]>>s[i];
	}
	for(int i=1;i<=n;i++)//哪种商品 
	{
		for(int j=m;j>=0;j--)//金额
		{
			for(int k=0;k<=s[i];k++)
			{
				if(j-k*v[i]<0) break;
				f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
				//cout<<"f["<<j<<"]:"<<f[j]<<"i:"<<i<<"k:"<<k<<" ";
			} 
			//cout<<endl;
		} 
		
	}
	cout<<"f[m]:"<<f[m]<<endl;
	return 0;
}