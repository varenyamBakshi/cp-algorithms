#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ll n; cin>>n;
    int cnt = 0;
    while(n){
        n = n&(n-1);
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}