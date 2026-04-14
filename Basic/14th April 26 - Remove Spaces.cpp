// Remove Spaces

class Solution {
  public:
    string removeSpaces(string& s) {
       string result = "";
       for(auto &ch : s){
           if(ch == ' ') continue; 
           result += ch; 
       }
       return result; 
        
    }
};