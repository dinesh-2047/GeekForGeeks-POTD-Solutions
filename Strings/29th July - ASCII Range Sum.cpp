// ASCII Range Sum



class Solution {
  public:
    vector<int> asciirange(string& s) {
       int n = s.length();
        vector<int>cnt(26, 0);
        
        for(auto &ch : s){
            cnt[ch - 'a']++;
        }
        
        vector<pair<int , int>>vec(26 , {-1, -1}); 
        
        for(int i = 0 ; i < 26; i++){
            if(cnt[i] > 1){
                int firstOcc = 0 ; 
                int lastOcc = 0 ; 
                
                for(int j = 0 ; j  < n; j++){
                    if(s[j] == i + 'a' ){
                        firstOcc = j ; 
                        break; 
                    }
                }
                
                for(int j = n-1 ; j >=0 ; j--){
                    if(s[j] == i + 'a'){
                        lastOcc  = j; 
                        break; 
                    }
                }
                
                vec[i] = {firstOcc, lastOcc};
            }
        }
        
        vector<int>result ;
        for(int i = 0 ; i < 26; i++){
            if(vec[i]!=make_pair(-1, -1)){
                int st = vec[i].first; 
                int last = vec[i].second; 
                if(st + 1 < last){ 
                 int sum = 0 ; 
                
                for(int j = st+1; j < last ; j++){
                     sum += s[j];
                }
                          result.push_back(sum);
            }
            }
        }
        
        
        return result; 
        
    }
};