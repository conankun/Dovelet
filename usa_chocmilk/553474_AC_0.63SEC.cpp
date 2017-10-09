#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
int N,IN[100001];
vector<int> ve[100011];
int toposort[100011];
int queue[100011];
int h=1,t;
int chk[1000011];
double flow[1000000];
int main() {
	scanf("%d",&N);
	int a,b;
	int i,j;
	while(scanf("%d%d",&a,&b) != -1) {
		ve[a].push_back(b);
		IN[b]++;
	}
	int cnt=0;
	for(i=1;i<=N;i++) if(IN[i]==0){cnt++;queue[++t]=i;flow[i]=1;chk[i]=1;}
	for(i=1;i<=N;i++) {
		for(j=0;j<ve[queue[h]].size();j++) {
			IN[ve[queue[h]][j]]--;
			if(IN[ve[queue[h]][j]]==0) {
				queue[++t]=ve[queue[h]][j];
			}
		}
		toposort[i]=queue[h];
		IN[toposort[i]]=-1;
		h++;
	}
	for(i=1;i<=N;i++) {
		int s=ve[toposort[i]].size();
		for(j=0;j<ve[toposort[i]].size();j++) {
			flow[ve[toposort[i]][j]]+=flow[toposort[i]]/s;
		}
	}
	for(i=1;i<=N;i++) {
		if(fabs(cnt-flow[i]) < 0.0000000001 && chk[i]==0) {
			printf("%d\n",i);
		}
	}
}