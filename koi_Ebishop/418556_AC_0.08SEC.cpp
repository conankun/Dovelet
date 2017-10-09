#include<stdio.h>
int n;
int map[100][100];
int graph[100][100];
int vis[100];
int path[200];
int pathind;
int cnt;
bool max(bool a,bool b){
if(a<b) return b;
return a;
}
bool dfs(int ind) {
bool tr=0;
if(ind==4*n){
int i;
cnt++;
for(i=1;i<=pathind-1;i++){
graph[path[i]][path[i+1]]=0;
graph[path[i+1]][path[i]]=1;
}
return true;
} else {
int i;
for(i=0;i<=4*n;i++) {
if(graph[ind][i]==1 && vis[i]==0){
vis[i]=1;
path[++pathind]=i;
tr=max(tr,dfs(i));
path[--pathind]=0;
if(tr) return tr;
}
}
}
return tr;
}
void nf(){
int i;
path[++pathind]=0;
vis[0]=1;
while(dfs(0)) {
for(i=0;i<=4*n;i++) {
vis[i]=0;
}
pathind=1;
path[pathind]=0;
vis[0]=1;
}
}
int main() {
scanf("%d",&n);
int i,j;
for(i=1;i<=n;i++) {
for(j=1;j<=n;j++){
scanf("%d",&map[i][j]);
}
}
for(i=1;i<=n;i++) {
for(j=1;j<=n;j++){
if(map[i][j]==1) {
graph[0][i+j-1]=1;
graph[i+j-1][2*n+n-j+i]=1;
graph[2*n+n-j+i][4*n]=1;
}
}
}
nf();
printf("%d",cnt);
}