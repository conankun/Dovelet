#include<stdio.h>
int n;
int main() {
	fscanf(stdin,"%d",&n);
	int i,j;
	//사전 셋팅.
	if(n<=4) {
		if(n==1) fprintf(stdout,"%d IS 1/1",n);
		if(n==2) fprintf(stdout,"%d IS 1/2",n);
		if(n==3) fprintf(stdout,"%d IS 2/1",n);
		if(n==4) fprintf(stdout,"%d IS 3/1",n);
		return 0;
	}
	int p=4;
	int c=2;
	int status=0;
	int a=3;
	int b=1;
	int cc=4;
	while(p<n) {
		if(status == 0) {
			a=cc/2+1;
			b=1;
		} else {
			a=1;
			b=cc/2+1;
		}
		if(p+c >= n && p+c+c+1 > n) {
			int plus = n-p;
			if(status==0) {
				fprintf(stdout,"%d IS %d/%d",n,a-plus,b+plus);
			} else {
				fprintf(stdout,"%d IS %d/%d",n,a+plus,b-plus);
			}
			return 0;
		} else if(p+c+1 == n) {
			int plus = (n-1)-p;
			if(status==0) {
				fprintf(stdout,"%d IS %d/%d",n,a-plus,b+plus+1);
			} else {
				fprintf(stdout,"%d IS %d/%d",n,a+plus+1,b-plus);
			}
			return 0;
		}
		p+=c+1;
		c++;
		cc+=2;
		status = 1-status;
	}
}