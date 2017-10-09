#include <stdio.h> 

int main() 
{ 
    int a, j,i,max=-9900, min = 9900; 
    for(i=1;i<=7;i++){ 
    scanf("%d",&a); 
    if(a>max){     
     max=a; 
    }
 if(a<min){
min = a;
}
}
    printf("%d %d",max, min); 
    return 0; 
} 