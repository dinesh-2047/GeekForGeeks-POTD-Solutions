// Generate Usernames

class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
       vector<string> result; 
       int n = arr.size();
       
       unordered_set<string> st; 
       
       unordered_map<string , int >mp; 
       
       for(auto &p : arr) mp[p]++;
       
       for(auto p : arr){
           string s = p ; 
           if(mp.count(p) && st.count(p)){
               int x = 1;
                while(mp.count(s)){
                 s = p +  to_string(x);
                 x++;
                }
                mp[s]++;
           }
          
           mp[s]++;
           result.push_back(s);
           st.insert(s);
       }
       return result; 
        
    }
};