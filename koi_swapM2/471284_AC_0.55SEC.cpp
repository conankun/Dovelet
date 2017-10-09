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
int sss[10][10];
void back(int level) {
	int i,j;
	queue<int> st[10];
	if(level==4) {
		for(i=1;i<=n;i++) {
			root[i]=order[rooted[i]];
			sorted[i]=order[rooted[i]];
		}
		stable_sort(sorted+1,sorted+1+n);
		int cnt=0;
		sss[1][2]=1,sss[1][3]=2,sss[2][1]=3,sss[2][3]=4,sss[3][1]=5,sss[3][2]=6;
		for(i=1;i<=n;i++) {
			st[sss[root[i]][sorted[i]]].push(i);
		}
		for(i=1;i<=n;i++) {
			if(root[i] == sorted[i]) continue;
			int ind;
			ind=sss[sorted[i]][root[i]];
			bool tr=0;
			while(!st[ind].empty()) {
				int aa = st[ind].front();
				if(aa <= i || sorted[aa]==root[aa] || sss[root[aa]][sorted[aa]] != ind) {
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
			if(sorted[i]==1) ind=1;
			else if(sorted[i]==2) ind=3;
			else if(sorted[i]==3) ind=5;

			while(!st[ind].empty()) {
				int aa = st[ind].front();
				if(aa <= i || sorted[aa]==root[aa] || sss[root[aa]][sorted[aa]] != ind) {
					st[ind].pop();
				} else {
					int temp = root[st[ind].front()];
					root[st[ind].front()]=root[i];
					root[i]=temp;
					cnt++;
					st[ind].pop();
					tr=1;
					st[sss[root[aa]][sorted[aa]]].push(aa);
					break;
				}
			}

			if(tr) continue;

			if(sorted[i]==1) ind=2;
			else if(sorted[i]==2) ind=4;
			else if(sorted[i]==3) ind=6;

			while(!st[ind].empty()) {
				int aa = st[ind].front();
				if(aa <= i || sorted[aa]==root[aa] || sss[root[aa]][sorted[aa]] != ind) {
					st[ind].pop();
				} else {
					int temp = root[st[ind].front()];
					root[st[ind].front()]=root[i];
					root[i]=temp;
					cnt++;
					st[ind].pop();
					tr=1;
					st[sss[root[aa]][sorted[aa]]].push(aa);
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