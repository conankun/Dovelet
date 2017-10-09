#include<iostream>
#include<queue>
using namespace std;
unsigned long long n;
unsigned long long data[100000];
unsigned long long vis[100000];
unsigned long long arr[100000];
unsigned long long l[100000];
unsigned long long index=0;
void BFS(unsigned long long ind) {
	queue<unsigned long long> qu;
	qu.push(ind);
	unsigned long long cnt=0;
	do {
		cnt++;
		vis[qu.front()] = 1;
		qu.push(data[qu.front()]);
		qu.pop();
	} while(qu.front() != ind);
	arr[index++] = cnt;
}
unsigned long long lcd(unsigned long long a,unsigned long long b) {
	unsigned long long gob = a*b;
	unsigned long long c;
	do {
		c = a%b;
		a = b;
		b = c;
	}while(c != 0);
	return gob/a;
}
int main() {
	scanf("%d",&n);
	unsigned long long i;
	for(i=1;i<=n;i++) scanf("%d",&data[i]);
	for(i=1;i<=n;i++) {
		if(vis[i] == 0) {
			BFS(i);
		}
	}
	l[0] = arr[0];
	for(i=1;i<index;i++) {
		l[i] = lcd(l[i-1],arr[i]);
	}
	cout<<l[index-1];
}