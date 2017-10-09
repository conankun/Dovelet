#include<iostream> 
using namespace std; 
int main() { 
    int m; 
    scanf("%d",&m);
    for(int d=0;d<m;d++) { 
        int a,b,c; 
        int arr[40]; 
        scanf("%d %d %d",&a,&b,&c);
        arr[0]=a; 
        arr[1]=b; 
        for(int i=2;i<=c;i++) { 
            arr[i]=arr[i-1]+arr[i-2];
        } 
printf("%d\n",arr[c-1]);    } 
} 
 
