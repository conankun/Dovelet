#include <iostream>
using namespace std;
int arr[100001];
int minn=2147483647,maxn=0;
int main () {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i] < minn) minn = arr[i];
        else if(arr[i] > maxn) maxn = arr[i];
    }
    cout<<maxn<<" "<<minn;
    return 0;
}