int d[13],n,i;
main(){scanf("%d",&n);for(i=2;i<=n;i++){d[i]+=d[i-1]*i;if(i%2 == 0)d[i]++;else d[i]--;}printf("%d",d[n]);}