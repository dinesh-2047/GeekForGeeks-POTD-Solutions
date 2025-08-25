// Check if a String is Subsequence of Other

class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
       int n1 = s1.length();
       int n2 = s2.length();
       
       int k = 0 ; 
       int count = 0 ; 
       for(int i = 0 ; i < n2; i++){
           if( k < n1 && s2[i]==s1[k]){
               count++;
               k++;
           }
       }
       return count == n1; 
       
       
    }
};