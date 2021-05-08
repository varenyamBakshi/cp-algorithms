#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix_pow(vector<vector<int>> mat, int n){
    vector<vector<int>> ans = {{1,0},{0,1}};
    if(n==0) return mat;
    while(n){
        if(n&1){
            vector<vector<int>> tempmat(2,vector<int>(2,0));
            for(int row = 0; row<2; row++){
                for(int col = 0; col<2; col++){
                    int temp=0;
                    for(int k = 0; k <2; k++){
                        temp += ans[row][k]*mat[k][col];
                    }
                    tempmat[row][col] = temp;
                }
            }
            ans = tempmat;
        }
        vector<vector<int>> tempmat(2,vector<int>(2,0));
        for(int row = 0; row<2; row++){
            for(int col = 0; col<2; col++){
                int temp=0;
                for(int k = 0; k <2; k++){
                    temp += mat[row][k]*mat[k][col];
                }
                tempmat[row][col] = temp;
            }
        }
        mat = tempmat;
        n >>= 1;
    }
    return ans;
}


int main(){
    vector<int> initial = {0,1}; // [F0, F1]
    vector<vector<int>> transform = {{0,1},        //transformation matrix  [Fi, Fi+1] * transform = [Fi+1, Fi+2]
                                       {1,1}};
    int n;
    cin>>n;
    int ans;
    if(n==1) ans = 0;
    if(n==2) ans = 1;
    if(n>2) {
        vector<vector<int>> trans = matrix_pow(transform,n-2);
        vector<int> res(2);
        for(int j = 0; j<2; j++){
            int temp=0;
            for(int k = 0; k <2; k++){
                temp += initial[k]*trans[k][j];
            }
            res[j] = temp;
        }
        ans = res[1];
    }
    cout<<ans<<endl;
    return 0;
}