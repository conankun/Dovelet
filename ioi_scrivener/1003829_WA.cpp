#include <iostream>
using namespace std;
int n;
char deq[10000000];
int f=1,r;
struct A {
    int x;
    char c;
} commands[10000000];
int ind;
int main()
{
  //  scanf("%d\n",&n);
    cin>>n;
    int i,j,k;
    for(i=1;i<=n;i++) {
        char c;
        int s;
        //scanf("%c\n",&c);
        cin>>c;
        if(c=='T') {
           // scanf("%c\n",&c);
            cin>>c;
            deq[++r]=c;
            commands[++ind].c='T';
            commands[ind].x=c;
        } else if(c=='U') {
           // scanf("%d\n",&s);
            cin>>s;
            for(j=ind;j>=ind-s+1;j--) {
                if(commands[j].c=='T') {
                    r--;
                } else if(commands[j].c=='U') {
                    for(k=j-commands[j].x;k<=j;k++) {
                        deq[++r]=(char)commands[k].x;
                    }
                    j=j-k;
                }
            }
            ind++;
            commands[ind].c='U';
            commands[ind].x=s;
        } else {
            //scanf("%d\n",&s);
            cin>>s;
            printf("%c\n",deq[f+s]);
        }
    }
    return 0;
}