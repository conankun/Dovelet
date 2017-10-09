#include<stdio.h>
int R,C,A,B;
int a[1000][1000];
int main() {
	//R*A,C*B
	scanf("%d%d%d%d",&R,&C,&A,&B);
	int i,j,k,mode=1;
	int cnt=0;
	for(i=1;i<=R*A;i+=A) {
		cnt++;
		if(cnt%2==1) mode=0;
		else mode=1;
		for(j=1;j<=C*B;j++) {
			if(mode==0) {
				for(k=i;k<i+A;k++) {
					a[k][j]=1;
				}
			} else {
				for(k=i;k<i+A;k++) {
					a[k][j]=-1;
				}
			}
			if(j%B==0) mode=(mode+1)%2;
		}
	}
	for(i=1;i<=R*A;i++,printf("\n")) {
		for(j=1;j<=C*B;j++) {
			if(a[i][j]==1) printf("X");
			else if(a[i][j]==-1) printf(".");
		}
	}
}