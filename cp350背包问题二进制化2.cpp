//cp350������������ƻ�2
/*
��������������������10
��Ʒ��������4
w[1]  c[1]:2 1
w[2]  c[2]:3 3
w[3]  c[3]:4 5
w[4]  c[4]:7 9
f[10]=1 f[9]=1 f[8]=1 f[7]=1 f[6]=1 f[5]=1 f[4]=1 f[3]=1 f[2]=1
f[10]=4 f[9]=4 f[8]=4 f[7]=4 f[6]=4 f[5]=4 f[4]=3 f[3]=3
f[10]=9 f[9]=9 f[8]=8 f[7]=8 f[6]=6 f[5]=5 f[4]=5
f[10]=12 f[9]=10 f[8]=9 f[7]=9
f[m]:12
*/
#include <iostream>
using namespace std; 
const int maxm=201;//�������������200��Ӧ���±�1-200 
const int maxn=31;//��Ʒ���������30��Ӧ���±�1-30
int w[maxn];//ÿ����Ʒ����
int c[maxn];//ÿ����Ʒ�ļ�ֵ

int f[maxm];//f[v] ������������v�����ż�ֵ 
int m;//�������� 10
int n;//��Ʒ���� 4

int main(int argc, char** argv) {
	int i,v;
	cout<<"��������������������";
	cin>>m;
	cout<<"��Ʒ��������";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout << "���� w[" << i << "] ��ֵ c[" << i << "] :";
		cin>>w[i]>>c[i];
	}
	for(i=1;i<=n;i++)//���� 
	{
		for(v=m;v>=w[i];v--)//����
		{
			if(f[v-w[i]]+c[i]>f[v])
			{
				f[v]=f[v-w[i]]+c[i];
			} 
			cout<<"f["<<v<<"]="<<f[v]<<" ";
		} 
		cout<<endl;
	}
	cout<<"f[m]:"<<f[m]<<endl;
	return 0;
}