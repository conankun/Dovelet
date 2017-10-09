#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[10];
    while(n--) {
        cin>>a[1]>>a[2]>>a[3];
        if(max(a[1],max(a[2],a[3])) == a[1]) {
            if(a[2]+a[3] <= a[1]) {
                cout<<"Not a triangle"<<endl;
            } else if(a[2]*a[2]+a[3]*a[3]==a[1]*a[1]) {
                cout<<"Right"<<endl;
            } else if(a[2]*a[2]+a[3]*a[3]>a[1]*a[1]) {
                cout<<"Acute"<<endl;
            } else if(a[2]*a[2]+a[3]*a[3]<a[1]*a[1]) {
                cout<<"Obtuse"<<endl;
            }
        } else if(max(a[1],max(a[2],a[3])) == a[2]) {
            if(a[1]+a[3] <= a[2]) {
                cout<<"Not a triangle"<<endl;
            } else if(a[1]*a[1]+a[3]*a[3]==a[2]*a[2]) {
                cout<<"Right"<<endl;
            } else if(a[1]*a[1]+a[3]*a[3]>a[2]*a[2]) {
                cout<<"Acute"<<endl;
            } else if(a[1]*a[1]+a[3]*a[3]<a[2]*a[2]) {
                cout<<"Obtuse"<<endl;
            }
        } else {
            if(a[2]+a[1] <= a[3]) {
                cout<<"Not a triangle"<<endl;
            } else if(a[2]*a[2]+a[1]*a[1]==a[3]*a[3]) {
                cout<<"Right"<<endl;
            } else if(a[2]*a[2]+a[1]*a[1]>a[3]*a[3]) {
                cout<<"Acute"<<endl;
            } else if(a[2]*a[2]+a[1]*a[1]<a[3]*a[3]) {
                cout<<"Obtuse"<<endl;
            }
        }
    }
}
