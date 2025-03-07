//cp181高精度加法
/*
a:856
b:255
1111
*/
#include <bits/stdc++.h>
using namespace std;
int a1[200],b1[200],c[200];
int main(int argc, char** argv) {
	char a[200],b[200];
	cout<<"a:";
	cin>>a;
	cout<<"b:";
	cin>>b;
	
	int lena=strlen(a);
	int lenb=strlen(b);
	for(int i=1;i<=lena;i++)
		a1[i]=a[lena-i]-'0';
	for(int i=1;i<=lenb;i++)
		b1[i]=b[lenb-i]-'0';

	int x=0;
	int lenc=1;
	while(lenc<=lena||lenc<=lenb)
	{
		c[lenc]=a1[lenc]+b1[lenc]+x;
		x=c[lenc]/10;
		c[lenc]=c[lenc]%10;
		lenc++;
	}
	
	c[lenc]=x;
	while(c[lenc]==0&&lenc>1)
	{
		lenc--;
	}
	for(int i =lenc;i>=1;i--)
		cout<<c[i];
	cout<<endl;


	return 0;
}