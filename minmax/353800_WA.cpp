#include <iostream>
#include <algorithm>
using namespace std;
int main() {int n;cin>>n;int a;int arr[10];for(int i=0;i<n;i++) {cin>>a;for(int i=0;i<10;i++) cin>>arr[i];sort(arr,arr+10);cout<<a<<" "<<arr[7]<<endl;}}