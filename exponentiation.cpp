#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9+7;

ll exp_pow(ll x, ll y){ // returns x to power y
    ll res = 1;
    while(y>0){
        if(y&1) res *= x; // if lsb is 1 we multiply the calculates power of x to the result 
        x *= x;
        y>>=1;
    }
    return res;
}

ll mod_exp_pow(ll x, ll y){
    ll res = 1;
    while(y>0){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y>>=1;
    }
    return res;
}

int main(){
    int x, y;
    cin>>x>>y;
    ll ans = exp_pow(x,y);
    cout<<ans<<endl;
}