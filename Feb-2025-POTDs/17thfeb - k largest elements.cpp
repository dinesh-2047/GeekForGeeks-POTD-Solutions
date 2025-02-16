// K largest elements 


class Solution {
    public:
      vector<int> kLargest(vector<int>& arr, int k) {
          vector<int>ans;
           priority_queue<int>pq(arr.begin(),arr.end());
           
           while(k--){
               auto topp = pq.top();
               pq.pop();
               ans.push_back(topp);
           }
           return ans; 
      }
  };

