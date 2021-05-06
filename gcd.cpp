#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    while(b>0){
        a = a%b;
        swap(a,b);
    }
    return a;
}

int main(){
    int a, b;
    cin>>a>>b;
    if(b>a) swap(a,b);
    int ans = gcd(a,b);
    cout<<ans;
    return 0;
}