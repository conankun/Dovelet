#include<stdio.h>
int M,T,U,F,D;
int main() {
	scanf("%d%d%d%d%d",&M,&T,&U,&F,&D);
	int i;
	int cnt=0;
	for(i=1;i<=T;i++) {
		char c;
		scanf("\n%c\n",&c);
		if(c == 'u' || c == 'd') {
			if(U+D <= M) {
				cnt++;
				M-=U+D;
			} else break;
		} else {
			if(F*2 <= M) {
				cnt++;
				M-=F*2;
			} else break;
		}
	}
	printf("%d",cnt);
}