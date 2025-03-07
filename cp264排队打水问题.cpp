//cp264排队打水问题
/*
person tap:4 2
2 6 4 5
2 4 5 6
23
*/
#include <string.h>
using namespace std;
void init(int a[], int person);
void show(int a[], int n);
void sort(int a[], int person);
void server(int person, int tap, int a[], int s[]);

void init(int a[], int person) {
	int i;
	for (i = 1; i <= person; i++) {
		cin >> a[i];
	}
}

void sort(int a[], int person) {
	int i, j, k, t;
	for (i = 1; i < person; i++) {
		k = i;
		for (j = i + 1; j <= person; j++) {
			if (a[j] < a[k])
				k = j;
		}
		if (k != i) {
			t = a[i];
			a[i] = a[k];
			a[k] = t;
		}
	}
}

void server(int person, int tap, int a[], int s[]) {
	int i, j;
	int minx = 0;

	memset(s, 0, sizeof(s));
	j = 0;

	for (i = 1; i <= person; i++) {
		j++;
		if (j == tap + 1)
			j = 1;
		s[j] += a[i];
		minx += s[j];
	}
	cout << minx;
}

void show(int a[], int n) {
	int i;
	for (i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


int main(int argc, char **argv) {
	int person, tap;
	const int n = 10;
	const int m = 2;
	int a[n + 1];
	int s[m + 1];

	cout << "person tap:";
	cin >> person >> tap;

	init(a, person);
	sort(a, person);
	show(a, person);

	server(person, tap, a, s);

	return 0;
}