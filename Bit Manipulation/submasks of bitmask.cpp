#include<bits/stdc++.h>
using namespace std;

const int bsize = 20;

int main(){
    string t;
    cin>>t;
    bitset<bsize>bitmask(t);
    unsigned long long m = bitmask.to_ullong();
    for(unsigned long long s = m; s; s = (s-1)&m){
        bitset<bsize>submask(s);
        cout<<submask<<"\n";
    }
    return 0;
}