#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[10];
char ors[10];
int main() {
scanf("%d%d%d",&arr[1],&arr[2],&arr[3]);
scanf("\n%s",&ors[1]);
sort(arr+1,arr+4);
int i;
for(i=1;i<=3;i++) printf("%d",arr[ors[i]-'A'+1]);
}