// Job Sequencing Problem


class Solution {
    public:
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          int n = profit.size();
          
          vector<pair<int, int>>jobs(n);
          vector<int>ans(2);
          
          for(int i = 0 ; i<n; i++){
              jobs[i] = {profit[i], deadline[i]};
              
          }
          
          sort(jobs.rbegin(), jobs.rend());
          
          set<int>s;
          for(int i = 1 ; i<=n; i++) s.insert(i);
          
          int cnt = 0 ; 
          int maxProfit = 0 ; 
          for(int i = 0 ; i<n; i++){
                if(s.empty()) break;
              int currentDeadline = jobs[i].second; 
              int currentProfit = jobs[i].first; 
              
              auto it = s.upper_bound(currentDeadline);
              if(it == s.begin()) continue;
             it--;
              cnt++;
              maxProfit+=currentProfit; 
              s.erase(it);
             
              
              
              
          }
          ans[0] = cnt; 
          ans[1] = maxProfit; 
          return ans; 
          
      }
  };