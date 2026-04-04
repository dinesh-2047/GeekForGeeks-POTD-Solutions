// Gray Code

class Solution {
  public:
    vector<string> graycode(int n) {
       vector<string>result; 
       
       int limit = 1 << n; 
       
       for(int i = 0 ; i  < limit ; i++){
           int num = i ^ (i >> 1);
           string gray_code = bitset<32>(num).to_string();
           gray_code = gray_code.substr(32 - n);
           
           result.push_back(gray_code);
       }
       return result; 
       
        
    }
};