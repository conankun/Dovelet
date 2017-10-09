#include<iostream> 
using namespace std; 
int map[20][20]={0}; 
bool omok(int i,int j) { 
    if(map[i-1][j] != map[i][j]) { 
        int cnt=1; 
        for(int k=i+1;k<=19;k++) { 
            if(map[k][j] == map[i][j]) cnt++; 
            else break; 
        } 
        if(cnt == 5) return true; 
    } 
    if(map[i][j-1] != map[i][j]) { 
        int cnt=1; 
        for(int k=j+1;k<=19;k++) { 
            if(map[i][k] == map[i][j]) cnt++; 
            else break; 
        } 
        if(cnt == 5) return true; 
    } 
    if(map[i-1][j-1] != map[i][j]) { 
        int cnt=1; 
        for(int k=1;;k++) { 
            if(i+k > 19 || j+k > 19) break; 
            if(map[i+k][j+k] == map[i][j]) cnt++; 
            else break; 
        } 
        if(cnt == 5) return true; 
    } 
    if(map[i+1][j-1] != map[i][j]) { 
        int cnt=1; 
        for(int k=1;;k++) { 
            if(i-k < 1 || j+k > 19) break; 
            if(map[i-k][j+k] == map[i][j]) cnt++; 
            else break; 
        } 
        if(cnt == 5) return true; 
    } 
    return false; 
} 
int main() { 
    for(int i=1;i<=19;i++) for(int j=1;j<=19;j++) cin>>map[i][j]; 
    for(int i=1;i<=19;i++) { 
        for(int j=1;j<=19;j++) { 
            if(map[i][j]!=0) { 
                if(omok(i,j)) { 
                    cout<<map[i][j]<<endl<<i<<" "<<j; 
                    return 0; 
                } 
            } 
        } 
    } 
cout<<0; 
} 
 
