#include <iostream> 
using namespace std; 
  
int sum=0; 
  
void radd(char c[],int size) { 
    for(int i=10;i>=0;i--) { 
        if(c[i] == NULL) continue; 
        else { 
            sum+=((int)(c[i]-48) * size); 
            if(size <= 1) break; 
            size/=10; 
        } 
    } 
} 
  
int main() { 
    char a[11]={NULL,}; 
    char b[11]={NULL,}; 
    int ajari=1; 
    int bjari=1; 
    cin>>a>>b; 
  
    for(int i=1;;i++) { 
        if(a[i] == NULL) break; 
        else ajari*=10; 
    } 
  
    for(int i=1;;i++) { 
        if(b[i] == NULL) break; 
        else bjari*=10; 
    } 
  
    radd(a,ajari); 
    radd(b,bjari); 
  
    int ji; 
    for(ji=1;;ji*=10) { 
        if(sum <= ji) break; 
  
    } 
    ji/=10; 
  
    int arr[11]={0,}; //각 자리수마다 들어감. 
    int index=0; 
    int sum2=0; 
    for(int i=0;ji > 0;i++,index++) { 
        if(i == 0) { 
            arr[i] = sum/ji; 
            sum2 += arr[i] * ji; 
        } else { 
             arr[i] = (sum-sum2)/ji; 
             sum2+=arr[i]*ji; 
        } 
        ji/=10; 
    } 
  
    bool ok=false; 
    for(int i=10;i>=0;i--) { 
        if(!ok && arr[i] == 0) continue; 
        else { 
            if(!ok) ok = true; 
            cout<<arr[i]; 
        } 
    } 
      
} 
 
