#include <iostream>
using namespace std;
int chk[1111][1111];
int main()
{
    int R,C;
    cin>>C>>R;
    int K;
    cin>>K;
    int cnt=1;
    int x=1,y=1;
    int i;
    for(i=0;i<=R;i++) chk[i][0]=1;
    for(i=0;i<=R;i++) chk[i][C+1]=1;
    for(i=0;i<=C;i++) chk[0][i]=1;
    for(i=0;i<=C;i++) chk[R+1][i]=1;
    int turn=0;//0 아래 2 위 3 왼 1 오
    while(cnt <= R*C) {
        if(cnt==K) {
            printf("%d %d",x,y);
            return 0;
        }
        chk[y][x]=1;
        int yy=y,xx=x;
        if(turn == 0) {
            yy++;
        } else if(turn ==1) {
            xx++;
        } else if(turn == 2) {
            yy--;
        } else if(turn == 3) {
            xx--;
        }
        if(chk[yy][xx] == 1) turn++;
        if(turn > 3) turn=0;
        if(turn == 0) {
            y++;
        } else if(turn ==1) {
            x++;
        } else if(turn == 2) {
            y--;
        } else if(turn == 3) {
            x--;
        }
        cnt++;
        
    }
    printf("0");
}

