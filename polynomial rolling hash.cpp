#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int M = 1e9+7;

ll mpow(ll x, ll y){
    ll res = 1;
    while(y){
        if(y&1) res = (res*x)%M;
        x = (x*x)%M;
        y>>=1; 
    }
    return res;
}

ll hashfunc(string num, ll p){
    ll ans = 0 ;
    for(int i = 0; i <num.length(); i++){
        ans += (((int)num[i]-'a'+1)*mpow(p,i))%M;
        ans %= M;
    }
    return ans;
}

int main(){
    ll p = 31; // prime number just greater than the character set length
    string num;
    getline(cin,num);
    ll hashvalue = hashfunc(num,p);
    cout<<hashvalue<<endl;
    return 0;
}