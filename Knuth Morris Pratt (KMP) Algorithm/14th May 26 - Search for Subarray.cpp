// Search for Subarray

class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        vector<int> lps(m);
        
        int i = 1; 
        int len = 0 ; 
        
        while(i < b.size()){
            if(b[i] == b[len]){
                len++;
                lps[i] = len ; 
                i++;
            }
            else {
                if(len!=0){
                    len = lps[len - 1];
                }
                else lps[i] = 0; 
                i++;
            }
        }
        
        i =0 ; 
        int j = 0 ; 
        
        vector<int> result; 
        while(i < n ){
            if(a[i] == b[j]){
                i++;
                j++;
                if(j == m ){
                   result.push_back(i - j )  ;
                   j = lps[j- 1];
                } 
            }
            else {
                if(j!=0) j = lps[j- 1];
                else i++;
            }
            
        }
        return result;
        
    }
};