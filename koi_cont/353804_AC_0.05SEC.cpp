#include<iostream>
using namespace std;
int main() {
    char a[3][9]={0};;
    for(int i=0;i<3;i++) {
        cin>>a[i];
    }
    for(int i=0;i<3;i++) {
        int cnt=1;
        int mx=1;
        for(int j=1;j<8;j++) {
            if(a[i][j] == a[i][j-1]) {
                cnt++;
                if(mx < cnt) mx = cnt;
            } else cnt=1;
        }
        cout<<mx<<endl;
    }
}