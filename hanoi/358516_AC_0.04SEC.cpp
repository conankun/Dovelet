#include <iostream> 
using namespace std; 
void hanoi(int n,int x,int y, int z) { 
    if(n == 1) { 
        printf("%d -> %d\n",x,z); 
        return; 
    } else { 
        hanoi(n-1,x,z,y); 
        printf("%d -> %d\n",x,z); 
        hanoi(n-1,y,x,z); 
    } 
} 
  
int main() { 
    int n; 
    cin>>n; 
    hanoi(n,1,2,3); 
    return 0; 
} 
 
