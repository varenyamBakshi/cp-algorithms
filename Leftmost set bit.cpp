#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ull unsigned long long

int main(){
    ll n; cin>>n;
    int i = 1;
    while((n>>i)){
        n = n|(n>>i);
        i<<=1;
    }
    n = ((ull)(n+1) >>1);
    cout<<n<<endl;
    return 0;
}