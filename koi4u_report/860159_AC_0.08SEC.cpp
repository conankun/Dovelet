#include<stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	int i;
	double sumgpa=0;
	for(i=1;i<=n;i++) {
		double a,b;
		scanf("%lf%lf",&a,&b);
		double c=a/b;
		c*=100;
		if(c >= 95 && c<=100) {
			printf("A+ 4.3\n");
			sumgpa+=4.3;
		}
		else if(c >= 90 && c<=95) {
			printf("A0 4.0\n");
			sumgpa+=4.0;
		}
		else if(c >= 85 && c<=90) {
			printf("A- 3.7\n");
			sumgpa+=3.7;
		}
		else if(c >= 80 && c<=85) {
			printf("B+ 3.3\n");
			sumgpa+=3.3;
		}
		else if(c >= 75 && c<=80) {
			printf("B0 3.0\n");
			sumgpa+=3.0;
		}
		else if(c >= 70 && c<=75) {
			printf("B- 2.7\n");
			sumgpa+=2.7;
		}
		else if(c >= 65 && c<=70) {
			printf("C+ 2.3\n");
			sumgpa+=2.3;
		}
		else if(c >= 60 && c<=65) {
			printf("C0 2.0\n");
			sumgpa+=2.0;
		}
		else if(c >= 55 && c<=60) {
			printf("C- 1.7\n");
			sumgpa+=1.7;
		}
		else if(c >= 50 && c<=55) {
			printf("D+ 1.3\n");
			sumgpa+=1.3;
		}
		else if(c >= 45 && c<=50) {
			printf("D0 1.0\n");
			sumgpa+=1.0;
		}
		else if(c >= 40 && c<=45) {
			printf("D- 0.7\n");
			sumgpa+=0.7;
		} else {
			printf("F 0.0\n");
		}
	}
	printf("%.2lf",sumgpa/n);
}