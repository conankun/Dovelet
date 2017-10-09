#include<iostream>
#include<fstream>
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
ifstream in("input.txt");
ofstream out("output.txt");
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
	//DFS
	for(i=0;i<v.size();i++) {
		check[v[i].idx] = 1;
		path.push_back(v[i].idx);
		if(PFS(v[i].idx,min(local_flow,v[i].weight))) //경로가 처리되면 다음은 방문하지 않고 리턴.
			return true;
		//복원
		path.pop_back();
		check[v[i].idx]=0;
	}
	return false;
}
void MaxFlow() {
	path.push_back(1);
	int t=m;
	while(t--) {
		PFS(1,999999999);
		fill(check,check+m+1,0);
		check[1]=1;
	}
}
int main() {
	int n,a,b,c;
	in>>n>>m;
	while(n--) {
		in>>a>>b>>c;
		rn[a][b]=c;
	}
	MaxFlow();
	out<<max_flow<<endl;
}