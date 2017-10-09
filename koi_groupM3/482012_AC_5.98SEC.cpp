#include<stdio.h>
int edge[3011][3011];
int A[3011][3011];//k~i , 모르는 갯수(i,k)
int B[3011][3011];//i~k', 아는 갯수(i,k)
int S1[3011][3011]; //모르는 갯수 합
int S2[3011][3011]; // 아는 갯수 합
int all[3011];
int dp[3011];
int back[3011];
int N;
int push[3011];
int index;
int main() {
	int i,j;
	int aa,bb,cc,dd,ee,ff,gg,hh,ii,jj;
	scanf("%d",&N);
	i=1;
	while(scanf("%d %d %d %d %d %d %d %d %d %d",&aa,&bb,&cc,&dd,&ee,&ff,&gg,&hh,&ii,&jj) != -1) {
		if(aa==0) i++;
		else {
			edge[i][aa]=1;
			if(aa>i)all[i]++;
		}
		if(bb==0) i++;
		else {
			edge[i][bb]=1;
			if(bb>i)all[i]++;
		}
		if(cc==0) i++;
		else {
			edge[i][cc]=1;
			if(cc>i)all[i]++;
		}
		if(dd==0) i++;
		else {
			edge[i][dd]=1;
			if(dd>i)all[i]++;
		}
		if(ee==0) i++;
		else {
			edge[i][ee]=1;
			if(ee>i)all[i]++;
		}
		if(ff==0) i++;
		else {
			edge[i][ff]=1;
			if(ff>i)all[i]++;
		}
		if(gg==0) i++;
		else {
			edge[i][gg]=1;
			if(gg>i)all[i]++;
		}
		if(hh==0) i++;
		else {
			edge[i][hh]=1;
			if(hh>i)all[i]++;
		}
		if(ii==0) i++;
		else {
			edge[i][ii]=1;
			if(ii>i)all[i]++;
		}
		if(jj==0) i++;
		else {
			edge[i][jj]=1;
			if(jj>i)all[i]++;
		}
		aa=0,bb=0,cc=0,dd=0,ee=0,ff=0,gg=0,hh=0,ii=0,jj=0;
	}
	for(i=1;i<=N;i++) { // i ~ k
		for(j=i+1;j<=N;j++) {
			A[i][j] = A[i][j-1]+(1-edge[i][j]);
			B[i][j] = B[i][j-1]+edge[i][j];
		}
	}
	for(j=1;j<=N;j++) {
		for(i=j-1;i>=1;i--) {
			S1[i][j] = S1[i+1][j]+A[i][j];
			S2[i][j] = S2[i+1][j]+B[i][j];
		}
	}
	for(i=1;i<=N;i++) all[i] = all[i-1]+all[i];
	for(i=1;i<=N;i++) {
		dp[i]=99999999;
		for(j=1;j<=i;j++) {
			if(dp[j-1]+S1[j][i]+(all[i]-all[j-1])-S2[j][i] < dp[i]) {
				dp[i] = dp[j-1]+S1[j][i]+(all[i]-all[j-1])-S2[j][i];
				back[i] = j-1;
			}
		}
	}
	printf("%d\n",dp[N]);
	push[++index]=N;
	int bt = back[N];
	while(bt>0) {
		push[++index]=bt;
		bt = back[bt];
	}
	printf("%d ",index);
	for(i=index;i>=1;i--) printf("%d ",push[i]-push[i+1]);
	
}