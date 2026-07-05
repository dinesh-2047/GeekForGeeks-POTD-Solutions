// Max Gap Between Two Same

class Solution {
  public:
    int maxCharGap(string &s) {
        int n = s.length();
        
       vector<int> first(26, -1);
       for(int i = n - 1; i >=0 ;i--){
           first[s[i] - 'a'] = i ;
       }
       
       int result = -1 ; 
       
       for(int i= 0 ; i  < n; i++){
           if(first[s[i] -'a'] == -1) continue; 
           result = max(result, i - first[s[i] -'a'] - 1);
       }
       return result; 
       
        
        
        
    }
};