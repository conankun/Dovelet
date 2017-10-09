#include<iostream>
using namespace std;
int f,m,n;
int vis[100]={0};
int tvis[100]={0};
bool t=false;
struct A {int fi,mi;};
A arr[100]={0};
double mx = 0.00;
void DFS(int level,int sumf,int summ,int index) {if(sumf/(double)summ > mx) {for(int i=0;i<100;i++) {tvis[i]=vis[i];}mx = sumf/(double)summ;}for(int i=index+1;i<n;i++) {if(sumf/(double)summ < sumf+arr[i].fi/(double)(summ+arr[i].mi)) {vis[i]=1;DFS(level+1,sumf+arr[i].fi,summ+arr[i].mi,i);vis[i]=0;}}}int main() {cin>>f>>m>>n;for(int i=0;i<n;i++) {cin>>arr[i].fi>>arr[i].mi;}DFS(0,f,m,-1);for(int i=0;i<n;i++) {if(tvis[i] == 1) {cout<<i+1<<endl;t=true;}}if(!t) cout<<"NONE";}