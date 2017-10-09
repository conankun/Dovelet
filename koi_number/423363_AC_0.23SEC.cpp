#include<stdio.h>
#include<math.h>
long long n;
int bin[10000];
int ind;
void makebin(long long m) {
	while(m > 0) {
		bin[++ind]=m%2;
		m/=2;
	}
}
void problem1() {
	int i,j;
	int bin2[100]={0};
	for(i=1;i<=ind;i++) bin2[i]=bin[i];
	bool t=false;
	int inds=ind;
	for(i=1;i<=ind-1;i++) {
		for(j=i-1;j>=1;j--) {
			if(bin2[i]==0&&bin[j]==1) {
				inds=i;
				bin2[i]=1;
				bin2[j]=0;
				t=true;
				break;
			}
		}
		if(t) break;
	}
	if(!t) {
		bin2[ind+1]=1;
		bin2[ind]=0;
	}
	for(i=inds-1;i>=1;i--) {
		for(j=1;j<=i-1;j++) {
			if(bin2[i]==1&&bin2[j]==0) {
				bin2[i]=0;
				bin2[j]=1;
			}
		}
	}
	long long sum=0;
	long long g=1;
	for(i=1;i<=ind+1;i++) {
		sum+=g*bin2[i];
		g*=2;
	}
	printf("%lld ",sum);
}
void problem2() {
	int i,j;
	int bin2[100]={0};
	for(i=1;i<=ind;i++) bin2[i]=bin[i];
	bool t=false;
	int inds;
	for(i=1;i<=ind;i++) {
		for(j=i-1;j>=1;j--) {
			if(bin2[i]==1&&bin2[j]==0) {
				bin2[i]=0;
				bin2[j]=1;
				inds=j;
				t=true;
				break;
			}
		}
		if(t) break;
	}
	if(!t) {
		printf("0 ");
	} else {
		for(i=inds-1;i>=1;i--) {
			for(j=i-1;j>=1;j--) {
				if(bin2[i]==0&&bin2[j]==1) {
					bin2[i]=1;
					bin2[j]=0;
					t=true;
					break;
				}
			}
		}
		long long sum=0;
		long long g=1;
		for(i=1;i<=ind;i++) {
			sum+=g*bin2[i];
			g*=2;
		}
		printf("%lld ",sum);
	}
}
int main() {
	scanf("%lld",&n);
	makebin(n);
	problem2();
	problem1();
}
