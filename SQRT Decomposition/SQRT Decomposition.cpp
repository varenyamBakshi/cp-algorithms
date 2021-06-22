#include<bits/stdc++.h>
using namespace std;

const int blk = 1e3;

int sqrt_dec(int l, int r, vector<int> &arr, vector<int> &block){
    int L = l/blk;
    int R = r/blk;
    int ans = INT_MAX;
    if(L==R){
        for(int i = l; i <= r; i++)ans = min(ans, arr[i]);
        return ans;
    }
    for(int i = l; i< blk*(L+1); i++) ans = min(ans, arr[i]);
    for(int i = L+1; i<R; i++) ans = min(ans, block[i]);
    for(int i = R*blk; i<=r; i++)ans = min(ans, arr[i]);
    return ans;
    
}

int main(){
    int n; cin>>n;
    int sz = (n+blk-1)/blk;
    vector<int> block(sz, INT_MAX);
    vector<int> arr(n);
    for(int i = 0; i < n; i++)cin>>arr[i];
    for(int i = 0; i < n; i++){
        int id = i/blk;
        block[id] = min(block[id], arr[i]);
    }
    int q; cin>>q;
    while(q--){
        int l , r; cin>>l>>r;
        int ans = sqrt_dec(l, r, arr, block);
        cout<<ans<<endl;
    }

    return 0;
}