#include<iostream> 
#include<stdlib.h> 
using namespace std; 
struct A { 
    int clock[3][3]; 
    int index; 
    int arr[30]; 
    int now; 
}; 
A qu[1000000]={0}; 
int front = 0; 
int teal=0; 
A a,b; 
int vis[5][5][5][5][5][5][5][5][5]={0}; 
void change() { 
    int now = b.now; 
    if(now == 1) { 
        for(int i=0;i<2;i++) { 
            for(int j=0;j<2;j++) { 
                b.clock[i][j]++; 
                b.clock[i][j]%=4; 
                if(b.clock[i][j] == 0) b.clock[i][j] = 4; 
            } 
        } 
    } else if(now == 2) { 
        for(int i=0;i<3;i++) { 
            b.clock[0][i]++; 
            b.clock[0][i]%=4; 
            if(b.clock[0][i] == 0) b.clock[0][i] = 4; 
        } 
    } else if(now == 3) { 
        for(int i=0;i<2;i++) { 
            for(int j=1;j<3;j++) { 
                b.clock[i][j]++; 
                b.clock[i][j]%=4; 
                if(b.clock[i][j] == 0) b.clock[i][j] = 4; 
            } 
        } 
    } else if(now == 4) { 
        for(int i=0;i<3;i++) { 
            b.clock[i][0]++; 
            b.clock[i][0]%=4; 
            if(b.clock[i][0] == 0) b.clock[i][0] = 4; 
        } 
    } else if(now == 5) { 
        b.clock[0][1]++; 
        b.clock[0][1]%=4; 
        if(b.clock[0][1] == 0) b.clock[0][1] = 4; 
        b.clock[2][1]++; 
        b.clock[2][1]%=4; 
        if(b.clock[2][1] == 0) b.clock[2][1] = 4; 
        for(int i=0;i<3;i++) { 
            b.clock[1][i]++; 
            b.clock[1][i]%=4; 
            if(b.clock[1][i] == 0) b.clock[1][i] = 4; 
        } 
    } else if(now == 6) { 
        for(int i=0;i<3;i++) { 
            b.clock[i][2]++; 
            b.clock[i][2]%=4; 
            if(b.clock[i][2] == 0) b.clock[i][2] = 4; 
        } 
    } else if(now == 7) { 
        for(int i=1;i<3;i++) { 
            for(int j=0;j<2;j++) { 
                b.clock[i][j]++; 
                b.clock[i][j]%=4; 
                if(b.clock[i][j] == 0) b.clock[i][j] = 4; 
            } 
        } 
    } else if(now == 8) { 
        for(int i=0;i<3;i++) { 
            b.clock[2][i]++; 
            b.clock[2][i]%=4; 
            if(b.clock[2][i] == 0) b.clock[2][i] = 4; 
        } 
    } else if(now == 9) { 
        for(int i=1;i<3;i++) { 
            for(int j=1;j<3;j++) { 
                b.clock[i][j]++; 
                b.clock[i][j]%=4; 
                if(b.clock[i][j] == 0) b.clock[i][j] = 4; 
            } 
        } 
    } 
} 
bool Vis() { 
    if(vis[b.clock[0][0]][b.clock[0][1]][b.clock[0][2]][b.clock[1][0]][b.clock[1][1]][b.clock[1][2]][b.clock[2][0]][b.clock[2][1]][b.clock[2][2]] == 0) { 
        return true; 
    } 
    return false; 
} 
int main() { 
    a.index = 0; 
    a.now = 0; 
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) { 
        cin>>a.clock[i][j]; 
        a.clock[i][j]/=3; 
    } 
    qu[teal++]=a; 
    int cnt=0; 
    while(abs(teal-front) > 0) { 
            cnt++; 
            qu[front].arr[qu[front].index++]=qu[front].now; 
            for(int i=1;i<=9;i++) { 
                b = qu[front]; 
                b.now = i; 
                change(); 
                if(Vis()) { 
                    vis[b.clock[0][0]][b.clock[0][1]][b.clock[0][2]][b.clock[1][0]][b.clock[1][1]][b.clock[1][2]][b.clock[2][0]][b.clock[2][1]][b.clock[2][2]] = 1; 
                    bool t=true; 
                    for(int c=0;c<3;c++) for(int d=0;d<3;d++) if(b.clock[c][d] != 4) { t=false; break; } 
                    if(t) { 
                        for(int j=1;j<b.index;j++) cout<<b.arr[j]<<" "; 
                        cout<<i; 
                        return 0; 
                    } 
                    else
                    qu[teal++]=b; 
                } 
            } 
        front++; 
    } 
} 
 
