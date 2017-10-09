#include <iostream> 
using namespace std; 
int main () { 
    float a,b;   
    scanf("%f",&a);   
    b=a;   
      
    while(1)   
    {   
        scanf("%f",&a);   
        if(a==999) break;   
        printf("%.2f\n",a-b); // 이부분 printf("%.2f\n",...);  
        b=a;   
    }   
    printf("End of Output"); // 이 부분 printf("End....");  
    return 0;   
} 
 
