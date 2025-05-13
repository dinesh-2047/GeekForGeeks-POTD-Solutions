// Look and Say Pattern 

class Solution {
  public:
    string countAndSay(int n) {
        
        if(n==1) return "1";
        
        string say = countAndSay(n-1);
        string result = "";
        
        int count = 1; 
        
        for(int i = 0 ; i<say.length(); i++){
            char ch = say[i];
            
            if(say[i] == say[i+1]) count++;
            
            else{
                result += to_string(count) + ch; 
                count = 1; 
            }
        }
        
        return result; 
    }
};