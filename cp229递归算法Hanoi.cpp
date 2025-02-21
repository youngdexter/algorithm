//cp229µÝ¹éËã·¨Hanoi
/*
n:3
a->c
a->b
c->b
a->c
b->a
b->c
a->c
*/
#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c) {
	if (n == 0)
		return;
	hanoi(n - 1, a, c, b);
	cout << a << "->" << c << endl;
	hanoi(n - 1, b, a, c);
}
int main(int argc, char **argv) {
	int n;
	cout << "n:";
	cin >> n;
	hanoi(n, 'a', 'b', 'c');

	return 0;
}