// Smallest window containing all characters

class Solution {
  public:
  bool isEqual(vector<int> &freqs, vector<int> &freqp){
      for(int i = 0 ; i  < 26; i++){
          if(freqp[i] == 0) continue; 
          if(freqs[i] < freqp[i]) return false;
      }
      return true; 
  }
  
    string minWindow(string &s, string &p) {
        int n = s.length();
        
        vector<int>freqp(26, 0);
        for(auto &ch : p){
            freqp[ch - 'a']++;
        }
        
        int w_size = INT_MAX ; 
        int i = 0 ; 
        int j = 0 ; 
        
        int resulti = -1 ; 
        int resultj = -1 ; 
        vector<int>freqs(26, 0);
        while( j < n ){
            freqs[s[j] - 'a']++;
            while(i <= j && isEqual(freqs, freqp)){
                if(w_size  > j - i + 1 ){
                    resulti = i ; 
                    resultj = j ; 
                    w_size = j - i + 1;
                }
                freqs[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        if(resulti == -1 ) return "";
        return s.substr(resulti, resultj - resulti + 1);
        
    }
};