#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10];
int main() {
	int i,j,k;
	for(i=1;i<=3;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+3);
	for(i=2000;i>=1;i--) {
		int b[10];
		for(j=1;j<=3;j++) b[j]=a[j];
		b[4]=i;
		sort(b+1,b+5);
		int c = b[2]-b[1];
		for(j=3;j<=4;j++) {
			if(b[j]-b[j-1] != c) {
				c=-1;
				break;
			}
		}
		if(c != -1) {
			printf("%d",i);
			break;
		}
	}
}