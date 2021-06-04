#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    int len = 1+ *max_element(arr.begin(),arr.end());
    vector<int> vec(len,0);
    for(auto it: arr) vec[it]++;
    for(int i = 1; i <len; i++) vec[i] += vec[i-1];
    vector<int> ans(n);
    for(int i = n-1; i >=0; i--){
        ans[ --vec[arr[i]] ] = arr[i];
    }

    for(auto it: ans) cout<<it<<" "; 
    return 0;
}