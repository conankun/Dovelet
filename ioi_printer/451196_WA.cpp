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
				if(i==size-1) isLast[n]++;
			}
			if(!t) isLast[now]++;
			break;
		}
	}
}
int dfs1(int x) {
	int i;
	int cnt=0;
	for(i=0;i<ve[x].size();i++) {
		cnt+=dfs1(ve[x][i]);
	}
	counts[x]=cnt;
	return cnt+1;
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
		countword++;
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
	dfs1(0);
	for(i=0;i<=n;i++) {
		sort(ve[i].begin(),ve[i].end(),cmp);
	}
	dfs(0);
	int m=ind;
	for(i=ind;i>=0;i--) { if(prints[i] == '-') m--; else break; }
	ind=m;
	printf("%d\n",ind+1);
	for(i=0;i<=ind;i++) printf("%c\n",prints[i]);
	return 0;
}