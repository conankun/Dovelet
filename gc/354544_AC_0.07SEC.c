dp[20]={1,1}; 
main(n,i,j) {scanf("%d",&n);for(i=2;i<=n;i++)for(j=2;j<=i*2;j+=2)dp[i]+=dp[(j-2)/2]*dp[(i*2-j)/2];printf("%d",dp[n]);} 
 
