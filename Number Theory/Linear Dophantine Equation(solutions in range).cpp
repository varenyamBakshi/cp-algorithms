#include<bits/stdc++.h>
using namespace std;

int xgcd(int a, int b, int &x, int &y){
    //if(b>a)swap(a,b);        // not needed as in next recursive call they will be interchanged
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    int x0, y0;
    int g = xgcd(b, a%b, x0, y0);
    x = y0;
    y = x0 - (a/b)*y0;
    return g;
}

int main(){
    int t; cin>>t;
    for(int t_ = 1; t_ <=t; t_++){
        int a, b, c; // equation is of form ax+by=c
        int xl, xr, yl, yr; // xl <= x <= xr  yl <= y <= yr
        cin>>a>>b>>c;
        cin>>xl>>xr>>yl>>yr;
        if(a==0 && b==0 && c!=0){
            cout<<"NO solution\n";
            continue;
        }
        int x,y;
        int g = xgcd(a, b, x, y);
        if(c%g!=0) cout<<"NO solution\n";
        else{

        }
    }
        
    return 0;
}