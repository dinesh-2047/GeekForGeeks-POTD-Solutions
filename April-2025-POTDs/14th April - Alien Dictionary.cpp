// Alien Dictionary

class Solution {
    public:
      string findOrder(vector<string> &words) {
          int n = words.size();
        unordered_map<int , list<int>>adj;
        vector<int>indegree(26,0);
        string ans = "";
        
        
        for(int i = 0 ; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.length(), s2.length());
            bool check = false; 
            for(int j = 0 ; j<len; j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[s2[j]-'a']++;
                    check = true; 
                    break; 
                }
            }
            if(!check && s1.length() > s2.length()) return "";
        }
        
        vector<int>present(26,0);
        for(int i =0 ; i<n; i++){
            for(auto ch : words[i]){
                present[ch-'a']++;
            }
        }
        
        queue<int>q; 
        for(int i= 0 ; i<26; i++){
            if(present[i] && indegree[i] == 0 ) q.push(i);
        }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            ans += (node + 'a');
            
            for(auto &nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        for(int i= 0 ;i<26; i++){
            if(present[i] && indegree[i] > 0) return "";
        }
        return ans; 
      }
  };
  