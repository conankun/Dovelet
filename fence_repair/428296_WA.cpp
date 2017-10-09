#include<stdio.h>
#include<math.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int stick[100000];
int n;
int ans;
struct A {
	int g,isFail,num,level;
	bool operator<(const A &a) const {
		return g > a.g;
	}
};
priority_queue<A> qu;
queue<A> que;
A Nodes[1000000];
vector<int> graph[100000];
int ind;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",&stick[i]);
	}
	make_heap(stick+1,stick+1+n);
	sort_heap(stick+1,stick+1+n);
	for(i=1;i<=n;i++) {
		A a;
		a.g = stick[i];
		a.isFail=1;
		a.num = i;
		Nodes[++ind]=a;
		qu.push(a);
	}
	A rootNode;
	for(i=1;i<=n-1;i++) {
		A one = qu.top();
		qu.pop();
		A two = qu.top();
		qu.pop();
		A a={0};
		a.g = one.g+two.g;
		a.num = ind+1;
		Nodes[++ind]=a;
		qu.push(a);
		rootNode=a;
		graph[ind].push_back(one.num);
		graph[ind].push_back(two.num);
	}
	que.push(rootNode);
	while(!que.empty()) {
		A front = que.front();
		if(front.isFail==1) {
			ans+=front.level*front.g;
		} else {
			for(i=0;i<graph[front.num].size();i++) {
				A aa;
				aa.num = graph[front.num][i];
				aa.isFail = graph[front.num][i] <= n;
				aa.level = front.level+1;
				aa.g = Nodes[graph[front.num][i]].g;
				que.push(aa);
			}
		}
		que.pop();
	}
	printf("%d",ans);
}