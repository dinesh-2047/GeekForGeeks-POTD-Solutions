// Construct List using XOR Queries

class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        vector<int> result; 
        result.push_back(0);
        
        int xorr = 0 ; 
        
        for(auto &q : queries){
            int type = q[0];
            int x = q[1];
            
            if(type == 0){
                result.push_back(x^xorr);
            }
            else xorr ^= x; 
        }
        
        for(int i= 0 ; i < result.size(); i++){
            result[i] ^= xorr; 
        }
        
        sort(begin(result), end(result));
        return result; 
        
    }
};
