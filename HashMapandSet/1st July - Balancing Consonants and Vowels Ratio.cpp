// Balancing Consonants and Vowels Ratio




// Approach 1 -> simpel prefix sum and diff 
class Solution {
  public:
  bool isVowel(char ch ){
      string str = "aeiou";
    return str.find(ch) != string::npos;
  }
  
  
  int countC(string s){
      int c = 0 ; 
      for(int i =  0 ; i < s.length(); i++){
           char ch = s[i];
           if(!isVowel(ch)){
               c++;
           }
      }
      return c; 
  }
  
  
  int countV (string s){
      int v = 0 ; 
      for(int i = 0; i<s.length(); i++){
          if(isVowel(s[i])) v++;
      }
      return v; 
  }
  
  
    int countBalanced(vector<string>& arr) {
       
       
       int n = arr.size();
       int result = 0 ; 
       
       vector<int>cCount(n);
       vector<int>vCount(n);
       
       for(int i = 0; i  < n; i++){
             string curr = arr[i];
              int c = countC(curr);
              int v = countV(curr);
               
               cCount[i] = c; 
               vCount[i] = v; 
           
       }
       
       vector<int>prefixC(n);
       vector<int>prefixV(n);
        
       prefixC[0] = cCount[0];
       prefixV[0] = vCount[0];
       for(int i = 1 ;i < n; i++){
           prefixC[i] = prefixC[i-1] + cCount[i]; 
           prefixV[i] = prefixV[i-1] + vCount[i]; 
       }
       
       
       unordered_map<int , int>mp;
       
      mp[0]++;
       
       for(int i = 0 ; i < n ;i++){
            int r = prefixV[i] - prefixC[i];
           if(mp.find(r)!=mp.end()){
               result+=mp[r];
           }
           mp[r]++;
       }
        return result; 
        
    }
};







//Approach 2 -> cleaner code of above approach 
class Solution {
  public:
  
  bool isVowel(char ch){
      string s = "aeiou";
      return s.find(ch)!=string::npos;
  }
  
  int countV(string s){
      int v = 0 ; 
      
      for(auto &ch : s){
          if(isVowel(ch)) v++;
      }
      return v; 
  }
  
    int countBalanced(vector<string>& arr) {
         int n = arr.size();
         
         vector<int>diff(n);
         
         
         for(int i = 0 ; i < n; i++){
             string curr = arr[i];
             
             int v = countV(curr);
             
             int c = curr.length() - v; 
             
             diff[i] = c - v; 
         }
         
         
         unordered_map<int, int>mp ; 
         mp[0]++;
         int sum = 0 ; 
         int result = 0 ; 
         
         for(int i = 0 ; i < n; i++){
              sum += diff[i];
              if(mp.count(sum)){
                  result += mp[sum];
              }
              mp[sum]++;
         }
      return result; 
    }
};