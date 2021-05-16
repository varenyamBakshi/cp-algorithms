#include<bits/stdc++.h>
using namespace std;

int etf(int n){
    int res = n;
    vector<bool>primes(n+1,true);
    primes[0] = primes[1] = false;
    for(int i = 2; i <=n; i++){
        if(primes[i]){
            for(int j = i*i; j <=n; j+=i)primes[j] = false;
            if(n%i == 0) res = res/i*(i-1);
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int ans = etf(n);
    cout<<ans;
    return 0;
}