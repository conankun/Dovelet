#include<iostream>
using namespace std;
long long n,m,l;
long long i,j,k,k2;
long long dp[100][100],dp2[100];
long long bit[100];
long long max(long long a,long long b) {
	if(a > b) return a;
	return b;
}
long long min(long long a,long long b) {
	if(a > b) return b;
	return a;
}
int C(long long a,long long b) {//aCb
    int c[100][100]={0};
    for(k=0;k<=a;k++) {
        c[k][0]=1;
        c[k][k]=1;
    }
    for(k=1;k<=a;k++) {
        for(k2=1;k2<k;k2++) {
            c[k][k2] = c[k-1][k2-1]+c[k-1][k2];
        }
    }
    return c[a][b];
}
bool tr=false;
long long dd[100][100]={0};
long long dp3[100]={0};
void bt(long long level,long long d,long long e) {
    if(level <= 0) {
           tr=true;
           for(i=n;i>=1;i--) {
               cout<<bit[i];
           }
        return;
    }
	for(i=0;i<100;i++) for(j=0;j<100;j++) dd[i][j]=0;
	for(i=0;i<100;i++) dp3[i]=0;
    dd[0][0]=1;
    for(i=1;i<=level;i++) { 
        dd[i][0]=1;
        for(j=1;j<min(i,e);j++) {
            dd[i][j] += C(i-1,j);
        }
    }
    long long s=d;
    for(i=0;i<=level;i++) {
        for(j=0;j<=min(i,e);j++) {
            if(s-dd[i][j] <= 0) {
                bit[i]=1;
                if(!tr) bt(i-1,d-dp3[i-1],e-1);
                bit[i]=0;
            } else s-=dd[i][j];
            dp3[i]+=dd[i][j];
        }
        if(i > 0) dp3[i]+=dp3[i-1];
    }
}
int main() {
    cin>>n>>m>>l;
    dp[0][0]=1;
    for(i=1;i<=n;i++) {
        dp[i][0]=1;
        for(j=1;j<=min(i,m-1);j++) {
            dp[i][j] += C(i-1,j);
        }
    }
    long long s=l;
    for(i=0;i<=n;i++) {
        for(j=0;j<=min(i,m);j++) {
            if(s-dp[i][j] <= 0) {
                bit[i]=1;
                if(!tr) bt(i-1,l-dp2[i-1],max(0,m-1));
                bit[i]=0;
		} else s-=dp[i][j];
			dp2[i]+=dp[i][j];
		}
		dp2[i]+=dp2[i-1];
	}
}
