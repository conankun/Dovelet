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
		for(j=p;j>=i;j--) {
			if(l[i]+l[j] <= s) {
				t=true;
				cnt+=j-i;
				p = j;
				break;
			}
		}
		if(t) {
		//	cnt++;
		} else {
			break;			
		}
	}
	cout<<cnt;
}