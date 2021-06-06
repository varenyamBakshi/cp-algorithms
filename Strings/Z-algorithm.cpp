#include<bits/stdc++.h>
using namespace std;

vector<int> zfunction(string s){
    int n = s.length();
    vector<int> z(n,0);
    for(int i = 1, l = 0, r = 0; i <=n; i++){ // till r is the known range
        if(i<=r) z[i] = min(z[i-l],r-i+1);

        while(i+z[i] < n && s[i+z[i]]==s[z[i]]) z[i]++;
        if(i+z[i]-1>r) {    // updating the righmost found segment
            r = i+z[i]-1;
            l = i;
        }
        
    }
    return z;
}

int main(){
    string s;
    cin>>s;
    vector<int> ans = zfunction(s);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}