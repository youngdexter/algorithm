//cp354���ر�������1
/*
����Ʒ��������5
�����1000
�۸�v[1]  ��ֵw[1]  �������s[1]:80 20 4
�۸�v[2]  ��ֵw[2]  �������s[2]:40 50 9
�۸�v[3]  ��ֵw[3]  �������s[3]:30 50 7
�۸�v[4]  ��ֵw[4]  �������s[4]:40 30 6
�۸�v[5]  ��ֵw[5]  �������s[5]:20 20 1
f[m]:1040
*/
#include <iostream>
using namespace std; 
const int maxm=6001;//��Ʒ�� ���۸� 6000��0-6000 
const int maxn=6001;//��Ʒ���������6000��1-6000
int v[maxn];//ÿ�ֽ�Ʒ�ļ۸�
int w[maxn];//ÿ�ֽ�Ʒ�ļ�ֵ
int s[maxn];//ÿ�ֽ�Ʒ������������
int f[maxm];//f[j] ��ʾ�ܼ۲�����j�����ż�ֵ
			//f[j]=max(f[j],f[j-k*v[i]]+k*w[i] 
//5 1000
//80 20 4
//40 50 9
//30 50 7
//40 30 6
//20 20 1

int n;//ϣ������Ʒ������ 5 
int m;//������ 1000 
int max(int x,int y)
{
	if(x<y)
		return y;
    return x;
}
int main(int argc, char** argv) {
	cout<<"����Ʒ��������";
	cin>>n;
	cout<<"�����";
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cout<<"�۸�v["<<i<<"]  ��ֵw["<<i<<"]  �������s["<<i<<"]:";
		cin>>v[i]>>w[i]>>s[i];
	}
	for(int i=1;i<=n;i++)//������Ʒ 
	{
		for(int j=m;j>=0;j--)//���
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