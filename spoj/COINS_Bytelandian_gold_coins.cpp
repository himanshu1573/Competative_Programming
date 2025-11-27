#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

map<int,int> memoised;

int recursive_solve(int n){
    if(n<=4)return n;
    if(memoised.count(n))return memoised[n];

    int ans=recursive_solve(n/2)+recursive_solve(n/3)+recursive_solve(n/4);
    int result=max(n,ans);

    memoised[n]=result;
    return memoised[n];
}

void solve(){
int  n;
while(cin>>n){

memoised.clear();
cout<<recursive_solve(n)<<nl;
}
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
