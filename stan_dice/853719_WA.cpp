#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		if(n==0) break;
		string ss[20];
		int prob[100][2000]={0};
		int i,j,k;
		for(i=1;i<=n;i++) {
			cin>>ss[i];
		}
		int find;
		cin>>find; 
		int mx=0,mx2=0,sum=1;
		prob[0][0]=1;
		for(i=1;i<=n;i++) {
			int x=20;
			if(ss[i]=="d4") {
				x=4;
			} else if(ss[i]=="d6") {
				x=6;
			} else if(ss[i]=="d8") {
				x=8;
			} else if(ss[i]=="d10") {
				x=10;
			} else if(ss[i]=="d12") {
				x=12;
			}
			sum*=x;
			for(j=0;j<=mx;j++) {
				for(k=1;k<=x;k++) {
					prob[i][j+k]+=prob[i-1][j];
					if(mx2 < j+k) mx2=j+k;
				}
			}
			mx=mx2;
		}
		printf("%.5lf\n",prob[n][find]/(double)sum);
	}
}