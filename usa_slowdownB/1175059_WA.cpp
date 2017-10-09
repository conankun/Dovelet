#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
struct A { //event
	char c; int d;
}ar[100000];
bool cmp(A a, A b) {
	if(a.c > b.c) {
		return a.c > b.c;
	}
	return a.d < b.d;
}
int main() {
	int i;
	scanf("%d\n",&N);
	int td=0;
	for(i=1;i<=N;i++) {
		scanf("%c %d\n",&ar[i].c,&ar[i].d);
		if(ar[i].c == 'T') {
			td++;
		}
	}
	int otd=td;
	td++;//index of D
	int tn=1;
	sort(ar+1,ar+N,cmp);
	int tm = 0, dis = 0,sp=1;
	double alltime=0;
	while(!(td > N && tn > otd)) {
		double disoft = dis+(ar[tn].d-tm)/sp;
		double disofd = ar[td].d;
		
		if(td > N) {
			alltime += (disoft-dis)*sp;
			tm += (disoft-dis)*sp;
			sp++;
			tn++;
			dis=disoft;
			continue;
		}

		if(tn > otd && td <= N) {
			alltime += (disofd-dis)*sp;
			tm += (disofd-dis)*sp;
			sp++;
			td++;
			dis=disofd;
			continue;
		}
		
		
		if(disoft < disofd) { // if t precedes d
			alltime += (disoft-dis)*sp;
			tm += (disoft-dis)*sp;
			sp++;
			tn++;
			dis=disoft;
		} else { //same or opposite
			alltime += (disofd-dis)*sp;
			tm += (disofd-dis)*sp;
			sp++;
			td++;
			dis=disofd;
		}
	}
	alltime += (1000.-dis) * sp;
	printf("%.0lf",alltime);
}