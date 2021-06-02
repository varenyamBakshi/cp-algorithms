#include<bits/stdc++.h>
using namespace std;

vector<bool> isprime;

void init(int size){
    isprime.resize(size,1);
    isprime[0] = isprime[1] = false;
    for(int i = 2; i*i < size; i++){
        if(!isprime[i]) continue;
        for(int j = i*i; j <size; j+=i){
            isprime[j] = false;
        }
    }
}

int main(){
    int n; cin>>n; //to print the nth prime
    const int size = 1e8+1;
    init(size);
    int cnt  =0 ;
    for(int i = 2; i < size; i++){
        if(isprime[i]){
            cnt++;
            if(cnt==n) {cout<<i<<endl; break;}
        }
    }
    return 0;
}