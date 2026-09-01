// Unoccupied Computers

class Solution {
  public:
    int solve(int n, string s) {

        
        vector<bool> vec(26, false);
        vector<bool> rej(26, false);
        
        
        int result = 0 ; 
        
        for(auto &ch : s){
            if(!rej[ch - 'A']){
                if(vec[ch -'A']){
                    n++;
                    vec[ch - 'A'] = false; 
                }
            
            else {
                if(n){
                    vec[ch - 'A'] = true; 
                    n--;
                }
                else {
                    rej[ch-'A'] = true; 
                    result++;
                }
            }
        }
        }
        return result; 
        
    }
};
