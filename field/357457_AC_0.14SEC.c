main() {struct f{int p;int w;};int k,m=0,n,w=0,p[5]={0},i,j,z;struct f q[6];scanf("%d",&k);for(i=0;i<6;i++){scanf("%d %d",&q[i].p,&q[i].w);p[q[i].p]++;if(q[i].w>m){m=q[i].w;n=i;}}if(p[q[n<5?n+1:0].p]==2){i=n<5?n+1:0;w+=((q[n<5?n+1:0].w)*m);j=i<5?i+1:0;z=j<5?j+1:0;w+=q[z].w*(m-q[j].w);}else if(p[q[n>0?n-1:5].p]==2){i=n>0?n-1:5;w+=((q[n > 0 ? n-1 : 5].w) * m);j=i>0?i-1:5;z=j>0?j-1:5;w+=q[z].w*(m-q[j].w);}printf("%d",k*w);} 
 
