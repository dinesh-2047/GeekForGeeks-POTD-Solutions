// Search Pattern (Rabin-Karp Algorithm)




class Solution {
  public:
  int mod = 1e9 + 7;
    vector<int> search(string &pat, string &txt) {
       int n = txt.size();
       int m = pat.size();
       
       int pathash = 0; 
       int txthash = 0 ; 
       vector<int>result; 
       
       for(int i = 0 ; i <m; i++){
           pathash = (pathash +  (pat[i]-'a'))%mod; 
           txthash = (txthash  + (txt[i]-'a'))%mod; 
       }
       
       if(pathash == txthash){
           if(txt.substr(0,m)==pat) result.push_back(1);
       }
       
       int i = 0 ; 
       int j = m ; 
       
       while(j < n){
           txthash = (txthash - (txt[i]-'a'))%mod;
           txthash  = (txthash + (txt[j]-'a'))%mod;
           
           if(txthash == pathash) {
               if(txt.substr(i+1, m) == pat) result.push_back(i+2);
           }
           i++;
           j++;
           
       }
       return result; 
    }
};