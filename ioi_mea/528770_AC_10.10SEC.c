n,A[9000000],i=1,s,e=2000000000,t;
main() {scanf("%d",&n);for(;i<=n;i++)scanf("%d",&A[i]);s=A[1];for(i=2;i<=n;i++){if(e>A[i])e=A[i];t=A[i]*2-e;e=A[i]*2-s;s=t;}if(e-s+1<0)e=s-1;printf("%d",e-s+1);}