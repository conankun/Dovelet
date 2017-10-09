#include <stdio.h>  
int main(){  
     int n,i,k,t,p,j,l;  
     bool sw=false;  
     scanf("%d",&n);  
     l=n%2;  
     l=1-l;  
     printf(" **");  
     for(i=1;i<=n;i++){ printf(" "); }  
     printf("**\n");  
     k=(n-1)/2+4; t=3+l; p=n-2;  
     for(i=1;i<=k;i++){  
          for(j=1;j<i;j++){ printf(" "); }  
          if(i <= k-3){  
               printf("*  ");  
               printf("*");  
               for(j=1;j<=p;j++){ sw=true; printf(" "); }  
               if(sw == true){ printf("*"); }  
               else if(p == 0){ printf("*"); }  
               printf("  *");  
               p-=2;  
               sw=false;  
          }  
          else{  
               printf("*");  
               for(j=1;j<=t;j++){ sw=true; printf(" "); }  
               if(sw == true){ printf("*"); }  
               else if(t == 0){ printf("*"); }  
               t-=2;  
               sw=false;  
          }  
          printf("\n");  
     }  
     return 0;  
} 
 
