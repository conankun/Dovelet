#include<iostream>
#include<math.h>
using namespace std;
int abs(int a) {
    if(a < 0) return -1*a;
    return a;
}
int main() {
    struct a{int x;int y;};
    int n;
    a arr[5001]={0,0};
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i].x>>arr[i].y;
    double max=-1;
    int ii,jj;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(i == j) continue;
            double x=abs(arr[i].x - arr[j].x);
            double y=abs(arr[i].y - arr[j].y);
            if(sqrt(x*x + y*y) > max) {
                max = sqrt(x*x + y*y);
                ii=i;jj=j;
            }
        }
    }
    cout<<ii+1<<" "<<jj+1;
}