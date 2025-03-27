// Activity Selection

// Greedy approach 
class Solution {
    public:
    static bool cmp(pair<int, int>a, pair<int , int>b){
        return a.second < b.second;
    }
    
      int activitySelection(vector<int> &start, vector<int> &finish) {
          int n = start.size();
          vector<pair<int, int>>v; 
          for(int i = 0 ; i<n; i++){
              v.push_back({start[i], finish[i]});
          }
          
          sort(v.begin(), v.end(), cmp);
          
           
           int ans = 1 ; 
            int st = 0 ; 
            int end = v[0].second;
           
           for(int i = 1 ; i <n ;i++){
               st = v[i].first;
               if(st<=end){
                   continue;
               }
               ans++;
               end = v[i].second;
           }
           return ans; 
      }
  };
  