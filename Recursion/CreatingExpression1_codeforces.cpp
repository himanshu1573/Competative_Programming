// this is the problem link 
//https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V

#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}

int n,x;

bool helper(int index,vector<int>&arr,int sum){
	if(index==n){
		return sum==x;
	}
	bool pos=helper(index+1,arr,sum+arr[index]);
	bool neg=helper(index+1,arr,sum-arr[index]);
	return pos||neg;
}
void solve(){
cin>>n>>x;
vector<int>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];
cout << (helper(1, arr, arr[0]) ? "YES" : "NO") << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
