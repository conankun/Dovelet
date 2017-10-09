#include<stdio.h>
int main() {
	int i,j;
	for(i=10;i<=100000;i++) {
		int size=1;
		while(size <= i) size*=10;
		size/=10;
		int j=0;
		int z=i;
		while(z>0) {
			j+=(z%10)*size;
			size/=10;
			z/=10;
		}
		int y = i+j;
		char s[1000]={0};
		int kj=0;
		while(y>0) {
			s[++kj]=y%10;
			y/=10;
		}
		int plus;
		if(kj%2==1) plus=2;
		else plus=1;
		int tr=1;
		for(j=1;j<=kj/2;j++) {
			if(s[j] != s[plus]) tr=0;
			plus+=2;
		}
		if(tr) printf("%d\n",i);
	}
}