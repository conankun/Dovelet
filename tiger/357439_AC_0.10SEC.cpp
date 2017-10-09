#include <iostream> 
using namespace std; 
int main() { 
    int arr[50]; 
    int d,k; 
    cin>>d>>k; 
    int day=0; 
    for(int i=1;i<=k;i++) { //첫째날 떡. 
        arr[0]=i; 
        day=1; 
        for(int j=i;j<=k;j++) { //둘째날 떡. 
            arr[1]=j; 
            day=2; 
            while(day < d) { 
                arr[day]=arr[day-1]+arr[day-2]; 
                day++; 
            } 
  
            if(arr[day-1] == k) { 
                cout<<arr[0]<<endl<<arr[1]; 
                return 0; 
            } 
  
        } 
    } 
  
} 
 
