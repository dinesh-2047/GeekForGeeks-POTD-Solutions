// Top K Frequent in Array


class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        int n = arr.size();
        
        vector<int>result; 
        unordered_map<int , int>mp ; 
        priority_queue<pair<int , int>>pq; 
        
        for(auto &a : arr){
            mp[a]++;
        }
        for(auto &pair : mp){
            int num = pair.first; 
            int freq = pair.second; 
            
            pq.push({freq, num});
        }
        
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
            
        }
        return result; 
       
    }
};
