#include <iostream>
using namespace std;
int main () {
    int n;
    int a,b,c;
    cin>>n;
    n = 1000-n;
     
    a = n/100;
    b = (n-a*100)/50;
    c = (n-(a*100+b*50))/10;
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}