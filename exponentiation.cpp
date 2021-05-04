// We are implementing the power function to calculate the x raised to y in log y time complexity.
// It is binary exponentiation.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9+7;// for large results ometimes we are asked to return modulo of reult

ll exp_pow(ll x, ll y){ // returns x to power y
    ll res = 1;
    while(y>0){
        if(y&1) res *= x; // if lsb is 1 we multiply the calculated power of x to the result 
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