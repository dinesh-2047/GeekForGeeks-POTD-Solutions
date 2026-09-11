// Max Product Subsequence of Size K



class Solution {
  public:
 int n;
 vector<vector<pair<int ,  int>>> dp; 
    pair<int, int> solve(vector<int>& arr, int i, int k) {
           if (k == 0)
               return {1, 1};

           if (i == n || n - i < k)
               return {INT_MIN, INT_MAX};
               
               if(dp[i][k]!= make_pair(-1,-1)) return dp[i][k];

           auto notTake = solve(arr, i + 1, k);
           auto take = solve(arr, i + 1, k - 1);

           int takeMax = arr[i] * take.first;
           int takeMin = arr[i] * take.second;

           int mx = max(notTake.first, max(takeMax, takeMin));
           int mn = min(notTake.second, min(takeMax, takeMin));

           return dp[i][k] = {mx, mn};
       }

    int maxProduct(vector<int> &arr, int k) {
        n = arr.size();
    dp.resize(n + 1, vector<pair<int , int>>(k + 1, make_pair(-1,-1)));
       return solve(arr, 0, k).first; 
    }
};