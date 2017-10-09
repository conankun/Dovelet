#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n,c;
struct A {
    int n,frq,loc;
}arr[10000];
bool cmp(A a, A b) {
    if(a.frq == b.frq) {
        return a.loc < b.loc;
    }
    return a.frq > b.frq;
}
map<int,int> mp1;//loc
map<int,int> mp2;//loc
int main()
{
    cin>>n>>c;
    int i;
    for(i=1;i<=n;i++) {
        cin>>arr[i].n;
        mp1[arr[i].n]++;
        if(mp2[arr[i].n]!=0) {
            continue;
        } else mp2[arr[i].n]=i;
    }
    for(i=1;i<=n;i++) {
        arr[i].frq = mp1[arr[i].n];
        arr[i].loc = mp2[arr[i].n];
    }
    sort(arr+1,arr+1+n,cmp);
    for(i=1;i<=n;i++) cout<<arr[i].n<<" ";
}
