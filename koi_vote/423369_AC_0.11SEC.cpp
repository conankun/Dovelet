#include<stdio.h>
#include<algorithm>
using namespace std;
struct A {
	int p[4];
	int points,ind;
	bool operator<(const A &a) const {
		int i;
		if(points == a.points)
		for(i=3;i>=1;i--) {
			if(p[i] != a.p[i]) return p[i] > a.p[i];
		}
		return points > a.points;
	}
};
A people[4];
int n;
int main() {
	scanf("%d",&n);
	int i,j,k;
	people[1].ind=1;
	people[2].ind=2;
	people[3].ind=3;
	for(i=1;i<=n;i++) {
		int a;
		for(j=1;j<=3;j++) {
			scanf("%d",&a);
			people[j].points+=a;
			people[j].p[a]++;
		}
		
	}
	sort(people+1,people+4);
	for(i=1;i<=3;i++) {
		for(j=1;j<=3;j++) {
			if(i!=j&&people[i].points == people[j].points) {
				bool t=false;
				for(k=1;k<=3;k++) if(people[j].p[k] != people[i].p[k]) { t=true; break; }
				if(!t) {
					printf("%d %d",0,people[1].points);
					return 0;
				}
			}
		}
		printf("%d %d",people[i].ind,people[i].points);
		return 0;
	}
}
