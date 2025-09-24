// Generate Binary Numbers


// Approach 1 


class Solution {
  public:
  string getBinary(int num){
      string binary  = "";
      
      while(num){
          if(num == 1){
              binary.push_back(num + '0');
              break; 
          }
          binary.push_back((num%2) + '0');
          num/=2; 
      }
      reverse(begin(binary) , end(binary));
      return binary; 
  }
    vector<string> generateBinary(int n) {
        vector<string>result;
        for(int num = 1; num <= n ; num++){
            string binary = getBinary(num);
            result.push_back(binary);
        }
        return result; 
    }
};










//Approach 2 
class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string>result;
        for(int num = 1; num <= n; num++){
            bitset<32>binary(num);
            string b = "";
            int i = 31 ; 
            while(binary[i] == 0){
                i--;
            }
            for(;i >=0; i--){
                int digit = binary[i];
                char d = digit + '0';

                b.push_back(d);
        }
        result.push_back(b);
        }
        return result; 
    }
};