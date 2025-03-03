
// Longest Increasing Subsequence

// Approach using binary search 

class Solution {
    public:
      int lis(vector<int>& arr) {
            int n=arr.size();
          
          vector<int> sub;
          
          for(int num : arr){
              
              auto it=lower_bound(sub.begin(),sub.end(),num);
              
              if(it == sub.end())
                  sub.push_back(num);
              else
                  *it=num;
          }
          
          return sub.size();
  
          
      }
  };