#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct data {
	int v,d; //정점,거리
	bool operator<(const data &data) const {
		return d > data.d;
	}
};
struct D {
	int index,value;
};
priority_queue<data> qu1,qu2,qu3;
data edge[100010][20];
int A,B,C,n,m,t,i,j,c,edgeindex[10010],v3[100010],d3[100010],d1[100010],d2[100010],v1[100010],v2[100010],indexed_b[100010],isRight[100010];
D byD_a[100010],byD_b[100010],tree[1000000];
bool cmp(D a,D b) {
	return a.value < b.value;
}
int main() {
	scanf("%d",&n);
	scanf("%d %d %d",&A,&B,&C);
	scanf("%d",&m);
	for(i=0;i<m;i++) {
		int s,e,t;
		scanf("%d %d %d",&s,&e,&t);
		data d;
		d.v = e;
		d.d = t;
		edge[s][edgeindex[s]++]=d;
		d.v = s;
		edge[e][edgeindex[e]++]=d;
	}
	fill(d1,d1+n+1,-1);
	fill(d2,d2+n+1,-1);
	fill(d3,d3+n+1,-1);
	d1[A]=0;
	data d;
	d.v = A;
	d.d = 0;
	qu1.push(d);
	int cnt=0;
	while(!qu1.empty()) {
		data p = qu1.top();
		if(v1[p.v] == 0) {
			v1[p.v]=1;
			cnt++;
		} else {
			qu1.pop();
			continue;
		}
		if(cnt == n) break;
		qu1.pop();
		for(i=0;i<edgeindex[p.v];i++) {
			if(d1[edge[p.v][i].v] == -1 || d1[edge[p.v][i].v] > d1[p.v]+edge[p.v][i].d) {
				 d1[edge[p.v][i].v] = d1[p.v]+edge[p.v][i].d;
				 d.v = edge[p.v][i].v;
				 d.d = d1[edge[p.v][i].v];
				 qu1.push(d);
			}
		}
	}
	d2[B]=0;
	d.v = B;
	d.d = 0;
	qu2.push(d);
	cnt=0;
	while(!qu2.empty()) {
		data p = qu2.top();
		if(v2[p.v] == 0) {
			v2[p.v]=1;
			cnt++;
		} else {
			qu2.pop();
			continue;
		}
		if(cnt == n) break;
		qu2.pop();
		for(i=0;i<edgeindex[p.v];i++) {
			if(d2[edge[p.v][i].v] == -1 || d2[edge[p.v][i].v] > d2[p.v]+edge[p.v][i].d) {
				 d2[edge[p.v][i].v] = d2[p.v]+edge[p.v][i].d;
				 d.v = edge[p.v][i].v;
				 d.d = d2[edge[p.v][i].v];
				 qu2.push(d);
			}
		}
	}
	d3[C]=0;
	d.v = C;
	d.d = 0;
	qu3.push(d);
	cnt=0;
	while(!qu3.empty()) {
		data p = qu3.top();
		if(v3[p.v] == 0) {
			v3[p.v]=1;
			cnt++;
		} else {
			qu3.pop();
			continue;
		}
		if(cnt == n) break;
		qu3.pop();
		for(i=0;i<edgeindex[p.v];i++) {
			if(d3[edge[p.v][i].v] == -1 || d3[edge[p.v][i].v] > d3[p.v]+edge[p.v][i].d) {
				 d3[edge[p.v][i].v] = d3[p.v]+edge[p.v][i].d;
				 d.v = edge[p.v][i].v;
				 d.d = d3[edge[p.v][i].v];
				 qu3.push(d);
			}
		}
	}
	for(i=1;i<=n;i++) {
		byD_a[i].value = d1[i];
		byD_a[i].index = i;
		byD_b[i].value = d2[i];
		byD_b[i].index = i;
	}
	sort(byD_a+1,byD_a+n+1,cmp);
	sort(byD_b+1,byD_b+n+1,cmp);
	for(i=1;i<=n;i++) {
		indexed_b[byD_b[i].index]=i;
	}
	int size=1;
	for(;size<n;size*=2);
	for(i=1;i<=n;i++) {
		int ld = size,rd = size+indexed_b[byD_a[i].index]-2;
		bool ok=1;
		bool cs=1;
		while(ld<=rd && ok) {
			if(ld == rd) ok=0;
			if(ld%2 == 1) {
				if(tree[ld].index != 0 && d3[tree[ld].index] < d3[byD_a[i].index]) {
					cs=0;
					break;
				}
				ld++;
			}
			if(rd%2 == 0) {
				if(tree[rd].index != 0 && d3[tree[rd].index] < d3[byD_a[i].index]) {
					cs=0;
					break;
				}
				rd--;
			}
			ld/=2;
			rd/=2;
		}
		isRight[byD_a[i].index] = cs;
		int rs = size+indexed_b[byD_a[i].index]-1;
		while(rs > 0) {
			if(tree[rs].index == 0 || d3[tree[rs].index] > d3[byD_a[i].index]) {
				tree[rs].index = byD_a[i].index;
			}
			rs/=2;
		}
	}
	scanf("%d",&t);
	for(i=0;i<t;i++) {
		scanf("%d",&c);
		if(isRight[c]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}

