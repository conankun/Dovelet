#include<stdio.h>
#include<vector>
using namespace std;
int M,N,SEQ[1111111],S[1111111],pp[1111111],chk[1111111],size;
vector<int> ve[1111111];
int main() {
	int d,i,j;
	scanf("%d",&M);
	for(i=1;i<=M;i++) {
		scanf("%d",&SEQ[i]);
		ve[SEQ[i]].push_back(i);
	}
	scanf("%d",&N);
	for(d=1;d<=N;d++) {
		int LEN;
		scanf("%d",&LEN);
		for(i=1;i<=LEN;i++) scanf("%d",&S[i]);
		int p=1;
		int before=0;
		bool ttt=1;
		for(i=1;i<=LEN;i++) {
			if(chk[S[i]] != d) {
				chk[S[i]]=d;
				pp[S[i]]=0;
			}
			int low=pp[S[i]];
			int high=ve[S[i]].size()-1;
			int mid;
			int gogogo=-1,ind=-1;
			while(low<=high) {
				mid=(low+high)/2;
				if(ve[S[i]][mid] > before) {
					if(gogogo > ve[S[i]][mid] || gogogo==-1) {
						gogogo=ve[S[i]][mid];
						ind=mid;
					}
					high=mid-1;
				} else {
					low=mid+1;
				}
			}
			if(gogogo == -1) {
				ttt=0;
				break;
			}
			before = gogogo;
			pp[S[i]]=ind+1;
		}
		if(ttt) printf("YES\n");
		else printf("NO\n");
	}
}