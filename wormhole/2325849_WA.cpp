#include<iostream>
#include<vector>
using namespace std;

struct Edge {
	int a, b, c;
};

bool test() {
	vector<Edge> ve;
	vector<int> dis(511, -1);
	int n,m,w;
	scanf("%d%d%d",&n,&m,&w);
	int i,j;
	for(i=1;i<=m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		Edge ee;
		ee.a = a;
		ee.b = b;
		ee.c = c;
		ve.push_back(ee);
	}
	for(i=1;i<=w;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		Edge ee;
		ee.a = a;
		ee.b = b;
		ee.c = -1*c;
		ve.push_back(ee);
	}

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