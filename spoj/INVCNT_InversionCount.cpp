#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

vector<int>temp;
vector<int>arr;
int merge(int left,int mid,int right){
int i=left;
int j=mid+1;
int k=left;
int inversions=0;

while(i<=mid && j<=right){
	if(arr[i]<=arr[j]){
		temp[k++]=arr[i++];
		
	}else{
		temp[k++]=arr[j++];
		inversions+=(mid-i+1);
	}
}
while(i<=mid){
	temp[k++]=arr[i++];
}
while(j<=right){
	temp[k++]=arr[j++];
}
for(i=left;i<=right;i++){
        arr[i]=temp[i];
    }
return inversions;
}
int divide(int left,int right){
 // we are recursively dividing the array 
	int inversions=0;
	if(left<right){
		int mid=left+(right-left)/2;
		//left array 
		inversions+=divide(left,mid);
		//right array 
		inversions+=divide(mid+1,right);
		// merge the sort which was recursive.
		inversions+=merge(left,mid,right);
	}
	return inversions;
}

void solve(){
int n;cin>>n;
arr.resize(n);
temp.resize(n);
for(auto &i:arr)cin>>i;
cout<<divide(0,n-1) << nl;	

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    int t=1;
    cin>>t;
    string blank;
    getline(cin,blank);
    while(t--){
        solve();
    }
    return 0;
}
