// Find the longest string



//Approach without trie -> TC- > O(nlogn)
class Solution {
  public:
    string longestString(vector<string> &arr) {
       
       
       int n = arr.size();
       
       unordered_map<string , bool>mp ; 
       
       sort(arr.begin(), arr.end());
       
       for(int i= 0  ; i <n; i++){
           string s = arr[i];
           if(s.length() == 1){
               mp[s] = true; 
           }
           else{
               string temp = s ; 
               temp.pop_back();
               if(mp[temp]){
                   mp[arr[i]] = true; 
               }
           }
       }
       
       string result = "";
       for(int i = 0 ; i <n; i++){
           if(mp[arr[i]] && arr[i].size() > result.size()){
               result = arr[i];
           }
          
       }
        
        return result; 
    }
};