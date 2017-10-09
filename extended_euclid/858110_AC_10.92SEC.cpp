#include<stdio.h>
#include<stdlib.h>
long long euclid(long long a,long long b) {
	int c;
	do {
		c=a%b;
		a=b;
		b=c;
	}while(c!=0);
	return a;
}
long long A,B;
int main() {
	scanf("%lld%lld",&A,&B);
	long long D=euclid(A,B);
	A/=D;B/=D;
	//ax+by=1
	long long i;
	long long x,y;
	for(i=-10000000;i<=100000000;i++) {
		if((1-A*i)%B==0) {
			x=i;y=(1-A*i)/B;
			break;
		}
	}
	//(x+p)a+(y+q)b=1
	bool tr=false;
	int XXX=0,YYY=0;
	for(i=-10000000;i<=10000000;i++) {
		if(x+i==-2) {
			i=i;
		}
		if((1-(x+i)*A)%B==0) {
			long long xx=x+i,yy=(1-(x+i)*A)/B;
			if(!tr || (abs(XXX)+abs(YYY) > abs(xx)+abs(yy))) {
				XXX=xx,YYY=yy;tr=true;
			}
		}
	}
	printf("%d %d %d",XXX,YYY,D);
}