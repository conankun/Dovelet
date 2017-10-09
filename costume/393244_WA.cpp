#include<iostream>
#include<algorithm>
using namespace std;
int n,s;
int l[100000];
int main() {
	scanf("%d%d",&n,&s);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&l[i]);
	sort(l+1,l+n+1);
	int p=n;
	int cnt=0;
	for(i=1;i<=n;i++) {
		bool t=false;
		for(j=p;j>=1;j--) {
			if(l[i]+l[j] <= s) {
				t=true;
				p = j-1;
				break;
			}
		}
		if(t) {
			cnt++;
		} else {
			break;			
		}
	}
	cout<<cnt;
}