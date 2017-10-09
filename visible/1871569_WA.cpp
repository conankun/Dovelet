#include <iostream>
#include <map>
using namespace std;
int d[1111];
long double slope(const int &x1,const int &y1, int &x2, int &y2) {
    return (y2-y1)/(long double)(x2-x1);
}
map<long double, bool> mp;
int main() {
    int t;
    cin>>t;
    int i,j;
    for(i=1;i<=1000;i++) {
        int cnt=0;
        for(j=0;j<=i;j++) {
            //(i,j)
            long double ss = slope(0,0,j,i);
            map<long double,bool>::iterator it = mp.find(ss);
            if(it == mp.end()) {
                cnt++;
                mp[ss]=true;
            }
        }
        for(j=0;j<=i-1;j++) {
            //(j,i)
            long double ss = slope(0,0,i,j);
            map<long double,bool>::iterator it = mp.find(ss);
            if(it == mp.end()) {
                cnt++;
                mp[ss]=true;
            }
        }
        d[i] = d[i-1]+cnt;
    }
    while(t--) {
        int n;
        cin>>n;
        cout<<d[n]<<endl;
    }
}
