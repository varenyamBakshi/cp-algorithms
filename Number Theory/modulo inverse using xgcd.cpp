#include<bits/stdc++.h>
using namespace std;

int xgcd(int a, int b, int &x, int &y){
    if(b==0){
        x =1;
        y=0;
        return a;
    }
    int x1,y1;
    int d = xgcd(b,a%b,x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return d;
}


int main(){
    int n, p;
    cin>>n>>p;
    int x, y;
    int gcd = xgcd(n,p,x,y);
    if(gcd!=1) cout<<"Inverse does not exist.\n";
    else {
        int ans = (x%p + p)%p;
        cout<<ans<<endl;
    }
    return 0;
}