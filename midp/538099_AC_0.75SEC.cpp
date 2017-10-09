#include<stdio.h>
int case1,case2,case3,case4,x,y,n,i,sum;
int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&x,&y);
		int tc=0;
		if(x%2==0 && y%2==0) {
			sum+=case1;
			case1++;
		} else if(x%2==0 && y%2==1) {
			sum+=case2;
			case2++;
		} else if(x%2==1 && y%2==0) {
			sum+=case3;
			case3++;
		} else if(x%2==1 && y%2==1) {
			sum+=case4;
			case4++;
		}

	}
	printf("%d",sum);
}