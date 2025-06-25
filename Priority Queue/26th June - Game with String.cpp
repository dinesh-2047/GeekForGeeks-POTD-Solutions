// Game with String

class Solution {
  public:
    int minValue(string &s, int k) {
        int n = s.length();
        
        priority_queue<int>pq; 
        vector<int>freq(26,0);
        for(int i = 0 ; i <n  ; i++){
           freq[s[i]-'a']++;
        }
        
        for(int i = 0 ; i <26;i++){
            if(freq[i] == 0 ) continue; 
            pq.push(freq[i]);
            
        }
        
        while(!pq.empty() && k>0){
          auto curr = pq.top();
          curr--;
          pq.pop();
          pq.push(curr);
            k--;
        }
        
        int result = 0 ; 
        
        while(!pq.empty()){
            int curr = pq.top();
            pq.pop();
            
            result += (curr * curr);
        }
        return result; 
        
    }
};