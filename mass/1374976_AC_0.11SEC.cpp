//
//  main.cpp
//  mass
//
//  Created by ConanKun on 7/17/14.
//  Copyright (c) 2014 ConanKun. All rights reserved.
//

#include <stdio.h>
char s[1000];
int ind=0;
int main()
{
    int i;
    int num=0;
    double ans=0;
    int tr=1;
    while(scanf("%c",&s[++ind]) == true) {
      
        if(s[ind]>='0' && s[ind]<='9') {
            num++;
        } else {
           
            if(num>0) {
                int lg=1;
                int sum=0;
                for(i=ind-1;i>=ind-num;i--) {
                    sum+=lg*(s[i]-'0');
                    lg*=10;
                }
                sum--;
                if(s[ind-num-1] == 'C') {
                    ans += sum*12.01;
                } else if(s[ind-num-1] == 'H') {
                    ans += sum*1.008;
                } else if(s[ind-num-1] == 'O') {
                    ans += sum*16;
                } else if(s[ind-num-1] == 'N') {
                    ans += sum*14.01;
                }
                
            }
                if(s[ind] == 'C') {
                    ans += 12.01;
                } else if(s[ind] == 'H') {
                    ans += 1.008;
                } else if(s[ind] == 'O') {
                    ans += 16;
                } else if(s[ind] == 'N') {
                    ans += 14.01;
                }
            
            num=0;
        }
    }
    if(s[ind]>='0' && s[ind]<='9') {
        num++;
    } else {
        
        if(num>0) {
            int lg=1;
            int sum=0;
            for(i=ind-1;i>=ind-num;i--) {
                sum+=lg*(s[i]-'0');
                lg*=10;
            }
            sum--;
            if(s[ind-num-1] == 'C') {
                ans += sum*12.01;
            } else if(s[ind-num-1] == 'H') {
                ans += sum*1.008;
            } else if(s[ind-num-1] == 'O') {
                ans += sum*16;
            } else if(s[ind-num-1] == 'N') {
                ans += sum*14.01;
            }
            
        }
        if(s[ind] == 'C') {
            ans += 12.01;
        } else if(s[ind] == 'H') {
            ans += 1.008;
        } else if(s[ind] == 'O') {
            ans += 16;
        } else if(s[ind] == 'N') {
            ans += 14.01;
        }
        
        num=0;
    }

    
    printf("%.3lf",ans);
}

