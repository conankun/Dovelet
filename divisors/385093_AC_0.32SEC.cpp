#include<iostream> 
using namespace std; 
bool isPrime(unsigned long long n) { 
     if(n == 1) return false; 
     unsigned long long i; 
     for(i=2;i*i<=n;i++) { 
          if(n%i == 0) return false; 
     } 
     return true; 
} 
unsigned long long prime[500]; 
unsigned long long soinsu[500]; 
unsigned long long sosu[500][500]; 
unsigned long long ind; 
void bunhae(unsigned long long n,unsigned long long d) { 
     while(n > 1) { 
          unsigned long long i; 
          for(i=0;i<ind;i++) { 
               if(n%prime[i] == 0) { 
                    sosu[d][prime[i]]++; 
                    n/=prime[i]; 
               } 
          } 
     } 
} 
int main() { 
     unsigned long long n,k; 
     unsigned long long i,j; 
     for(i=1;i<=431;i++) if(isPrime(i)) prime[ind++]=i; 
     for(i=1;i<=431;i++) { 
          bunhae(i,i); 
          for(j=1;j<=i;j++) sosu[i][j]+=sosu[i-1][j]; 
     } 
     while(scanf("%llu%llu",&n,&k) != -1) { 
          unsigned long long sum=1; 
          for(i=1;i<=n;i++) { 
               soinsu[i] = sosu[n][i]; 
               soinsu[i] -= sosu[k][i]; 
               soinsu[i] -= sosu[n-k][i]; 
               sum*=(soinsu[i]+1); 
          } 
          printf("%llu\n",sum); 
     } 
} 