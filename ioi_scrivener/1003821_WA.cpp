#include <iostream>
using namespace std;
int n;
char deq[10000001];
int f=1,r;
int main()
{
    scanf("%d\n",&n);
    int i;
    for(i=1;i<=n;i++) {
        char c;
        int s;
        scanf("%c\n",&c);
        if(c=='T') {
            scanf("%c\n",&c);
            deq[++r]=c;
        } else if(c=='U') {
            scanf("%d\n",&s);
            r-=s;
            if(r<0) {
                f=1;r=0;
            }
        } else if(c=='P') {
            scanf("%d\n",&s);
            printf("%c\n",deq[f+s]);
        }
    }
    return 0;
}