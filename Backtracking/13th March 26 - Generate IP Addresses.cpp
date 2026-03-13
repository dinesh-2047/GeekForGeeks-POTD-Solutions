// Generate IP Addresses



class Solution {
  public:
   vector<string>result; 
   bool isValid(string s){
       if(s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
   }
   
   
   void solve(string &s, vector<string> path , int i ){
       if(path.size()  == 4){
           if(i >= s.length()){
               result.push_back(path[0] + "."  + path[1] + "." + path[2] + "." + path[3]);
           }
           return ;
       }
       
       for(int len = 1; len <= 3; len++){
           
            if(i + len > s.size()) break;
           
           string part = s.substr(i, len);
           
           if(isValid(part)){
               path.push_back(part);
               solve(s, path, i + len);
               path.pop_back();
           }
       }
   }
   
   
    vector<string> generateIp(string &s) {
      vector<string>path ; 
      
      solve(s, path, 0);
      
      return result; 
        
    }
};