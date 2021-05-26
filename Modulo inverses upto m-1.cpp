#include<bits/stdc++.h>
using namespace std;

#define ll long long

void moduloinverse(int m, vector<int> &inv){
    inv[1] = 1;
    for(int i = 2; i < m; i++){
        inv[i] = m - (m/i)*inv[m%i]%m;
    }
}

int main(){
    int m; cin>>m;
    vector<int> inv(m);
    moduloinverse(m,inv);
    for(int i = 1; i < m; i++) cout<<i<<":"<<inv[i]<<endl;
    return 0;
}