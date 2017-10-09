#include<iostream>
using namespace std;
int vis[1000];
int priod[1000/*00*/];
int ind=1;
int A,B;
int main() {
	int i,j;
	for(i=0;i<1000;i++) vis[i]=-1;
	cin>>A>>B;
	int s=1;
	int start;
	for(i=1;;i++) {
		s*=A;
		s%=1000;
		if(vis[s] != -1) {
			start=vis[s];
			priod[0]=priod[ind-1];
			break;
		}
		vis[s]=i;
		priod[ind++]=s;
	}
	B-=start;
	int div=i-start;
	printf("%03d",priod[start+B%div]);
}