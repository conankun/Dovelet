#include<iostream>
using namespace std;
int main() {
	int i,j,k;
	int n,r;
	while(cin>>n>>r) {
		int card[101];
		if(n == 0 && r == 0) break;
		for(i=n;i>=1;i--) card[i]=n-i+1;
		int a,b;
		for(i=1;i<=r;i++) {
			int backup[101];
			int backup2[101];
			int ind=1,ind2=1;
			cin>>a>>b;
			for(j=a;j<=a+b-1;j++) {
				backup[ind++]=card[j];
			}
			for(j=1;j<=a-1;j++) {
				backup2[ind2++]=card[j];
			}
			for(j=1;j<=b;j++) card[j]=backup[j];
			for(j=b+1;j<=a+b-1;j++) card[j]=backup2[j-b];
		}
		cout<<card[1]<<endl;
	}
}