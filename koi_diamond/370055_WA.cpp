#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
struct A {
    int x,y;
};
int n,m,t,k;
int i,j,z;
A pos[10000]={0};
A posarr[1000000]={0};
int ind=0;
int main() {
    cin>>n>>m>>t>>k;
    for(i=0;i<t;i++) {
        cin>>pos[i].x>>pos[i].y;
        pos[i].x*=2;
        pos[i].y*=2;
    }
    n*=2;
    m*=2;
    k*=2;
    for(i=0;i<t;i++) {
        for(j=0;j<t;j++) {
            int xx = pos[i].x+(pos[j].x-pos[i].x)/2+(pos[j].y-pos[i].y)/2;
            int yy = pos[j].y+(pos[j].x-pos[i].x)/2+(pos[j].y-pos[i].y)/2;
 
            posarr[ind].x = xx;
            posarr[ind++].y = yy;
 
            posarr[ind].x = xx+k/2;
            posarr[ind++].y = yy;
 
            posarr[ind].x = xx;
            posarr[ind++].y = yy+k/2;
 
            posarr[ind].x = xx-k/2;
            posarr[ind++].y = yy;
 
            posarr[ind].x = xx;
            posarr[ind++].y = yy-k/2;
        }
    }
A rectpos;int c=0;for(i=0;i<ind;i++) {int cnt=0;for(j=0;j<t;j++) {if(abs(posarr[i].y-pos[j].y) <= k/2 && abs(pos[j].x-posarr[i].x) <= (k/2)-abs(posarr[i].y-pos[j].y)) {cnt++;}}if(cnt > c) {rectpos.x = posarr[i].x;rectpos.y = posarr[i].y;c=cnt;}}cout<<rectpos.x/2<<" "<<rectpos.y/2<<endl;cout<<c;}