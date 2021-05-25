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
        cin>>a>>b>>c;
        if(a==0 && b==0){
            if(c==0)cout<<"INFINITE solution\n";
            else cout<<"NO solution\n";
            continue;
        }
        int x,y;
        int g = xgcd(a, b, x, y);
        if(c%g==0) cout<<"INFINITE solution\n";
        else cout<<"NO solution\n";
    }
        
    return 0;
}