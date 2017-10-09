#include<stdio.h>
int n,m,k;
int map[1701][1701];
int r1[1701][1701];
int rect[1701][1701];
int w[4][1701][1701];
int h[4][1701][1701];
int updown[2001];
int ans;
int main() {
    scanf("%d%d%d",&n,&m,&k);
    int i,j;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            scanf("%d",&map[i][j]);
        }
    }
    for(j=1;j<=m;j++) {
        int s=0;
        for(i=1;i<=k;i++) {
            s+=map[i][j];
        }
        r1[k][j]=s;
        for(i=k+1;i<=n;i++) {
            s-=map[i-k][j];
            s+=map[i][j];
            r1[i][j]=s;
        }
    }
    for(i=k;i<=n;i++) {
        int s=0;
        for(j=1;j<=k;j++) s+=r1[i][j];
        rect[i][k]=s;
        for(j=k+1;j<=m;j++) {
            s-=r1[i][j-k];
            s+=r1[i][j];
            rect[i][j]=s;
        }
    }
    for(j=1;j<=m;j++) {
        int s=0;
        for(i=1;i<=n;i++) {
            s=rect[i][j];
            if(s < h[0][i-1][j]) s=h[0][i-1][j];
            h[0][i][j]=s;
        }
        for(i=n;i>=1;i--) {
            s=rect[i+k-1][j];
            if(s < h[1][i+1][j]) s = h[1][i+1][j];
            h[1][i][j]=s;
        }
    }
    for(j=m;j>=1;j--) {
        int s=0;
        for(i=1;i<=n;i++) {
            s=rect[i][j+k-1];
            if(s < h[2][i-1][j]) s=h[2][i-1][j];
            h[2][i][j]=s;
        }
        for(i=n;i>=1;i--) {
            s=rect[i+k-1][j+k-1];
            if(s < h[3][i+1][j]) s = h[3][i+1][j];
            h[3][i][j]=s;
        }
    }
    for(i=1;i<=n;i++) {
        int s=0;
        for(j=k;j<=m;j++) {
            s=rect[i][j];
            if(s < w[0][i][j-1]) s=w[0][i][j-1];
            w[0][i][j]=s;
        }
        for(j=m;j>=1;j--) {
            s=rect[i][j+k-1];
            if(s < w[1][i][j+1]) s=w[1][i][j+1];
            w[1][i][j]=s;
        }
    }
    for(i=n;i>=1;i--) {
        int s=0;
        for(j=1;j<=m;j++) {
            s=rect[i+k-1][j];
            if(s < w[2][i][j-1]) s=w[2][i][j-1];
            w[2][i][j]=s;
        }
        for(j=m;j>=1;j--) {
            s=rect[i+k-1][j+k-1];
            if(s < w[3][i][j+1]) s=w[3][i][j+1];
            w[3][i][j]=s;
        }
    }
    int tr=0;
    for(j=k;j<=m;j++) {
        if(h[0][n][j] > tr) tr = h[0][n][j];
        updown[k-1]=0;
        for(i=k;i<=n;i++) {
            updown[i]=w[1][i][j+1];
            if(updown[i-1] > updown[i]) updown[i]=updown[i-1];
        }
        int s=0;
        for(i=n-k+1;i>=k+1;i--) {
            if(w[3][i][j+1] > s) s = w[3][i][j+1];
            if(tr+updown[i-1]+s > ans) ans = tr+updown[i-1]+s;
        }
    }
    tr=0;
    for(j=k;j<=m;j++) {
        if(h[0][n][j] > tr) tr = h[0][n][j];
        updown[j+k-1]=0;
        for(i=j+k;i<=m;i++) {
            updown[i]=h[0][n][i];
            if(updown[i-1] > updown[i]) updown[i]=updown[i-1];
        }
        int s=0;
        for(i=m;i>=1;i--) {
            if(s < h[2][n][i]) s = h[2][n][i];
            if(tr+updown[i-1]+s > ans) ans = tr+updown[i-1]+s;
        }
    }
    tr=0;
    for(j=m-k+1;j>=k+1;j--) {
        if(h[2][n][j] > tr) tr = h[2][n][j];
        updown[k-1]=0;
        for(i=k;i<=n;i++) {
            updown[i]=w[0][i][j-1];
            if(updown[i] < updown[i-1]) updown[i]=updown[i-1];
        }
        int s=0;
        for(i=n-k+1;i>=k+1;i--) {
            if(s < w[2][i][j-1]) s = w[2][i][j-1];
            if(s+updown[i-1]+tr > ans) ans = s+updown[i-1]+tr;
        }
    }
    tr=0;
    for(i=k;i<=n-k;i++) {
        if(tr<w[0][i][m])tr=w[0][i][m];
        updown[k-1]=0;
        for(j=k;j<=m;j++) {
            updown[j]=h[1][i+1][j];
            if(updown[j] < updown[j-1]) updown[j]=updown[j-1];
        }
        int s=0;
        for(j=m-k+1;j>=k+1;j--) {
            if(h[3][i+1][j] > s) s = h[3][i+1][j];
            if(tr+updown[j-1]+s > ans) ans = tr+updown[j-1]+s;
        }
    }
    tr=0;//
    for(i=n;i>=1;i--) {
        if(tr<w[2][i][m])tr=w[2][i][m];
        updown[k-1]=0;
        for(j=k;j<=m;j++) {
            updown[j]=h[0][i-1][j];
            if(updown[j] < updown[j-1]) updown[j]=updown[j-1];
        }
        int s=0;
        for(j=m;j>=k+1;j--) {
            if(h[2][i-1][j] > s) s = h[2][i-1][j];
            if(tr+updown[j-1]+s > ans) ans = tr+updown[j-1]+s;   
        }
    }
    tr=0;
    for(i=k;i<=n;i++) {
        updown[i+k-1]=0;
        if(tr<w[0][i][m])tr=w[0][i][m];
        for(j=i+k;j<=n;j++) {
            updown[j]=w[0][j][m];
            if(updown[j]<updown[j-1]) updown[j]=updown[j-1];
        }
        int s=0;
        for(j=n;j>=1;j--) {
            if(w[2][j][m] > s) s = w[2][j][m];
            if(s+updown[j-1]+tr > ans) ans = s+updown[j-1]+tr;
        }
    }
    printf("%d",ans);
    fclose(stdout);
    return 0;
}