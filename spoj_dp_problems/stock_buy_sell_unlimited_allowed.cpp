class Solution {
  public:
  vector<vector<int>>dp;
  int solve(int index,int buy,vector<int> &arr){
      if(index==arr.size())return 0;
      int profit=0;
      if(dp[index][buy]!=-1)return dp[index][buy];
      if(buy){
          profit=max(-arr[index]+solve(index+1,0,arr),solve(index+1,1,arr));
      }else{
          profit=max(arr[index]+solve(index+1,1,arr),solve(index+1,0,arr));
      }
        return dp[index][buy]=profit;
      }
    int stockBuySell(vector<int> &arr) {
        // code here
        int n=arr.size();
        dp.assign(n, vector<int>(2, -1));
       return  solve(0,1,arr);
    }
};

// this is geeks for geek problem 
// https://www.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
