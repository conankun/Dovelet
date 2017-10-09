#include<iostream>
using namespace std;
struct A {
	int s,e;
	int value;
};
A arr[100];
int map[10][10];
bool t=false;
bool ok=false;
void DFS(int ind) {
	if(ind >= 15) {
		t=true;
		ok=true;
		return;
	} else {
		int i;
		bool chk=false;
		for(i=0;i<3;i++) {
			if(map[arr[ind].s][i] >= 1 && map[arr[ind].e][2-i] >= 1 && !t) {
				chk=true;
				map[arr[ind].s][i]-=1;
				map[arr[ind].e][2-i]-=1;
				DFS(ind+1);
				map[arr[ind].s][i]+=1;
				map[arr[ind].e][2-i]+=1;
			}
		}
		if(chk==false) return;
	}
}
int main() {
	int i,j,k;
	for(i=1;i<=4;i++) {
		//Setting
		t=false;
		ok=false;
		int ind=0;
		for(j=1;j<=6;j++) {
			for(k=j+1;k<=6;k++) {
				arr[ind].s = j;
				arr[ind].e = k;
				arr[ind++].value = 0;
			}
		}
		int sum=0;
		for(j=1;j<=6;j++) {
			for(k=0;k<3;k++) {
				cin>>map[j][k];
				sum+=map[j][k];
			}
		}
		//DFS
		DFS(0);
		if(sum/2 != 15) ok=false;
		cout<<ok<<" ";
	}
}