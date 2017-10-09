main(){int n,i;double a,s=1,m=0;scanf("%d",&n);for(i=1;i<=n;i++){scanf("%lf",&a);if(s*a>a)s*=a;else s=a;if(s>m)m=s;}printf("%.3lf",m);} 
 
