#include<stdio.h>
int n;
int a,b,c;
int arm[1111111];
int qu[1111111],d[1111111],h=1,t=0;
int f(int i,int j){
    return -2*a*arm[i]*arm[j]+d[j]+a*arm[j]*arm[j];
}
int s(int i,int j) {
    return -2*a*arm[i]*arm[j];
}
int main()
{
    scanf("%d",&n);
    scanf("%d%d%d",&a,&b,&c);
    int i,j;
    for(i=1;i<=n;i++){
        scanf("%d",&arm[i]);
        arm[i] = arm[i-1]+arm[i];
    }
    qu[++t]=0;
    for(i=1;i<=n;i++){
        for(j=h;j<t;j++){
            if(f(i,qu[j]) <= f(i,qu[j+1])) h++;
            else break;
        }
        d[i] = f(i,qu[h]) + a*arm[i]*arm[i]+c;
        for(j=t;j>h;j--){
            if(s(i+1,qu[j]) < s(i+1,qu[j-1])) t--;
            else break;
        }
        qu[++t]=i;

    }
    printf("%d",d[n]+b*arm[n]);

}
