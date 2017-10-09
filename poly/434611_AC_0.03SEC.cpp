#include<stdio.h>
#include<deque>
using namespace std;
int R,N;
int root[1000];
int poss[1000][1000];
int chk[1000];
int cnt;
deque<int> de1;
deque<int> de2;
deque<int> de3;
deque<int> de4;
int main() {
	scanf("%d",&R);
	int i,j,d;
	for(i=1;i<=R;i++) scanf("%d",&root[i]);
	scanf("%d",&N);
	for(i=1;i<=N;i++) {
		for(j=1;j<=R;j++) {
			scanf("%d",&poss[i][j]);
		}
	}
	for(i=1;i<=R;i++) de1.push_back(root[i]);
	for(d=1;d<=R;d++) {
		for(j=1;j<=N;j++) {
			bool t=true;
			for(i=0;i<de1.size();i++) {	
				if(de1[i] != poss[j][i+1]) {
					t=false;
					break;
				}
			}
			if(t && !chk[j]) {
				chk[j]=1;
				cnt++;
			}
		}
		int da = de1.front();
		de1.pop_front();
		de1.push_back(da);
	}
	for(i=R;i>=1;i--) de3.push_back(root[i]);
	for(d=1;d<=R;d++) {
		for(j=1;j<=N;j++) {
			bool t=true;
			for(i=0;i<de3.size();i++) {	
				if(de3[i] != poss[j][i+1]) {
					t=false;
					break;
				}
			}
			if(t && !chk[j]) {
				chk[j]=1;
				cnt++;
			}
		}
		int da = de3.front();
		de3.pop_front();
		de3.push_back(da);
	}
	for(i=1;i<=R;i++) {
		if(root[i] == 1) root[i] = 3;
		else if(root[i] == 2) root[i] = 4;
		else if(root[i] == 3) root[i] = 1;
		else if(root[i] == 4) root[i] = 2;
	}
	for(i=1;i<=R;i++) de2.push_back(root[i]);
	for(d=1;d<=R;d++) {
		for(j=1;j<=N;j++) {
			bool t=true;
			for(i=0;i<de2.size();i++) {	
				if(de2[i] != poss[j][i+1]) {
					t=false;
					break;
				}
			}
			if(t && !chk[j]) {
				chk[j]=1;
				cnt++;
			}
		}
		int da = de2.front();
		de2.pop_front();
		de2.push_back(da);
	}
	for(i=R;i>=1;i--) de4.push_back(root[i]);
	for(d=1;d<=R;d++) {
		for(j=1;j<=N;j++) {
			bool t=true;
			for(i=0;i<de4.size();i++) {	
				if(de4[i] != poss[j][i+1]) {
					t=false;
					break;
				}
			}
			if(t && !chk[j]) {
				chk[j]=1;
				cnt++;
			}
		}
		int da = de4.front();
		de4.pop_front();
		de4.push_back(da);
	}
	printf("%d\n",cnt);
	for(i=1;i<=N;i++) {
		if(chk[i]) {
			for(j=1;j<=R;j++) {
				printf("%d ",poss[i][j]);
			}
			printf("\n");
		}
	}
}