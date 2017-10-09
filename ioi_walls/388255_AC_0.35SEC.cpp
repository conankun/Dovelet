#include<iostream>
using namespace std;
int m,n; //구역,마을 수.
int l;
int reg[500];
int map[500][500]; //i->j (다각형 별)
int edgemap[500][500]; // 정점 i->다각형 j
struct A {
	int su;
	int chk[500];
};
A hull[500];
int main() {
	int i,j,k,z;
	cin>>m>>n>>l;
	for(i=1;i<=l;i++) cin>>reg[i];
	for(k=1;k<=m;k++) {
		cin>>hull[k].su;
		for(i=1;i<=hull[k].su;i++) {
			cin>>hull[k].chk[i];
			edgemap[hull[k].chk[i]][k] = 1;
		}
	}
	for(i=1;i<=m;i++) {
		for(j=i+1;j<=m;j++) {
			if(i == j) continue;
			int t=0;
			hull[i].chk[hull[i].su+1] = hull[i].chk[1];
			hull[j].chk[hull[j].su+1] = hull[j].chk[1];
			for(k=1;k<=hull[i].su;k++) {
				for(z=1;z<=hull[j].su;z++) {
					if(hull[i].chk[k+1] == hull[j].chk[z] && hull[i].chk[k] == hull[j].chk[z+1]) {
						t=1;
						break;
					}
				}
				if(t) break;
			}
			if(t) {
				map[i][j] = 1;
				map[j][i] = 1;
			}
		}
	}
	for(i=1;i<=n;i++) {
		int p=-1;
		int vis[500]={0};
		for(j=1;j<=m;j++) {
			edgemap[i][j]-=1;
			if(edgemap[i][j] != -1 && (edgemap[i][p] > edgemap[i][j] || p == -1)) p = j;
		}
		vis[p]=1;
		for(j=1;j<=m;j++) {
			if((edgemap[i][j] > edgemap[i][p]+map[p][j] || edgemap[i][j] == -1) && map[p][j] > 0) {
				edgemap[i][j] = edgemap[i][p]+map[p][j];
			}
		}
		for(j=1;j<=m-1;j++) {
			int mn=999999999;
			int ind;
			vis[p]=1;
			for(k=1;k<=m;k++) {
				if(edgemap[i][k] < mn && edgemap[i][k] != -1 && vis[k] == 0) {
					mn = edgemap[i][k];
					ind = k;
				}
			}
			p = ind;
			for(k=1;k<=m;k++) {
				if((edgemap[i][k] > edgemap[i][p]+map[p][k] || edgemap[i][k] == -1) && map[p][k] > 0 && vis[k] == 0) {
					edgemap[i][k] = edgemap[i][p]+map[p][k];
				}
			}
		}

	}
	int sum[500]={0};
	int mn=999999999;
	for(i=1;i<=l;i++) {
		//reg[i]
		for(j=1;j<=m;j++) {
			sum[j]+=edgemap[reg[i]][j];
		}
	}
	for(i=1;i<=m;i++) {
		if(sum[i] < mn) mn = sum[i];
	}
	cout<<mn<<endl;
	for(i=1;i<=m;i++) {
		if(sum[i] == mn) {
			cout<<i;
			return 0;
		}
	}
}