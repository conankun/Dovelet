#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    int arr[1000];
    int sortarr[1000];
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sortarr[i] = arr[i];
    }
    sort(sortarr,sortarr+n);
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(arr[i] != sortarr[i]) {
            for(int j=0;j<n;j++) {
                if(i != j && (sortarr[i] == arr[j] && sortarr[j] == arr[i])) {
                    cnt++;
                    int t=arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                    break;
                }
            }
            if(arr[i] != sortarr[i]) {
                for(int j=0;j<n;j++) {
                    if(i != j && sortarr[i] == arr[j] && arr[j] != sortarr[j]) {
                    cnt++;
                    int t=arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                    break;
                }
                }
            }
        }
    }
    cout<<cnt;
}