#include<iostream>
#include<string>
using namespace std;
int N;
struct A {
	string name;
	int plus,minus,a,b,c,d,e;
}people[100];
int main() {
	cin>>N;
	int i;
	for(i=1;i<=N;i++) {
		cin>>people[i].name>>people[i].plus>>people[i].minus>>people[i].a>>people[i].b>>people[i].c>>people[i].d>>people[i].e;
	}
	int ans=-2147483647,index=0;
	for(i=1;i<=N;i++) {
		int score = people[i].a+people[i].b+people[i].c+people[i].d+people[i].e;
		score+=(people[i].plus*100);
		score-=(people[i].minus*50);
		if(ans < score) {
			ans = score;
			index = i;
		}
	}
	printf("%s",people[index].name.c_str());
}