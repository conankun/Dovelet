#include<iostream>
using namespace std;
int n;
int arr[100];
int main() {
	int i,j,k,z,l,c;
	cin>>n;
	int cnt=0;
	for(i=1;i<=n;i++) cin>>arr[i];
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			for(k=1;k<=n;k++) {
				for(z=1;z<=n;z++) {
					for(l=1;l<=n;l++) {
						int a = arr[i]*100+arr[j]*10+arr[k];
						int b = arr[z]*10+arr[l];
						if((a*arr[z])/1000 <= 0 && (a*arr[l])/1000 <= 0 && (a*b)/10000 <= 0) {
							int cc = a*arr[z];
							bool tr=true;
							while(cc > 0) {
								tr=false;
								for(c=1;c<=n;c++) {
									if(cc%10 == arr[c]) tr=true;
								}
								if(!tr) break;
								cc/=10;
							}
							if(!tr) continue;
							cc = a*arr[l];
							while(cc > 0) {
								tr=false;
								for(c=1;c<=n;c++) {
									if(cc%10 == arr[c]) tr=true;
								}
								if(!tr) break;
								cc/=10;
							}
							if(!tr) continue;
							cc = a*b;
							while(cc > 0) {
								tr=false;
								for(c=1;c<=n;c++) {
									if(cc%10 == arr[c]) tr=true;
								}
								if(!tr) break;
								cc/=10;
							}
							if(tr) {
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	cout<<cnt;
}