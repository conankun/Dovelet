#include <iostream> 
#include <string.h> 
using namespace std; 
  
int main() { 
    int n; 
    cin>>n; 
      
    int aa[100][3]; 
    int a1=0; 
    for(int i=3;i<=n;i++) { 
          
        for(int j=2;j<=n;j++) { 
            for(int z=2;z<j;z++) { 
                for(int a=2;a<z;a++) { 
                    if(a*a*a + z*z*z + j*j*j == i*i*i) { 
                          
                        aa[a1][0] = a; 
                        aa[a1][1] = z; 
                        aa[a1][2] = j; 
                          
                        a1++; 
                    } 
                      
                } 
            } 
        } 
          
          
        int min; 
        for(int d=0;d<a1-1;d++) { 
            min=d; 
            for(int e=d+1;e<a1;e++) { 
                if(aa[e][0] > aa[min][0]) { 
                    min = e; 
                } 
            } 
              
            int tempa=aa[d][0]; 
            int tempb=aa[d][1]; 
            int tempc=aa[d][2]; 
              
            aa[d][0] = aa[min][0]; 
            aa[d][1] = aa[min][1]; 
            aa[d][2] = aa[min][2]; 
              
            aa[min][0]=tempa; 
            aa[min][1]=tempb; 
            aa[min][2]=tempc; 
        } 
          
        for(int c=a1-1;c>=0;c--) { 
            if(aa[c][0] != 0 && aa[c][1] != 0 && aa[c][2] != 0) 
                printf("Cube = %d, Triple = (%d,%d,%d)\n",i,aa[c][0],aa[c][1],aa[c][2]); 
        } 
        memset(aa,0,sizeof(aa)); 
        a1=0; 
    } 
      
} 
 
