#include<iostream>
#include<algorithm>
using namespace std;
int a;
int c[111][111]={0,};
int d[111][111]={0,};
int cnt=0;
int maxcnt=0;
void DFS(int h,int i,int j) {
    if(i<1 || j<1) return;
    if(i>a || j > a) return;
    if(c[i][j] <= h) return;
 
    if(c[i][j] > h && d[i][j] == 0) d[i][j] = cnt;
 
    if(c[i+1][j] > h && d[i+1][j] == 0) DFS(h,i+1,j);
    if(c[i-1][j] > h && d[i-1][j] == 0) DFS(h,i-1,j);
    if(c[i][j-1] > h && d[i][j-1] == 0) DFS(h,i,j-1);
    if(c[i][j+1] > h && d[i][j+1] == 0) DFS(h,i,j+1);
 
    return;
}
 
int main() {
    cin>>a;
    int max=0;
    for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) {
        cin>>c[i][j];
        if(c[i][j] > max) max = c[i][j];
    }
     
    for(int h=0;h<=max;h++) {
    cnt=0;
    for(int i=0;i<=110;i++) fill(d[i],d[i]+111,0);
    for(int i=1;i<=a;i++) {
        for(int j=1;j<=a;j++) {
            if(c[i][j] > h && d[i][j] == 0) {
            cnt++;  
            DFS(h,i,j);
            } else continue;
        }
    }
 
    if(cnt > maxcnt) maxcnt = cnt;
     
    }
 
    cout<<maxcnt;
}