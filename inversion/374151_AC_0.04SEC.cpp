#include<iostream>
using namespace std;
int arr[10000];
int inver[10000];
int n;
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) cin>>inver[i];
	for(i=1;i<=n;i++) {
		int cnt=0;
		int ind;
		if(inver[i] == 0) {
			ind = 1;
		} else {
			for(j=1;j<=n;j++) {
				if(arr[j] == 0 || arr[j] > i) cnt++;
				if(cnt == inver[i]) {
					ind=j+1;
					break;
				}
			}
		}
		if(arr[ind] != 0) {
			for(j=ind+1;j<=n;j++) {
				if(arr[j] == 0) {
					ind = j;
					break;
				}
			}
		}
		arr[ind]=i;
	}
	for(i=1;i<=n;i++) cout<<arr[i]<<" ";
}