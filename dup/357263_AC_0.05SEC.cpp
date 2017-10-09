#include <stdio.h> 
int main() { 
    int a[10]; 
    int b[10]; 
    for(int i=0;i<10;i++) { 
        scanf("%d",&a[i]); 
        b[i] = a[i]; 
        for(int j=0;j<i;j++) { 
            if(j!=i&&a[i]==b[j]) { 
                a[i]=11; 
                a[j]=11; 
            } 
        } 
    } 
    for(int i=0;i<10;i++){ if(a[i]!=11)printf("%d ",a[i]);} 
} 
 
