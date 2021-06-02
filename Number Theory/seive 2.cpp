#include<bits/stdc++.h>
using namespace std;

int func(int n){
    vector<int> lp(n+1,0), primes;

    for(int i = 2; i<=n; i++){
        if(!lp[i]){
            lp[i] = i;
            primes.push_back(i);
        }
        for(int p = 0; p<primes.size() && primes[p]<=lp[i] && i*primes[p]<=n; p++){
            lp[i*primes[p]] = primes[p];
        }
    }
    return primes.size();
}

int main(){
    int n; cin>>n;
    int ans = func(n);
    cout<<ans;
    return 0;
}