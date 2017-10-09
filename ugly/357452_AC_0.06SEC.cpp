#include <iostream> 
#include <cmath> 
using namespace std; 
  
  
int main() { 
    int i, j; 
    int a[1500], n; 
    a[0] = 1; 
    cin>>n; 
    for(i = 1;i<n;i++) 
    { 
        a[i] = 999999999; 
        for(j = 0;j<i;j++) 
        { 
            int r1 = a[j]*2; 
            int r2 = a[j]*3; 
            int r3 = a[j]*5; 
            if(r1<a[i] && a[i-1]<r1) 
                a[i] = r1; 
            else if(r2<a[i] && a[i-1]<r2) 
                a[i] = r2; 
            else if(r3<a[i] && a[i-1]<r3) 
                a[i] = r3; 
        } 
    } 
    printf("The %d'th ugly number is %d.", n, a[i-1]); 
      
} 
 
