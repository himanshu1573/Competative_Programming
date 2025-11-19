#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int costA=0;
	int costB=0;
	// here cost of A is the minimum operation needed to make prefix 1....i to all A's;
	// here cost of B is the minimum operation needed to make prefix 1....i to all B's;

	for(auto &c:s){
        int next_costA,next_costB;

        if(c=='A'){
        	next_costA=min(costA,costB+1);
        	next_costB=min(costB+1,costA+1);
        }else{
        	next_costA=min(costA+1,costB+1);
        	next_costB=min(costB,costA+1);
        }
        costA=next_costA;
        costB=next_costB;
	}
	cout<<costA;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    int t=1;
    // cin>>t;
    // string blank;
    // getline(cin,blank);
    while(t--){
        solve();
    }
    return 0;
}
