#include<stdio.h>
#include<algorithm>
using namespace std;
struct A {
	int value,classes;
	bool operator<(const A &a) const {
		return value < a.value;
	}
};
int n,m;
A points[10000000];
int ind;
int cnt;
int vis[10000];
int ans=2147483647;
int main() {
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			points[++ind].classes=i;
			scanf("%d",&points[ind]);
		}
	}
	stable_sort(points+1,points+ind+1);
	int last=1;
	cnt=1;
	vis[points[1].classes]=1;
	if(cnt==n) {
		last=1;
		ans=0;
	} else {
		for(i=2;i<=ind;i++) {
			if(vis[points[i].classes]==0) cnt++;
			vis[points[i].classes]++;
			if(cnt == n) {
				if(ans > points[i].value-points[1].value) ans = points[i].value-points[1].value;
				last=i;
				break;
			}
		}
	}
	for(i=2;i<=ind;i++) {
		vis[points[i-1].classes]--;
		if(vis[points[i-1].classes]==0) cnt--;
		for(j=last;j<=ind;j++) {
			if(j != last) {
				if(vis[points[j].classes]==0) cnt++;
				vis[points[j].classes]++;
			}
			if(cnt == n) {
				if(ans > points[j].value-points[i].value) ans = points[j].value-points[i].value;
				last=j;
				break;
			}
		}
	}
	printf("%d",ans);
}