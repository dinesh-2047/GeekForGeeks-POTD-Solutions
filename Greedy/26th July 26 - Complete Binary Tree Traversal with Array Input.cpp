// Complete Binary Tree Traversal with Array Input

class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> result; 
        
        int n = arr.size();
        
        int nodes = 1; 
   
        
        int i = 0 ; 
        while(i < n ){
            multiset<int>st; 
            int count = 0 ; 
            while(i < n  && count < nodes){
                st.insert(arr[i]);
                count++;
               i++;
            }
            vector<int> vec; 
            for(auto &x : st){
                vec.push_back(x);
            }
            result.push_back(vec);
            nodes *=2 ; 
        }
        return result;
    }
};
