// Palindrome Sentence


// Appraoch 1 
class Solution {
  public:
    bool isPalinSent(string &s) {
        
        int n = s.length();
        
        string str = "";
        
        for(int i = 0 ; i < n; i++){
            if(isalnum(s[i])){
                str.push_back(tolower(s[i]));
            }
        }
        
        int i = 0 ; 
        int j = str.length()- 1; 
        
        while(i<=j){
            if(str[i]!=str[j]) return false; 
            i++;
            j--;
        }
        return true; 
        
    }
};








//Approach 2 
class Solution {
  public:
    bool isPalinSent(string &s) {
        
        int n = s.length();
    
        
        int i = 0 ; 
        int j = n- 1; 
        
        while(i<=j){
            
            while(i<j && !isalnum(s[i]) ) i++;
            while(j>i && !isalnum(s[j])) j--;
            if(tolower(s[i])!=tolower(s[j])) return false; 
            i++;
            j--;
        }
        return true; 
        
    }
};