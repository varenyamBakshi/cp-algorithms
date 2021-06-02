#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9+7;

ll dp[100000];
ll hashpat;

void init(string text, string pat, ll p){
    dp[0] = 0;
    ll  mult = 1;
    for(int i = 1; i <= text.length(); i++){
        dp[i] = (dp[i-1] + ((ll)text[i-1]-'a'+1)*mult)%M;
        mult = (mult*p)%M;
    }
    hashpat= 0;
    mult = 1;
    for(int i = 0; i <pat.length(); i++){
        hashpat = (hashpat +mult*((ll)pat[i] - 'a'+1))%M;
         mult = (mult*p)%M;
    }
}

vector<int> match(int t, int s, ll p){
      vector<int> ans;
      ll mult = 1;
      for(int i = s; i<=t; i++){
          ll val = (dp[i] - dp[i-s] + M)%M;
          ll hval = (hashpat*mult)%M;
          mult = (mult*p)%M;
          if(val==hval) ans.push_back(i-s);
      }
      return ans;
}

int main(){
    string text, pat;
    getline(cin,text);
    getline(cin, pat);
    ll p = 31;
    init(text, pat, p);

    vector<int> indexes = match(text.length(),pat.length(),p);
    for(auto idx:indexes) cout<<idx<<" ";
    cout<<endl;
    return 0;
}