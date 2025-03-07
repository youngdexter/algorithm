//cp248八皇后问题
/*
sum=1
1 5 8 6 3 7 2 4
sum=2
1 6 8 3 7 4 2 5
sum=3
1 7 4 6 8 2 5 3
sum=4
1 7 5 8 2 4 6 3
sum=5
2 4 6 8 3 1 7 5
.....
*/
#include <iostream>
using namespace std;
#include <cmath>

bool b[9] = {0}, c[17] = {0}, d[17] = {0};
int sum = 0, a[9];

void search(int t);
void print();

int main(int argc, char **argv) {
	search(1);

	return 0;
}

void search(int i) {//选第i行的位置
	int j;
	for (j = 1; j <= 8; j++) {
		if ((!b[j]) && (!c[i + j]) && (!d[i - j + 7])) {
			a[i] = j;
			b[j] = 1;
			c[i + j] = 1;
			d[i - j + 7] = 1;
			if (i == 8) {
				print();
			} else
				search(i + 1);
			b[j] = 0;
			c[i + j] = 0;
			d[i - j + 7] = 0;
		}
	}
}

void print() {
	int i;
	sum++;
	cout << "sum=" << sum << endl;

	for (int i = 1; i <= 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}