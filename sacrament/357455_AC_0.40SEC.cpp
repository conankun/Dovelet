#include <stdio.h> 
  
int main() { 
    int a,i,j; 
    int arr[50001]; 
    scanf("%d",&a); 
    for(i=0;i<a;i++) scanf("%d",&arr[i]); 
  
    int b; 
    int arr2[50001]; 
    scanf("%d",&b); 
    for(int ii=0;ii<b;ii++) scanf("%d",&arr2[ii]); 
  
    for(i=0;i<a;i++) { 
        int c=arr[i]; 
        int d=arr2[b/2]; 
        if(c+d > 10000) { 
    for(j=b/2;j<b;j++) { 
                if(arr[i]+arr2[j] == 10000) { 
                    printf("YES"); 
                    return 0; 
                } 
            } 
      
        } else if(c+d < 10000) { 
            for(j=b/2;j>=0;j--) { 
                if(arr[i]+arr2[j] == 10000) { 
                    printf("YES"); 
                    return 0; 
                } 
            } 
              
              
        } else if(c+d == 10000) { 
            printf("YES"); 
            return 0; 
        } else continue; 
    } 
  
    printf("NO"); 
  
} 
 
