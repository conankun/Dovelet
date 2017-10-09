#include<stdio.h>
#include<stdlib.h>
int euclid(int a,int b) {
	int c;
	do {
		c=a%b;
		a=b;
		b=c;
	}while(c!=0);
	return a;
}
int A,B;
int main() {
	scanf("%d%d",&A,&B);
	int D=euclid(A,B);
	A/=D;B/=D;
	//ax+by=1
	int i;
	int x,y;
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
		if(x+i==-1) {
			i=i;
		}
		if((1-(x+i)*A)%B==0) {
			int xx=x+i,yy=(1-(x+i)*A)/B;
			if(!tr || (abs(XXX)+abs(YYY) > abs(xx)+abs(yy))) {
				XXX=xx,YYY=yy;
			}
		}
	}
	printf("%d %d %d",XXX,YYY,D);
}