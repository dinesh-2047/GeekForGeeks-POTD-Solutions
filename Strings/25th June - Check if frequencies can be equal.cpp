// Check if frequencies can be equal


class Solution {
  public:
  
  bool isSame(vector<int> &freq){
      int n = freq.size();
      
      for(int i = 0 ; i < n-1; i++){
          if(freq[i]==0 || freq[i+1]==0) continue; 
          if(freq[i]!=freq[i+1]) return false; 
      }
      return true; 
  }
  
    bool sameFreq(string& s) {
        int n = s.length();
        
        vector<int>freq(26,0);
        
        for(int i = 0 ; i<n; i++){
            freq[s[i]-'a']++;
        }
        
        vector<int>newFreq; 
        
        for(int i = 0 ; i < 26; i++){
            if(freq[i]!=0) newFreq.push_back(freq[i]);
        }
        
        int f = newFreq.size();
        
          if(isSame(newFreq)) return true; 
        for(int i = 0 ; i <f; i++){
            newFreq[i]--;
            if(isSame(newFreq)) return true; 
            
            newFreq[i]++;
        }
        
        return false; 
    }
};