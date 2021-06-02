// iterates over every number x from 0 to 2^(n−1) and considers x to be a binary number of length n, 
// where bit 1 means taking a number and bit 0 is not taking.
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, S;
	cin>>n>>S;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin>>a[i];

	for(int mask = 0; mask < (1 << n); mask++) {
		long long sum_of_this_subset = 0;
		for(int i = 0; i < n; i++) {
			if(mask & (1 << i)) {
				sum_of_this_subset += a[i];
			}
		}
		if(sum_of_this_subset == S) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
