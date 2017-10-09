#include <stdio.h>
int a[100][100];
int b[100][100];
int main()
{
    int i,j;
    for(i=1;i<=5;i++) {
        for(j=1;j<=5;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=5;i++) {
        a[0][i]=9999999;
        a[i][0]=9999999;
        a[6][i]=9999999;
        a[i][6]=9999999;
    }
    
    for(i=1;i<=5;i++) {
        for(j=1;j<=5;j++) {
            if(a[i][j] < a[i+1][j] && a[i][j]<a[i-1][j] && a[i][j] < a[i][j+1] && a[i][j] < a[i][j-1]) {
                b[i][j]=-1;
            }
        }
    }
    for(i=1;i<=5;i++) {
        for(j=1;j<=5;j++) {
            if(b[i][j]==-1) {
                printf("* ");
            } else {
                printf("%d ",a[i][j]);
            }
        }
        printf("\n");
    }
}

