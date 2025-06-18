// Case-specific Sorting of Strings



class Solution {
  public:
    string caseSort(string& s) {
        int n = s.length();
      vector<int>lowercase(26,0);
      vector<int>uppercase(26,0);
      
      string result = "";
      
      for(int i = 0 ; i <n ;i++ ){
          char ch = s[i];
          
          if(ch >= 'a' && ch <= 'z' ) lowercase[ch-'a']++;
          else uppercase[ch-'A']++;
      }
      
      for(int i = 0 ; i <n; i++){
          char ch = s[i];
          
          if(ch >= 'a' && ch <= 'z'){
              for(int j = 0 ; j <26; j++){
                  if(lowercase[j] == 0 ) continue; 
                  result.push_back(j + 'a');
                  lowercase[j]--;
                  break; 
              }
          }
          
          else {
             for(int j = 0 ; j <26; j++){
                  if(uppercase[j] == 0 ) continue; 
                  result.push_back(j + 'A');
                  uppercase[j]--;
                  break; 
              } 
          }
      }
      
      return result; 
        
    }
};