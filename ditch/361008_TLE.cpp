#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct vertex {
	int weight,idx;
};
int rn[300][300];
int max_flow,m;
bool check[300];
vector<int> path;
int vertex_sort(const vertex &a,const vertex &b) {
	return a.weight > b.weight;
}
bool PFS(int x,int local_flow) {
	int i;
	vector<vertex> v;
	vertex vx;
	if(x == m) {
		max_flow+=local_flow;
		for(i=0;i<path.size()-1;i++) {
			rn[path[i]][path[i+1]]-=local_flow;
			rn[path[i+1]][path[i]]+=local_flow;
		}
		path.clear();
		path.push_back(1);
		return true;
	}
	for(i=1;i<=m;i++) {
		if(rn[x][i] > 0 && !check[i]) {
			vx.idx = i;
			vx.weight = rn[x][i];
			v.push_back(vx);
		}
	}
	sort(v.begin(),v.end(),vertex_sort);
	for(i=0;i<v.size();i++) {
		check[v[i].idx] = true;
		path.push_back(v[i].idx);
		//용량이 큰 것부터 차례대로 방문됨.
		//하나의 경로가 처리되면 다음은 방문하지 않고 true
		//리턴하며 종료
		//이전까지의 간선 용량중 최소로 갱신해간다.
		if(PFS(v[i].idx,min(local_flow,v[i].weight))) {
			return true;
		}
		path.pop_back();
		check[v[i].idx]=false;
	}
	return false;
}
void MaxFlow() {
	path.push_back(1);
	while(PFS(1,999999999)) {
		fill(check,check+m+1,0);
		check[1]=1;
	}
}
int main() {
	int n,a,b,c;
	cin>>n>>m;
	while(n--) {
		cin>>a>>b>>c;
		rn[a][b]=c;
	}
	MaxFlow();
	cout<<max_flow<<endl;
}