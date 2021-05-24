#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

#define ll unsigned long long

ll mpow(ll a, ll n, ll p){
    ll res = 1;
    while(n){
        if(n&1)res = (res*a)%p;
        a = (a*a)%p;
        n>>=1;
    }
    return res;
}

bool isPrime(ll x, int iter = 10){
    ll s = 0, d = 0;
    ll temp = x-1;
    while(temp%2==0){
        temp/=2;
        s++;
    }
    d = temp;
    int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for(int a: prime){
        if(a==x)return true;
        if()
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