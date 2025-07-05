// Maximum Sum Combination



class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        vector<int>result;
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        priority_queue<pair<int , pair<int , int>>>pq; 
        set<pair<int , int>>st; 
        pq.push({a[0] + b[0], {0 , 0}});
        st.insert({0,0});
        
        while(k--){
            auto curr = pq.top();
            pq.pop();
            int currSum = curr.first ; 
            int i = curr.second.first; 
            int j = curr.second.second;
        
            
            if( i + 1 < n  && !st.count({i+ 1, j  })){
                pq.push({a[i+1]+ b[j], {i+1, j}});
                st.insert({i+1, j});
            }
            
            if(j+1 < n && !st.count({i, j + 1}) ){
                pq.push({a[i]+b[j+1], {i, j + 1}});
                st.insert({i, j+1});
            }
            
            result.push_back(currSum);
        }
        
        
        return result; 
        
    }
};