#include <iostream>
using namespace std;
 
int min(int x,int y) {
    return x>y ? y : x;
}
 
int max(int x,int y) {
    return x>y ? x : y;
}
 
 
 
int main () {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",max(min(a,b),a));
    return 0;
}