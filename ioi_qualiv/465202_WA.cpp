#include<stdio.h>
int R,C,H,W;
int map[3011][3011];
int w[3011][3011];
int g[3011][3011];
bool t;
int ans;
int chking(int pivot) {
	int i,j,x,y;
	for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) {
			if(map[i][j] > pivot) w[i][j]=1;
			else if(map[i][j] < pivot) w[i][j]=-1;
			else {
				w[i][j]=0;
				x=j;
				y=i;
			}
			g[i][j]=w[i][j];
			g[i][j]+=g[i-1][j];
			if(i-H > 0) g[i][j]-=g[i-H][j];
		}
	}
	for(i=H;i<=R;i++) {
		int s=0;
		for(j=1;j<=W;j++) {
			s+=g[i][j];
		}
		if(i>=y && i<=y+H-1) {
			if(W >= x && W <= x+W-1) {
				if(s==0) return 1;
			}
		}
		for(j=W+1;j<=C;j++) {
			s+=g[i][j];
			s-=g[i][j-W];
			if(i>=y && i<=y+H-1) {
				if(j >= x && j <= x+W-1) {
					if(s==0) return 1;
				}
			}
		}
	}
	return 0;
}
int parametric(int low,int high) {
	if(low>high) return 0;
	int mid=(low+high)/2;
	int chk = chking(mid);
	if(chk) {
		t=1;
		if(ans == 0 || ans > mid) ans=mid;
		parametric(low,mid-1);
		return 1;
	} else {
		int tr=parametric(low,mid-1);
		if(!tr) parametric(mid+1,high);
	}
	return 0;
}
int main() {
	scanf("%d%d%d%d",&R,&C,&H,&W);
	int i,j;
	for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) {
			scanf("%d",&map[i][j]);
		}
	}
	parametric(1,R*C);
	printf("%d",ans);
}