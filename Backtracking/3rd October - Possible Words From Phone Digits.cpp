// Possible Words From Phone Digits


class Solution {
  public:
  unordered_map<int , string>mp ; 
  void solve(vector<int> &arr, int i , string curr , vector<string> &result ){
      if(i >= arr.size()){
          result.push_back(curr);
          return ;
      }
      
      if(!mp.count(arr[i])){
          solve(arr, i + 1, curr, result);
          return ;
      }
      
      string temp = mp[arr[i]];
      
      for(auto &ch : temp){
          curr.push_back(ch);
          solve(arr, i + 1, curr, result);
          curr.pop_back();
      }
  }
  
    vector<string> possibleWords(vector<int> &arr) {
       mp[2] = "abc";
       mp[3] = "def";
       mp[4] = "ghi";
       mp[5] = "jkl";
       mp[6] = "mno";
       mp[7] = "pqrs";
       mp[8] = "tuv";
       mp[9] = "wxyz";
       
       vector<string>result; 
       string curr = ""; 
       
       solve(arr,0 , curr, result  );
       
       return result; 
        
    }
};