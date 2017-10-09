#include<stdio.h>
int main() {
	int n,m;
	int i,j;
	scanf("%d%d",&m,&n);
	printf("%d\n",m*n*2);
	if(!(m%2==0&&n%2==1)) printf("1 1 1\n");
	//m,n이 하나라도 3일때 처리안함.단 데이터보니까 필요없을듯ㅋㅋㅋㅋ
	if(m%2==1&&n%2==1) {
		if(m != 3&& n != 3) {
			for(i=1;i<=n-3;i++) {
				if(i%2==1) {
					for(j=2;j<=m;j++) {
						printf("%d %d %d\n",j,i,0);
						printf("%d %d %d\n",j,i,1);
					}
				} else {
					printf("%d %d %d\n",m,i,0);
					printf("%d %d %d\n",m,i,1);
						for(j=m-1;j>=3;j--) {
							printf("%d %d %d\n",j,i,1);
							printf("%d %d %d\n",j,i,0);
						}
						printf("%d %d %d\n",2,i,1);
						printf("%d %d %d\n",2,i,0);
					}
				}
			for(i=2;i<=m-3;i++) {
				if(i%2==1) {
					printf("%d %d %d\n",i,n-1,1);
					printf("%d %d %d\n",i,n-1,0);
					printf("%d %d %d\n",i,n-2,0);
					printf("%d %d %d\n",i,n-2,1);
				} else {
					printf("%d %d %d\n",i,n-2,0);
					printf("%d %d %d\n",i,n-2,1);
					printf("%d %d %d\n",i,n-1,0);
					printf("%d %d %d\n",i,n-1,1);
				}
			}
			printf("%d %d %d\n",m-2,n-1,1);
			printf("%d %d %d\n",m-1,n-1,0);
			printf("%d %d %d\n",m-2,n-1,0);
			for(j=m-2;j<=m;j++) {
				printf("%d %d %d\n",j,n-2,0);
				printf("%d %d %d\n",j,n-2,1);
			}
			printf("%d %d %d\n",m,n-1,0);
			printf("%d %d %d\n",m-1,n-1,1);
			printf("%d %d %d\n",m,n-1,1);
			for(j=m;j>=1;j--) { //|
				printf("%d %d %d\n",j,n,1);	
				printf("%d %d %d\n",j,n,0);
			}
			for(j=n-1;j>=2;j--) {//<-
				printf("%d %d %d\n",1,j,1);	
				printf("%d %d %d\n",1,j,0);
			}
		}
	} else if(m%2==1&&n%2==0) {
		printf("1 1 0\n");
		for(i=2;i<=n;i++) {
			printf("%d %d %d\n",1,i,0);
			printf("%d %d %d\n",1,i,1);
		}
		for(i=n;i>=2;i--) {
			if(i%2==0) { //아래로
				printf("%d %d %d\n",2,i,0);
				printf("%d %d %d\n",2,i,1);
				if(n==2) continue;
				for(j=3;j<=m-1;j++) {
					printf("%d %d %d\n",j,i,0);
					printf("%d %d %d\n",j,i,1);
				}
				printf("%d %d %d\n",m,i,1);
				printf("%d %d %d\n",m,i,0);
			} else { //위로.
				for(j=m;j>=2;j--) {
					printf("%d %d %d\n",j,i,1);
					printf("%d %d %d\n",j,i,0);
				}
			}
		}
		for(i=m;i>=2;i--) {
			printf("%d %d %d\n",i,1,1);
			printf("%d %d %d\n",i,1,0);
		}
		return 0;
	} else if(m%2==0&&n%2==1) {
		printf("1 1 0\n1 1 1\n");
		for(i=2;i<=m;i++) {
			printf("%d %d %d\n",i,1,0);
			printf("%d %d %d\n",i,1,1);
		}
		for(i=m;i>=1;i--) {
			if(i%2==0) { //->
				printf("%d %d %d\n",i,2,1);
				printf("%d %d %d\n",i,2,0);
				if(n==2) continue;
				for(j=3;j<=n-1;j++) {
					printf("%d %d %d\n",i,j,0);
					printf("%d %d %d\n",i,j,1);
				}
				printf("%d %d %d\n",i,n,0);
				printf("%d %d %d\n",i,n,1);
			} else { //<-
				for(j=n;j>=2;j--) {
					printf("%d %d %d\n",i,j,1);
					printf("%d %d %d\n",i,j,0);
				}
			}
		}
		return 0;
	} else if((m%2==0&&n%2==0)) {
		for(i=2;i<=m;i++) {
			printf("%d %d %d\n",i,1,0);
			printf("%d %d %d\n",i,1,1);
		}
		for(i=m;i>=1;i--) {
			if(i%2==0) { //->
				printf("%d %d %d\n",i,2,1);
				printf("%d %d %d\n",i,2,0);
				if(n==2) continue;
				for(j=3;j<=n-1;j++) {
					printf("%d %d %d\n",i,j,0);
					printf("%d %d %d\n",i,j,1);
				}
				printf("%d %d %d\n",i,n,1);
				printf("%d %d %d\n",i,n,0);
			} else { //<-
				for(j=n;j>=2;j--) {
					printf("%d %d %d\n",i,j,1);
					printf("%d %d %d\n",i,j,0);
				}
			}
		}
	}
	printf("1 1 0");
}
