#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int main() {
	int a, b, c, d, e, f;
	scanf("%d:%d:%d", &a, &b, &c);
	scanf("%d:%d:%d", &d, &e, &f);
	int t1 = a * 3600 + b * 60 + c;
	int t2 = d * 3600 + e * 60 + f;
	if (t1 >= t2) {
		t2 += 24 * 3600;
	}
	int t3 = t2 - t1;
	printf("%02d:", t3 / 3600);
	t3 -= ((int)(t3 / 3600)) * 3600;
	printf("%02d:", t3 / 60);
	t3 -= ((int)(t3 / 60)) * 60;
	printf("%02d", t3);

}