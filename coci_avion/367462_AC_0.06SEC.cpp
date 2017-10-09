#include<iostream>
#include<string>
using namespace std;
string arr[10];
bool t=false;
int vis[10];
int main() {
	int i,j;
	for(i=1;i<=5;i++) cin>>arr[i];
	for(i=1;i<=5;i++) {
		for(j=0;j<arr[i].size()-2;j++) {
			if(arr[i][j] == 'F' && arr[i][j+1] == 'B' && arr[i][j+2] == 'I') {
				vis[i]=1;
				t=true;
				break;
			}
		}
	}
	if(!t) cout<<"HE GOT AWAY!";
	else {
		for(i=1;i<=5;i++) if(vis[i] == 1) cout<<i<<" ";
	}
}