#include<iostream> 
#include<algorithm> 
using namespace std; 
int n,m; 
int icebreg[301][301]={0,}; 
int check[301][301]={0,}; 
int visted[301][301]={0,}; 
int notzero=0; 
int notzeroDFS=0; 
void DFS(int i,int j) { 
    if(i<1 || j<1) return; 
    if(i>n || j > m) return; 
    if(icebreg[i][j] == 0) return; 
    if(icebreg[i][j] !=0 && check[i][j] == 0) { 
        notzeroDFS++; 
        check[i][j] = 1; 
    } 
    visted[i][j]=1; 
    int temp=icebreg[i][j]; 
    icebreg[i][j]=0; 
    if(icebreg[i+1][j] != 0 && visted[i+1][j] == 0) DFS(i+1,j); 
    if(icebreg[i-1][j] != 0 && visted[i-1][j] == 0) DFS(i-1,j); 
    if(icebreg[i][j-1] != 0 && visted[i][j-1] == 0) DFS(i,j-1); 
    if(icebreg[i][j+1] != 0 && visted[i][j+1] == 0) DFS(i,j+1); 
    icebreg[i][j]=temp; 
    return; 
} 
  
  
int main() { 
    cin>>n>>m; 
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>icebreg[i][j]; 
    for(int y=1;;y++) { 
        notzero=0; 
        notzeroDFS=0; 
        for(int i=0;i<301;i++) fill(check[i],check[i]+301,0); 
        for(int i=0;i<301;i++) fill(visted[i],visted[i]+301,0); 
        int minus[301][301]={0,}; 
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=m;j++) { 
                if(icebreg[i][j+1] == 0) minus[i][j]++; 
                if(icebreg[i][j-1] == 0) minus[i][j]++; 
                if(icebreg[i+1][j] == 0) minus[i][j]++; 
                if(icebreg[i-1][j] == 0) minus[i][j]++; 
            } 
        } 
  
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=m;j++) { 
                icebreg[i][j]-=minus[i][j]; 
                if(icebreg[i][j] < 0) icebreg[i][j]=0; 
                if(icebreg[i][j] != 0) notzero++; 
            } 
        } 
  
        if(notzero == 0) { 
            cout<<0; 
            return 0; 
        } 
  
        for(int i=1;i<=n;i++) { 
            bool a=false; 
            for(int j=1;j<=m;j++) { 
                if(icebreg[i][j] != 0) { 
                    DFS(i,j); 
                    if(notzeroDFS < notzero) { 
                        cout<<y; 
                        return 0; 
                    } 
                a=true; 
                break; 
                } 
            } 
        if(a)break; 
        } 
  
    } 
}