#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ve[500001];
char node[500001];
char word[250001][30];
int counts[500001];
int isLast[500001];
int N,n;
void make_trie(int x) {
	int now=0,ind=0;
	int i;
	while(1) {
		for(i=0;i<ve[now].size();i++) {
			if(node[ve[now][i]]==word[x][ind]) {
				now = ve[now][i];
				ind++;
				break;
			}
		}
		if(i==ve[now].size()) {
			int size = strlen(word[x]);
			bool t=false;
			for(i=ind;i<size;i++) {
				t=true;
				node[++n]=word[x][i];
				ve[now].push_back(n);
				now=n;
				if(i==size-1) isLast[n]=1;
			}
			if(!t) isLast[now]=1;
			break;
		}
	}
}
int mxlevel;
void dfs1(int x,int level) {
	int i;
	int cnt=0;
	for(i=0;i<ve[x].size();i++) {
		dfs1(ve[x][i],level+1);
	}
	if(level > mxlevel) {
		mxlevel = level;
	}
}
int back[1000];
int sized=1;
bool tru=0;
void dfs2(int x,int level) {
	int i;
	int cnt=0;
	for(i=0;i<ve[x].size();i++) {
		back[++sized]=ve[x][i];
		dfs2(ve[x][i],level+1);
		--sized;
		if(tru) return;
	}
	if(level == mxlevel) {
		for(i=1;i<=sized;i++) {
			counts[back[i]]=1;
		}
		tru=1;
		return;
	}
}
bool cmp(int a,int b) {
	return counts[a] < counts[b];
}
int countword=0;
char prints[1500000];
int ind=-1;
bool t=false;
void dfs(int x) {
	if(x != 0) prints[++ind]=node[x];
	if(isLast[x]) {
		countword+=isLast[x];
		int i;
		for(i=1;i<=isLast[x];i++) prints[++ind]='P';
	}
	int i;
	for(i=0;i<ve[x].size();i++) {
		if(t) break;
		dfs(ve[x][i]);
	}
	if(countword==N) {
		t=true;
		return;
	}
	else if(x != 0) prints[++ind]='-';
}
int main() {
	scanf("%d",&N);
	scanf("\n");
	int i;
	for(i=1;i<=N;i++) {
		scanf("%s",word[i]);
		make_trie(i);
	}
	dfs1(0,0);
	dfs2(0,0);
	for(i=0;i<=n;i++) {
		sort(ve[i].begin(),ve[i].end(),cmp);
	}
	dfs(0);
	int m=ind;
	ind=m;
	printf("%d\n",ind+1);
	for(i=0;i<=ind;i++) printf("%c\n",prints[i]);
	return 0;
}