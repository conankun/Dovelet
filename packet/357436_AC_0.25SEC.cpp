#include<iostream> 
#include<cmath> 
using namespace std; 
int papers[10]={0}; 
int main() { 
    for(int i=1;i<=6;i++) { 
        cin>>papers[i]; 
    } 
    int cnt=0; 
    for(int i=6;i>=1;i--) { 
        if(papers[i] > 0) { 
            if(i == 6) { 
                for(int j=1;j<=papers[i];j++) { 
                    cnt++; 
                } 
            } else if(i == 5) { 
                for(int j=1;j<=papers[i];j++) { 
                    cnt++; 
                    int sum=25; 
                    while(1) { 
                        if(1+sum <= 36 && papers[1] > 0) { 
                            sum+=1; 
                            papers[1]--; 
                        } else break; 
                    }    
                } 
            } else if(i == 4) { 
                for(int j=1;j<=papers[i];j++) { 
                    if(papers[2] >= 5) { 
                        papers[2]-=5; 
                    } else { 
                        if(papers[1] > 0) papers[1]-=(36-(papers[2]*4+16)); 
                        papers[2] = 0; 
                    } 
                    cnt++; 
                } 
            } else if(i == 3) { 
                cnt+=papers[3]/4; 
                if(papers[3] % 4 != 0) { 
                    cnt++; 
                    int sum=papers[3]%4; 
                    sum*=9; 
                    if(papers[3]% 4 == 1) { 
                        papers[2]-=4; 
                        sum+=4*4; 
                    } else if(papers[3]% 4 == 2) { 
                        papers[2]-=3; 
                        sum+=4*3; 
                    } else if(papers[3] % 4 == 3) { 
                        papers[2]-=1; 
                        sum+=4; 
                    } 
                    while(1) { 
                        if(1+sum <= 36 && papers[1] > 0) { 
                            sum+=1; 
                            papers[1]--; 
                        } else break; 
                    } 
  
                } 
            } else if(i == 2) { 
                cnt+=papers[2]/9; 
                if(papers[2]%9 != 0) { 
                    cnt++; 
                    int sum=papers[2]%9; 
                    sum*=4; 
                    while(1) { 
                        if(1+sum <= 36 && papers[1] > 0) { 
                            sum+=1; 
                            papers[1]--; 
                        } else break; 
                    } 
                } 
            } else if(i == 1) { 
                cnt+=ceil(papers[1]/36.00); 
            } 
        } 
    } 
    cout<<cnt; 
} 
 
