#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int a[10];
	scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
	sort(a+1,a+5);
	printf("%d",a[1]*a[3]);
}