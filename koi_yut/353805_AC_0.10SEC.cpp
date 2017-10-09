#include<iostream>
using namespace std;
int main() {
    int arr[4];
    for(int i=0;i<3;i++) {
        int a=0,b=0;
        for(int j=0;j<4;j++) {
            cin>>arr[j];
            if(arr[j] == 0) a++;
            else b++;
        }
 
        if(a == 1 && b == 3) {
            cout<<"A"<<endl;
        } else if(a == 2 && b == 2) {
            cout<<"B"<<endl;
        } else if(a == 3 && b == 1) {
            cout<<"C"<<endl;
        } else if(a == 4 && b == 0) {
            cout<<"D"<<endl;
        } else if(a == 0 && b == 4) {
            cout<<"E"<<endl;
        }
 
    }
}