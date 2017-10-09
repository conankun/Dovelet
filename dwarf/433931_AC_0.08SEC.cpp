#include<stdio.h>
int p[100];
int main() {
	int a,b,c,d,e,f,g,i;
	for(i=1;i<=9;i++) scanf("%d",&p[i]);
	for(a=1;a<=9;a++) {
		for(b=a+1;b<=9;b++) {
			for(c=b+1;c<=9;c++) {
				for(d=c+1;d<=9;d++) {
					for(e=d+1;e<=9;e++) {
						for(f=e+1;f<=9;f++) {
							for(g=f+1;g<=9;g++) {
								if(p[a]+p[b]+p[c]+p[d]+p[e]+p[f]+p[g] == 100) {
									printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n",p[a],p[b],p[c],p[d],p[e],p[f],p[g]);
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
}