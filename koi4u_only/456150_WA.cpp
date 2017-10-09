#include<stdio.h>
#include<map>
#include<queue>
using namespace std;
int N,K;
int isChk[1000000];
int tree[1000000];
int node[1000000];
int size=1;
map<int,int> chk;
map<int,int> ::iterator I,J;
struct A {
	int number;
	bool operator<(const A &a) const {
		return number < a.number;
	}
};
priority_queue<A> qu;
int main() {
	scanf("%d%d",&N,&K);
	int i,j;
	for(i=1;i<=N;i++) {
		scanf("%d",&node[i]);
	}
	for(;size<N;size*=2);
	for(i=1;i<=K;i++) {
		I=chk.find(node[i]);
		if(I==chk.end()) {
			chk.insert(make_pair(node[i],1));
		} else chk.insert(make_pair(node[i],(I->second)+1));
	}
	A a;
	for(i=1;i<=K;i++) {
		I=chk.find(node[i]);
		if(I->second==1) {
			a.number=node[i];
			qu.push(a);
		}
	}
	for(i=1;i<=N-K+1;i++) {
		bool t=true;
		int counts;
		while(!qu.empty()) {
			I=chk.find(qu.top().number);
			counts=I->second;
			if(counts != 1) {
				qu.pop();
			} else {
				t=false;
				break;
			}
			if(qu.empty()) break;
		}
		if(qu.empty()) printf("Poor yeaFe\n");
		else printf("%d\n",qu.top().number);
		chk[node[i]]--;
		chk[node[i+K]]++;
		I=chk.find(node[i]);
		J=chk.find(node[i+K]);
		if(I->second==1) {
			a.number=node[i];
			qu.push(a);
		}
		if(J->second==1) {
			a.number=node[i+K];
			qu.push(a);
		}
	}
}