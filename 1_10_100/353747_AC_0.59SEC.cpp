#include <iostream>
using namespace std;
int main() {int n;cin>>n;int a;for(int i=0;i<n;i++) {cin>>a;int b=1;int plus=2;for(;;) {b+=plus;plus++;if(b+plus >= a) break;}if(b+1 == a) cout<<"1 ";else cout<<"0 ";}}