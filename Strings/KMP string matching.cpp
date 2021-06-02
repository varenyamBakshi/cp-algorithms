#include<bits/stdc++.h>
using namespace std;

#define maxn 100001

int pi[maxn];
void pifunc(string pat){
    int n = pat.length();
    pi[0] = 0;
    for(int i = 1; i<n ; i++){
        int j = pi[i-1];       //length of the longest prefix which is also a suffix of string pat[0 ... i-1]
        while(j > 0 && pat[j]!=pat[i]) j = pi[j-1];
        if(pat[i] == pat[j]) pi[i] = j+1;
        else pi[i] = 0;
    }
}

int main(){
    string pat, text;
    getline(cin,pat);
    getline(cin, text);
    pifunc(pat);
    int n = text.length();
    int m = pat.length();
    int i = 0, j = 0;
    int cnt=  0;
    while(i<n){
        if(text[i]==pat[j]){
            i++,j++;
            if(j==m){
                cnt++;
                j = pi[j-1];
            }
        }
        else{
            while(j>0 && pat[j]!=text[i])j = pi[j-1];
            if(pat[j]!=text[i])i++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}