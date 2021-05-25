#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
using u128 = __uint128_t;

ll mpow(ll a, ll n, ll p){
    u128 res = 1;
    while(n){
        if(n&1)res = (res*a)%p;
        a = ((u128)a*a)%p;
        n>>=1;
    }
    return res;
}

bool isComposite(ll a, ll x, ll d, ll s){
    u128 A = mpow(a, d, x);
    if(A==1||A==(x-1)) return false;
    
    while(s){
            s--;
            A = (A*A)%x;
            if(A == (x-1))return false;
    }
    return true;
}

bool isPrime(ll x){
    ll s = 0, d = 0;
    ll temp = x-1;
    while(temp%2==0){
        temp/=2;
        s++;
    }
    d = temp;
    ll primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for(ll a: primes){
        if(a==x)return true;
        if(isComposite(a, x , d, s))return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n; 
        cin>>n;
        if(n>1 && isPrime(n))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}