// Strings Rotations of Each Other


class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        string str = s1 + s1; 
        if(str.find(s2)!= string::npos) return true; 
        else return false; 
        
    }
};