#include <iostream>
#include<math.h>
using namespace std;
int tree[10000];
int n,limit;
void dfs(int index) {
    if(index==0) return;
    if(index >= limit) return;
    dfs(index*2);
    scanf("%d",&tree[index]);
    dfs(index*2+1);
    //dfs(index/2);
}
int main(){
    cin>>n;
    limit = pow(2,n);
    dfs(1);
    int i,j;
    cout<<tree[1]<<endl;
    for(i=2;i<=n;i++) {
        for(j=0;j<pow(2,i-1);j++) {
            cout<<tree[(i-1)*2+j]<<" ";
        }
        cout<<endl;
    }
}
