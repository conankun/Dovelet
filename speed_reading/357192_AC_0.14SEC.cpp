#include <iostream> 
#include <stdlib.h> 
using namespace std; 
int main() { 
    int n,k; 
    cin>>n>>k; 
    int *arr=(int *)malloc(sizeof(int) * k); 
    for(int i=0;i<k;i++) { 
        int sum=0; 
        int time = 0; 
        cin>>arr[0]>>arr[1]>>arr[2]; 
        while(sum<n) { 
            int it=0; 
            while(it < arr[1] && sum<n) { 
                sum+=arr[0]; 
                time+=1; 
                it+=1; 
            } 
            it=0; 
                if(sum<n) time+=arr[2]; 
      
        } 
        cout<<time<<endl; 
        sum=0,time=0; 
    } 
    return 0; 
} 
 
