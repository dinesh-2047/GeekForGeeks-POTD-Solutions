// Roll Characters of String

class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        int n = s.length();
        
        vector<int> v(n, 0);
        for(int i = 0 ; i  < roll.size(); i++){
            v[roll[i] - 1]++;
        }
        
        int sum = 0 ; 
        
        for(int i = n - 1; i >= 0 ; i--){
            sum = (sum + v[i])%26; 
            int num = s[i] - 'a';
            num = (num + sum)%26; 
            s[i] = char(num + 'a');
        }
        return s; 
        
    }
};
