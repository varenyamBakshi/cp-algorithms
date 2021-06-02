#include<bits/stdc++.h>
using namespace std;

int func(int n){
    int sqrtn = sqrt(n);
    vector<bool> isprime(sqrtn+1,true);
    vector<int>primes;
    isprime[0] = isprime[1] = false;
    for(int i = 2 ; i <=sqrtn; i++){
        if(!isprime[i])continue;
        primes.push_back(i);
        for(int j = i*i; j <=sqrtn; j+=i){
            isprime[j] = false;
        }
    }
    int S = 10000; // Size of each bloack
    vector<bool> block(S);
    int cnt = 0;
    for(int k = 0; k*S<=n; k++){
        fill(block.begin(),block.end(),true);
        if(k==0)block[0] = block[1] = false;
        for(auto pi: primes){
            int start = (k*S + pi - 1)/pi;
            int j = max(start,pi)*pi-k*S;   // starting multiple can come out to be zero thats why tkaing max of start,pi
            for(;j<S && k*S+j<=n;j+=pi) block[j] = false;
        }
        for(int i = 0; i <S && i+k*S<=n; i++) if(block[i])cnt++;
    }
    return cnt;
    
} 

int main(){
    int n; cin>>n;
    int ans = func(n);
    cout<<ans<<endl;
    return 0;
}