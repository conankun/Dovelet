#include<iostream>
using namespace std;
int k,n;
char map[2000][30]={0};
bool x=false;
void ladder(int index) {
    int t=index;
    for(int i=0;i<n;i++) {
        if(map[i][t] == '?') {
            x=true;
            char c;
            int tt=t;
            for(int j=i+1;j<=n;j++) {
                c=map[j][tt];
                if(map[j][tt] == '-') {
                    tt = tt+1;
                } else if(map[j][tt-1] == '-') {
                    tt = tt-1;
                }
            }
 
            if(c == 'A'+index) {
                x = false;
                map[i][t]='*';  
                return;
            } else {
                tt=t+1;
                for(int j=i+1;j<=n;j++) {
                    c=map[j][tt];
                    if(map[j][tt] == '-') {
                        tt = tt+1;
                    } else if(map[j][tt-1] == '-') {
                        tt = tt-1;
                    }
                }
                if(c == 'A'+index) {
                    x = false;
                    map[i][t]='-';  
                    return;
                }
                tt=t-1;
                for(int j=i+1;j<=n;j++) {
                    c=map[j][tt];
                    if(map[j][tt] == '-') {
                        tt = tt+1;
                    } else if(map[j][tt-1] == '-') {
                        tt = tt-1;
                    }
                }
                if(c == 'A'+index) {
                    x = false;
                    map[i][t-1]='-';    
                }
            }
        return;
        } else {
            if(map[i][t] == '-') {
                t = t+1;
            } else if(map[i][t-1] == '-') {
                t = t-1;
            }
        }
    }
}
int main() {
    int index_;
    cin>>k>>n;
    cin>>map[n];
    for(int i=0;i<n;i++) {
        cin>>map[i];
        map[i][k] = '*';
        if(map[i][0] == '?') index_ = i;
    }
    for(int i=0;i<k;i++) {
        if(!x) {
            ladder(i);
        }
    }
    if(x) {
        for(int i=0;i<k-1;i++) {
             cout<<'x';
        }
    } else {
        for(int i=0;i<k-1;i++) {
            if(map[index_][i] == '?') map[index_][i] = '*';
            cout<<map[index_][i];
        }
    }
}