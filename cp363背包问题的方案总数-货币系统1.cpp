//cp363��������ķ�������-����ϵͳ1
/*
�����ֵ:10
����������:3
������ֵ a[1]:1
������ֵ a[2]:2
������ֵ a[3]:5
f[m]:10
*/
#include <iostream>
using namespace std;

int m; //�����ֵ 10
int n; //������ֵ�� 3
int a[11]; //������ֵ

long long f[101];  //f[j]��ʾ��ֵΪj����󷽰���

int i,j,k; //ѭ������

int main(int argc, char **argv) {

	cout << "�����ֵ:";
	cin >> m;
	cout << "����������:";
	cin >> n;


	for (i = 1; i <= n; i++) {
		cout << "������ֵ a[" << i << "]:";
		cin >> a[i];
	}

	f[0]=1;
	for (i = 1; i <= n; i++)  //n�ֻ���
		for (j = m; j >= a[i]; j--) //��ֵ��
			for (k = 1; k <= j/a[i]; k++) 
				f[j]=f[j]+f[j-k*a[i]];

	cout << "f[m]:" << f[m] << endl;
	return 0;
}