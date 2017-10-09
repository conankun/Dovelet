#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

struct Edge {
	int a, b;
	ll c;
};

bool test() {
	vector<Edge> ve;
	vector<ll> dis(511, 9220000000000000LL);
	int n,m,w;
	scanf("%d%d%d",&n,&m,&w);
	int i,j;
	for(i=1;i<=m;i++) {
		int a,b; ll c;
		scanf("%d%d%lld",&a,&b,&c);
		Edge ee;
		ee.a = a;
		ee.b = b;
		ee.c = c;
		ve.push_back(ee);
		ee.b = a;
		ee.a = b;
		ve.push_back(ee);
	}
	for(i=1;i<=w;i++) {
		int a,b; ll c;
		scanf("%d%d%lld",&a,&b,&c);
		Edge ee;
		ee.a = a;
		ee.b = b;
		ee.c = -1*c;
		ve.push_back(ee);
	}
	dis[1] = 0;
	for(i=1;i<=n-1;i++) {
		for(j=0;j<ve.size();j++) {
			if(dis[ve[j].a] + ve[j].c < dis[ve[j].b]) {
				dis[ve[j].b] = dis[ve[j].a] + ve[j].c;
			}
		}
	}
	for(j=0;j<ve.size();j++) {
		if(dis[ve[j].a] + ve[j].c < dis[ve[j].b]) {
			return true;
		}
	}
	return false;
}
int main() {
	int T;
	scanf("%d",&T);
	int i;
	for(i=1;i<=T;i++) {
		bool result = test();
		if(result) printf("YES\n");
		else printf("NO\n");
	}
}