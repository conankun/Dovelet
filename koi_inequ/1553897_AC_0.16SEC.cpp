#include<stdio.h>
#include<string.h>
char s[1000];
long long number;
long long mx=0,mn=199999999999LL;
bool isRight(int M,int N,int inequ) {
    if(s[inequ]=='>') {
        if(M>N) return true;
        return false;
    } else {
        if(M<N) return true;
        return false;
    }
}
int bt[100];
int vs[100];
void backtracking(long long N,int level) {
    int i;
    if(N==9 && level==2) {
        N=N;
    }
    for(i=1;i<=level-1;i++) {
        bool t=isRight(bt[i],bt[i+1],i-1);
        if(!t) return;
    }
    if(level==number) {
        if(N > mx) mx=N;
        if(N < mn) mn=N;
        return;
    } else {
        for(i=0;i<10;i++) {
            if(vs[i]==1) continue;
            bt[level+1]=i;
            vs[i]=1;
            backtracking(N*10+i,level+1);
            bt[level+1]=0;
            vs[i]=0;
        }
    }
}
int main() {
    long long n;
    scanf("%lld\n",&n);
    int i;
    for(i=0;i<n;i++) scanf("%c ",&s[i]);
    number=strlen(s)+1;
    backtracking(0,0);
    switch(n) {
    case 2:printf("%03lld\n%03lld",mx,mn);break;
    case 3:printf("%04lld\n%04lld",mx,mn);break;
    case 4:printf("%05lld\n%05lld",mx,mn);break;
    case 5:printf("%06lld\n%06lld",mx,mn);break;
    case 6:printf("%07lld\n%07lld",mx,mn);break;
    case 7:printf("%08lld\n%08lld",mx,mn);break;
    case 8:printf("%09lld\n%09lld",mx,mn);break;
    case 9:printf("%010lld\n%010lld",mx,mn);break;
    default:printf("");break;
    }
}