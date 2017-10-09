#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
#include<search.h>
using namespace std;
struct code {
	string cos;
	int value;
	int index;
	bool operator<(const code &c) const {
		return value < c.value;
	}
};
code codes[100010];
int temp[100010];
code code[100010];
int dis[100010];
int vis[100010];
int back[100010];
int vis2[100010];
int bt[100010];
int backind;
int n,k,m;
int a,b;
queue<int> qu;
vector<int> vex[100010];
int convert(string s) {
	int i;
	int g=1;
	int sum=0;
	for(i=s.size()-1;i>=0;i--) {
		sum+=(s[i]-48)*g;
		g*=2;
	}
	return sum;
}
int cmp(const void *va,const void *vb) 
{ 
   int *p,*q; 
  
   p = (int*)va; 
   q = (int*)vb; 
  
   return *p - *q; 
}
int log2(int x) {
	int cnt=0;
	while(x > 0) {
		cnt++;
		x/=2;
	}
	return cnt-1;
}
int main() {
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++) {
		cin>>codes[i].cos;
		codes[i].index = i;
		codes[i].value = convert(codes[i].cos);
		code[i] = codes[i];
		temp[i] = codes[i].value;
	}
	scanf("%d %d",&a,&b);
	sort(codes+1,codes+n+1);
	sort(temp+1,temp+n+1);
	for(i=1;i<=n;i++) {
		for(j=1;;j*=2) {
			if(codes[i].value-j < 0) break;
			else {
				int x = k-1-log2(j);
				if(codes[i].cos[k-1-log2(j)] == '0') continue;
				int key = codes[i].value-j;
				int *s = (int*) bsearch(&key,temp,n+1,sizeof(int),cmp);
				if(s != 0) {
					vex[codes[i].index].push_back(codes[s-temp].index);
				}
			}
		}
		int limit=pow(2,(double)k);
		for(j=1;;j*=2) {
			if(codes[i].value+j > limit || codes[i].value+j < 0) break;
			else {
				int x = k-1-log2(j);
				if(codes[i].cos[k-1-log2(j)] == '1') continue;
				int key = codes[i].value+j;
				int *s =(int*) bsearch(&key,temp,n+1,sizeof(int),cmp );
				if(s != 0) {
					vex[codes[i].index].push_back(codes[s-temp].index);
				}
			}
		}
	}
	//Graph Setting End.
	fill(dis+1,dis+1+n,-1);
	qu.push(a);
	dis[a]=0;
	int cnt=0;
	while(!qu.empty()) {
		int p=qu.front();
		if(vis[p] == 0) {
			vis[p]=1;
			cnt++;
		} else {
			qu.pop();
			continue;
		}
		if(cnt == n) break;
		for(j=0;j<vex[p].size();j++) {
			//p -> vex[p][j]
			int cc=vex[p][j];
			if(vis[vex[p][j]] == 0 && dis[vex[p][j]] > dis[p]+1 || dis[vex[p][j]] == -1) {
				dis[vex[p][j]] = dis[p]+1;
				back[vex[p][j]] = p;
				qu.push(vex[p][j]);
			}
		}
		qu.pop();
	}
	if(dis[b] == -1) {
		cout<<-1<<endl;
		return 0;
	}
	vector<int> backv;
	backv.push_back(b);
	int t=back[b];
	backv.push_back(t);
	while(t > 0) {
		t = back[t];
		backv.push_back(t);
	}
	for(j=backv.size()-2;j>=0;j--) cout<<backv[j]<<" ";
	cout<<endl;
}