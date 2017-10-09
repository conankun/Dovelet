#include <iostream>
using namespace std;
//n-1
//-=2
int main()
{
    int n,m;
    cin>>n>>m;
    int a=1;
    int b=n-1;
    int i;
    for(i=1;i<=m;i++) {
        a+=b;
        b-=2;
    }
    cout<<a;
}
