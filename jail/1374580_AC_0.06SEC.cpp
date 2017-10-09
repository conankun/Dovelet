#include <iostream>
using namespace std;
int chk[111111];
int main()
{
    int n;
    cin>>n;
    int i,j;
    //0 open 1 closed
    int cnt=1;
    for(i=2;i<=n;i++) {
        if(chk[i]==0) {
            cnt++;
            for(j=i*2;j<=n;j+=i) chk[j]=1-chk[j];
        }
    }
    cout<<cnt;
}
