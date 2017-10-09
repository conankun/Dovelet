#include<iostream>
using namespace std;
int N,B,H,W;
int mini=999999999;
int main() {
	cin>>N>>B>>H>>W;
    mini=B;
	int i,j;
	for(i=1;i<=H;i++) {
		int n,a;
		cin>>n;
		for(j=1;j<=W;j++) {
            cin>>a;
            if(a >= N) {
                mini=min(mini,n*N);
            }
        }
	}
	if(mini==B) cout<<"stay home";
	else cout<<mini;
}