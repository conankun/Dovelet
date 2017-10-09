#include <iostream> 
using namespace std; 
int main() {int n;cin>>n;int index=0;for(int i=1;;i++){if(i<10){index++;if(index == n) {cout<<i;return 0;}continue;}else {int jari=1;for(int j=0;;j++) {jari*=10;if(jari*10 > i) break;}int sum=0;int nowsu;for(int j=jari;j>=1;j/=10) {if(j == jari) {sum+=(i/j)*j;nowsu=i/j;++index;} else {nowsu=(i-sum)/j;sum+=((i-sum)/j)*j;++index;}if(n == index) {cout<<nowsu;return 0;}continue;}continue;}continue;}} 
 
