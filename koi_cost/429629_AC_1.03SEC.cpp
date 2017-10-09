#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct vertex {
	long long x,y,w;
	bool operator<(const vertex &a) const {
		return w > a.w;
	}
}ve[200000];
long long n,m;
long long group[200000];
long long groupcount[200000];
long long union_find(long long x) {
	vector<long long> v;
	while(group[x] != x) {
		if(group[x] != group[group[x]]) v.push_back(x);
		x = group[x];
	}
	while(!v.empty()) {
		group[v.back()]=x;
		v.pop_back();
	}
	return x;
}
long long m2(long long x) {
	long long mm = ((x-1)*x);
	mm/=2;
	mm%=1000000000;
	return mm;
}
int main() {
	scanf("%lld%lld",&n,&m);
	int i;
	for(i=1;i<=m;i++) {
		scanf("%lld%lld%lld",&ve[i].x,&ve[i].y,&ve[i].w);
		ve[i].w%=1000000000;
	}
	for(i=1;i<=n;i++) {
		group[i] = i;
		groupcount[i] = 1;
	}
	sort(ve+1,ve+1+m);
	long long plus=0;
	long long sum=0;
	long long a,b;
	for(i=1;i<=m;i++) {
		a = union_find(ve[i].x);
		b = union_find(ve[i].y);
		if(a>b) {
			plus+=1000000000;
			plus-=m2(groupcount[a]);
			plus%=1000000000;
			plus+=1000000000;
			plus-=m2(groupcount[b]);
			plus%=1000000000;
			groupcount[b]+=groupcount[a];
			group[a]=b;
			plus+=m2(groupcount[b]);
			plus%=1000000000;
		} else if(a<b) {
			plus+=1000000000;
			plus-=m2(groupcount[a]);
			plus%=1000000000;
			plus+=1000000000;
			plus-=m2(groupcount[b]);
			plus%=1000000000;
			groupcount[a]+=groupcount[b];
			group[b]=a;
			plus+=m2(groupcount[a]);
			plus%=1000000000;
		}
		sum+=(ve[i].w*plus)%1000000000;
		sum%=1000000000;
	}
	printf("%lld",sum%1000000000);
}