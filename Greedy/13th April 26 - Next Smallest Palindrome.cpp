// Next Smallest Palindrome


class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        
        bool all9 = true; 
        for(auto &x : num){
            if(x!=9){
                all9 = false; 
                break; 
            }
        }
        if(all9){
            vector<int>result (n + 1, 0);
            result[0] = result[n] = 1; 
            return result; 
        }
        
        
        vector<int>result = num; 
        
        for(int i = 0 ; i  < n/2; i++){
            result[n-i-1] = result[i];
        }
        
        if(result > num) return result; 
        
        int carry = 1; 
        int mid = n/2; 
        
        if(n%2 == 1){
            result[mid] += carry; 
            carry = result[mid]/10;
            result[mid]%=10; 
            mid--;
        }
        else mid--; 
        
        while(mid >= 0 && carry){
            result[mid] += carry; 
            carry = result[mid]/10; 
            result[mid]%=10 ; 
            result[n-mid-1] = result[mid];
            mid--; 
        }
        
        for(int i = 0 ; i  < n/2 ; i++){
            result[n-i-1] = result[i];
        }
        return result; 
        
    }
};