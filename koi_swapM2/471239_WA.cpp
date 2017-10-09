#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int rooted[100011];
int root[100011];
int sorted[100011];
int order[10],vis[10];
int ans=-1;
void back(int level) {
	int i,j;
	queue<int> st[10];
	if(level==4) {
		for(i=1;i<=n;i++) {
			root[i]=order[rooted[i]];
			sorted[i]=order[root[i]];
		}
		stable_sort(sorted+1,sorted+1+n);
		int cnt=0;
		for(i=1;i<=n;i++) {
			if(root[i]==1&&sorted[i]==2) {
				st[1].push(i);
			}
			if(root[i]==1&&sorted[i]==3) {
				st[2].push(i);
			}
			if(root[i]==2&&sorted[i]==1) {
				st[3].push(i);
			}
			if(root[i]==2&&sorted[i]==3) {
				st[4].push(i);
			}
			if(root[i]==3&&sorted[i]==1) {
				st[5].push(i);
			}
			if(root[i]==3&&sorted[i]==2) {
				st[6].push(i);
			}
		}
		for(i=1;i<=n;i++) {
			if(root[i] == sorted[i]) continue;
			int ind;
			if(root[i]==1&&sorted[i]==2) {
				ind=3;
			}
			if(root[i]==1&&sorted[i]==3) {
				ind=5;
			}
			if(root[i]==2&&sorted[i]==1) {
				ind=1;
			}
			if(root[i]==2&&sorted[i]==3) {
				ind=6;
			}
			if(root[i]==3&&sorted[i]==1) {
				ind=2;
			}
			if(root[i]==3&&sorted[i]==2) {
				ind=4;
			}
			bool tr=0;
			while(!st[ind].empty()) {
				int aa = st[ind].front();
				if(aa <= i || sorted[aa]==root[aa]) {
					st[ind].pop();
				} else {
					int temp = root[st[ind].front()];
					root[st[ind].front()]=root[i];
					root[i]=temp;
					cnt++;
					st[ind].pop();
					tr=1;
					break;
				}
			}
			if(tr) continue;
			if(root[i]==1) ind=3;
			else if(root[i]==2) ind=1;
			else if(root[i]==3) ind=2;

			while(!st[ind].empty()) {
				int aa = st[ind].front();
				if(aa <= i || sorted[aa]==root[aa]) {
					st[ind].pop();
				} else {
					int temp = root[st[ind].front()];
					root[st[ind].front()]=root[i];
					root[i]=temp;
					cnt++;
					st[ind].pop();
					tr=1;
					break;
				}
			}

			if(tr) continue;

			if(root[i]==1) ind=5;
			else if(root[i]==2) ind=6;
			else if(root[i]==3) ind=4;

			while(!st[ind].empty()) {
				int aa = st[ind].front();
				if(aa <= i || sorted[aa]==root[aa]) {
					st[ind].pop();
				} else {
					int temp = root[st[ind].front()];
					root[st[ind].front()]=root[i];
					root[i]=temp;
					cnt++;
					st[ind].pop();
					tr=1;
					break;
				}
			}
		}
		if(ans==-1 || cnt < ans) ans = cnt;
	} else {
		for(i=1;i<=3;i++) {
			if(vis[i]==0) {
				vis[i]=1;
				order[i]=level;
				back(level+1);
				vis[i]=0;
			}
		}
	}
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&rooted[i]);
	back(1);
	printf("%d",ans);
}