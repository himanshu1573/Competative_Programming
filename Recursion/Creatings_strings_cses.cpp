#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}


int n;

void helper(string &s,vector<bool>&checker, string &temp){
	if(temp.size()==n){
		cout<<temp<<nl;
		return;
	}

	for(int i=0;i<n;i++){
		if(checker[i])continue;
		if(i>0 && s[i]==s[i-1] && !checker[i-1])continue;
	    checker[i]=true;
		temp.push_back(s[i]);

		
		
		
		helper(s,checker,temp);

		temp.pop_back();
		checker[i]=false;

	}
}
void solve(){
string s ;cin>>s;
sort(s.begin(),s.end());
n=s.size();

vector<bool>checker(n,false);
string temp;
helper(s,checker,temp);
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
