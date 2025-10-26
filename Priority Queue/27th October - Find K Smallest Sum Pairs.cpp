// Find K Smallest Sum Pairs

class Solution {
  public:
  #define P pair<int ,pair<int , int>>
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        int n = arr1.size();
        
        vector<vector<int>>result; 
        
        priority_queue<P , vector<P>, greater<>>pq; 
        
       for(int i = 0 ; i < min(n, k); i++){
           pq.push({arr1[i] + arr2[0], {i, 0}});
       }
       
       while(!pq.empty() && result.size() < k ){
           auto curr = pq.top();
           pq.pop();
           
           result.push_back({arr1[curr.second.first], arr2[curr.second.second]});
           
           if(curr.second.second +  1 < n ){
               pq.push({arr1[curr.second.first] +  arr2[curr.second.second + 1], {curr.second.first, curr.second.second + 1}});
           }
       }
       return result; 
        
        
    }
};
