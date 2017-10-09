#include<iostream>
using namespace std;
int n;
int team1[3000];
int team2[3000];
int i,j;
int main() {
	cin>>n;
	for(i=0;i<n;i++) {
		int t,a,b;
		scanf("%d %d:%d",&t,&a,&b);
		//a*60+b
		for(j=a*60+b;j<48*60;j++) {
			if(t == 1) {
				team1[j]++;
			} else {
				team2[j]++;
			}
		}
	}
	int o=0,t=0;
	for(i=0;i<48*60;i++) {
		if(team1[i] > team2[i]) o++;
		if(team1[i] < team2[i]) t++;
	}
	printf("%02d:%02d\n",o/60,o%60);
	printf("%02d:%02d\n",t/60,t%60);
}