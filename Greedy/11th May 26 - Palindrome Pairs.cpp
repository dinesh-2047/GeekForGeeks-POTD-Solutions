// Palindrome Pairs

class Solution {
  public:
  
  bool isPal(string s){
      int i = 0 ; 
      int j = s.length() - 1; 
      
      while(i < j ){
          if(s[i] != s[j]) return false; 
          i++;
          j--;
      }
      return true; 
  }
    bool palindromePair(vector<string>& arr) {
        int n = arr.size();
        
        unordered_map<string , int> mp ; 
        for(int i = 0 ; i < n; i++){
            mp[arr[i]] = i; 
        }
        
        for(int i = 0 ; i < n; i++){
            string word = arr[i];
            for(int j = 0 ; j  <= word.length(); j++){
                string left = word.substr(0, j);
                string right = word.substr(j);
                
                if(isPal(left)){
                    string revr = right ; 
                    reverse(begin(revr), end(revr));
                    if(mp.count(revr) && mp[revr] != i) return true; 
                }
                if(isPal(right)){
                    string revl = left ; 
                    reverse(begin(revl), end(revl));
                    if(mp.count(revl) && mp[revl] != i) return true; 
                }
            }
        }
        return false; 
        
    }
};