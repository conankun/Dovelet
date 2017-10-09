#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int cn[1011][1011];
int vis[1011];
int chk[1011];
int vis2[1011][1011];
int n,l;
int cnt=0;
vector<int> path;
int min(int a,int b) {
    if(a < b) return a;
    return b;
}
bool PFS(int idx,int nowflow) {
    int i;
    if(idx == l) {
        cnt++;
        for(i=0;i<path.size()-1;i++) {
            //i,i+1
            cn[path[i]][path[i+1]]-=1;
            cn[path[i+1]][path[i]]+=1;
        }
        return true;
    }
    for(i=0;i<=l;i++) {
        if(vis[i] == 0 && cn[idx][i] > 0) {
            vis[i]=1;
            path.push_back(i);
            if(PFS(i,min(cn[idx][i],nowflow))) {
                return true;
            }
            path.pop_back();
        }
    }
    return false;
}
bool PFS2(int idx,int nowflow) {
    int i;
    if(idx == 0) {
        for(i=0;i<path.size()-1;i++) {
            //i,i+1
            cn[path[i]][path[i+1]]-=1;
            cn[path[i+1]][path[i]]+=1;
        }
		//path[1] , path[path.size()-2]
		chk[path[path.size()-2]]=path[path.size()-3];
		return true;
    }
    for(i=0;i<=l;i++) {
        if(vis[i] == 0 && cn[idx][i] > 0) {
            vis[i]=1;
            path.push_back(i);
            if(PFS2(i,min(cn[idx][i],nowflow))) {
                return true;
            }
            path.pop_back();
        }
    }
    return false;
}
void nf() {
	vis[0]=1;
	path.push_back(0);
	while(PFS(0,9999999)) {
		memset(vis,0,sizeof(int)*1011);
		vis[0]=1;
		path.clear();
		path.push_back(0);
	}
}
void nf2() {
	vis[n*2+1]=1;
	path.push_back(n*2+1);
	memset(vis,0,sizeof(int)*1011);
	while(PFS2(n*2+1,9999999)) {
		memset(vis,0,sizeof(int)*1011);
		vis[n*2+1]=1;
		path.clear();
		path.push_back(n*2+1);
	}
}
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) {
		int s;
		cin>>s;
		for(j=1;j<=s;j++) {
			int a;
			cin>>a;
			cn[i][a+n]+=1;
		}
	}
	l=n+n+1;
	for(i=1;i<=n;i++) cn[0][i]=1;
	for(i=n+1;i<=n+n;i++) cn[i][l]=1;
	nf();
	nf2();
	cout<<cnt<<endl;
	for(i=1;i<=n;i++) {
		cout<<i<<" ";
		if(chk[i] == 0) cout<<-1<<endl;
		else cout<<chk[i]-n<<endl;
	}
}
