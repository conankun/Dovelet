#include <iostream> 
using namespace std; 
unsigned long long C(int n,int r) { 
    unsigned long long bc[101][101]; 
    for(int i=0;i<=n;i++) bc[i][0]=1; 
    for(int j=0;j<=n;j++) bc[j][j]=1; 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<i;j++) { 
            bc[i][j] = bc[i-1][j-1]+bc[i-1][j]; 
        } 
    } 
    return bc[n][r]; 
} 
int main() { 
    int a,b; 
    cin>>a>>b; 
    printf("%d things taken %d at a time is %llu exactly.",a,b,C(a,b)); 
} 
 
