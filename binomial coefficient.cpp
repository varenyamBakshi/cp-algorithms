#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9+7;

ll mpow(ll x, ll y){
    ll a = x;
    ll res = 1;
    while(y){
        if(y&1) res = (res*a)%M;
        a = (a*a)%M;
        y>>=1;
    }
    return res;
}

ll inverse(int a){
    return mpow(a,M-2);
}

ll factorial(int a){
    ll x = 1;
    for(int i = 2; i <=a;i++){
        x = (x*i)%M;
    }
    return x;
}

ll nCr(int n, int r){
    return (factorial(n)*inverse(factorial(n-r)))%M*inverse(factorial(r))%M;
}

int main(){
    ll n, r;
    cin>>n>>r;
    ll ans = nCr(n,r);
    cout<<(ans+M)%M;
    return 0;
}