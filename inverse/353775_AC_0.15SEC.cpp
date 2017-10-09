#include<iostream>
using namespace std;
char now[5][5]={0};
int bt[1000]={0};
int vis[1000]={0};
bool f =false;
void DFS(int a,int index) {
    char r[5][5]={0};
    vis[a]=1;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) r[i][j]=now[i][j];
    bool t = true;
        if(a == 1) {
            for(int i=0;i<=1;i++) {
                for(int j=0;j<=1;j++) {
                    if(now[i][j] == 'b')  now[i][j]='w';
                    else  now[i][j]='b';
                }
            }
        } else if(a == 2) {
            for(int i=0;i<=1;i++) {
                for(int j=0;j<=2;j++) {
                    if(now[i][j] == 'b')  now[i][j]='w';
                    else  now[i][j]='b';
                }
            }
        } else if(a == 3) {
            for(int i=0;i<=1;i++) {
                for(int j=1;j<=2;j++) {
                    if( now[i][j] == 'b')  now[i][j]='w';
                    else  now[i][j]='b';
                }
            }
        } else if(a == 4) {
            for(int i=0;i<=2;i++) {
                for(int j=0;j<=1;j++) {
                    if( now[i][j] == 'b')  now[i][j]='w';
                    else  now[i][j]='b';
                }
            }
        } else if(a == 5) {
            for(int i=0;i<=2;i++) {
                for(int j=0;j<=2;j++) {
                    if( now[i][j] == 'b')  now[i][j]='w';
                    else  now[i][j]='b';
                }
            }
        } else if(a == 6) {
            for(int i=0;i<=2;i++) {
                for(int j=1;j<=2;j++) {
                    if( now[i][j] == 'b')  now[i][j]='w';
                    else  now[i][j]='b';
                }
            }
        } else if(a == 7) {
            for(int i=1;i<=2;i++) {
                for(int j=0;j<=1;j++) {
                    if( now[i][j] == 'b')  now[i][j]='w';
                    else  now[i][j]='b';
                }
            }
        } else if(a == 8) {
            for(int i=1;i<=2;i++) {
                for(int j=0;j<=2;j++) {
                    if( now[i][j] == 'b')  now[i][j]='w';
                    else  now[i][j]='b';
                }
            }
        } else if(a == 9) {
            for(int i=1;i<=2;i++) {
                for(int j=1;j<=2;j++) {
                    if( now[i][j] == 'b')  now[i][j]='w';
                    else  now[i][j]='b';
                }
            }
        }
 
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(now[i][j] != 'w') t=false;
    if(t) {
        f=true;
        for(int i=0;i<=index-1;i++) {
            cout<<bt[i];
        }
        cout<<a<<endl;
    } else {
        if(a != 0) bt[index]=a;
        for(int i=1;i<=9;i++) {
            if(vis[i] == 0 && !f) DFS(i,index+1);
        }
    }
    //복구
        if(a == 1) {
            for(int i=0;i<=1;i++) {
                for(int j=0;j<=1;j++) {
                    if(now[i][j] == 'b')  now[i][j]=r[i][j];
                    else  now[i][j]=r[i][j];
                }
            }
        } else if(a == 2) {
            for(int i=0;i<=1;i++) {
                for(int j=0;j<=2;j++) {
                    now[i][j]=r[i][j];
                }
            }
        } else if(a == 3) {
            for(int i=0;i<=1;i++) {
                for(int j=1;j<=2;j++) {
                    now[i][j]=r[i][j];
                }
            }
        } else if(a == 4) {
            for(int i=0;i<=2;i++) {
                for(int j=0;j<=1;j++) {
                    now[i][j]=r[i][j];
                }
            }
        } else if(a == 5) {
            for(int i=0;i<=2;i++) {
                for(int j=0;j<=2;j++) {
                    now[i][j]=r[i][j];
                }
            }
        } else if(a == 6) {
            for(int i=0;i<=2;i++) {
                for(int j=1;j<=2;j++) {
                    now[i][j]=r[i][j];
                }
            }
        } else if(a == 7) {
            for(int i=1;i<=2;i++) {
                for(int j=0;j<=1;j++) {
                    now[i][j]=r[i][j];
                }
            }
        } else if(a == 8) {
            for(int i=1;i<=2;i++) {
                for(int j=0;j<=2;j++) {
                     now[i][j]=r[i][j];
                }
            }
        } else if(a == 9) {
            for(int i=1;i<=2;i++) {
                for(int j=1;j<=2;j++) {
                    now[i][j]=r[i][j];
                }
            }
        }
        bt[index]=0;
        vis[a]=0;
}
int main() {
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>now[i][j];
        f=false;
        DFS(0,-1);
}