#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
bool cmp(int x,int y) {
    return abs(x) < abs(y);
}
 
int arr[100001];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,cmp); 
    int min = 2147483647;
    int a,b;
    for(int i=0;i<n-1;i++) {
        if(abs(arr[i]+arr[i+1]) < min) {
         
            min = abs(arr[i]+arr[i+1]);
         
            a = arr[i];
            b = arr[i+1];
        }
    }
     
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
 
    cout<<a<<" "<<b;
}