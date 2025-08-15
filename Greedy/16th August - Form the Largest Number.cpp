// Form the Largest Number


class Solution {
  public:
  bool cmp(string a, string b){
      if(a.length() == b.length()){
          return a > b;
      }
      
      if(a.length() < b.length()){
          if(a[0] != b[0]){
              return a[0] > b[0];
          }
          else {
              bool zero = false; 
              
              for(int i = 0 ; i < b.length(); i++){
                  if(b[i]=='0'){
                      zero = true; 
                      break; 
                  }
              }
              if(zero)
              
          }
      }
      
      if(a.length() > b.length()){
          
      }
      
  }
  
  
    string findLargest(vector<int> &arr) {
      
       int n = arr.size();
       
       vector<string>vec(n); 
       
       for(int i = 0 ; i  < n; i++){
           vec[i] = to_string(arr[i]);
       }
       
       sor(vec.begin(), vec.end(), cmp);
        string result = "";
       for(int i = 0 ; i < n; i++){
           result += vec[i];
       }
       
       return result; 

        
    }
};