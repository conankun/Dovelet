#include<stdio.h>
int d[258257],d1[258257],d2[258257],d3[258257];
int main()
{
	int n,i,c=1,s=1,c3=0,s2=1,j,t,max=0,ii=0,jj=0,s1=0,t1,t2,max1=0,iii,jjj,t3,s4=2;
	scanf("%d",&n);
	for(i=1; i<=n; i++){
		scanf("%1d",&d[i]);
	}
	printf("1");
	for(i=1; i<=n-1; i++){
		if(1-d[i]==d[i+1] && d[i]!=999 && d[i+1]!=999){
			s++;
			d[i]=999;
			d[i+1]=999;
			d2[s2]=i;
			s2++;
			d2[s2]=i+1;
			s2++;
		}
	}
	c++;
	while(1){
		for(i=1; i<=n-1; i++){
			max=0;
			if(i%2==1){
				for(j=i+1; j<=n; j++){
					if(1-d[i]==d[j] && j%2==0 && d[i]!=999 && d[j]!=999){
						t=j-i;
						if(max<t){
							max=t;
							ii=i;
							jj=j;
						}
					}
				}
			}
			if(i%2==0){
				for(j=i+1; j<=n; j++){
					if(1-d[i]==d[j] && j%2==1 && d[i]!=999 && d[j]!=999){
						t=j-i;
						if(max<t){
							max=t;
							ii=i;
							jj=j;
						}
					}
				}
			}
			if(max1<=max){
				if(max1==max){
					if(iii>ii){
						max1=max;
						iii=ii;
						jjj=jj;
					}
				}
				else{
					max1=max;
					iii=ii;
					jjj=jj;
				}
			}
		}
		d[ii]=999;
		d[jj]=999;
		max1=0;
		s++;
		c++;
		d2[s2]=ii;
		s2++;
		d2[s2]=jj;
		s2++;
		if(d1[n/2]>0) break;
	}
	for(i=1; i<=n; i+=2){
		d1[i/2+1]=d2[i+1]-d2[i];
	}
	for(i=1; i<=n/2-1; i++){
		for(j=i+1; j<=n; j++){
			if(d1[j]<d1[i]){
				t3=d1[i];
				d1[i]=d1[j];
				d1[j]=t3;
			}
		}
	}
	d3[1]=1;
	c3=1;
	for(i=2; i<=n/2; i++){
		if(d1[i-1]!=d1[i]) c3++;
		d3[i]=c3;
		s4+=d3[i]*2;
	}
	printf("%d\n",s4);
	for(i=1; i<=n-3; i+=2){
		for(j=i+2; j<=n-1; j++){
			if(d2[i]>d2[j]){
				t1=d2[i];
				t2=d2[i+1];
				d2[i]=d2[j];
				d2[i+1]=d2[j+1];
				d2[j]=t1;
				d2[j+1]=t2;
			}
		}
	}
	for(i=1; i<=n; i+=2) printf("%d %d\n",d2[i],d2[i+1]);

	return 0;
}