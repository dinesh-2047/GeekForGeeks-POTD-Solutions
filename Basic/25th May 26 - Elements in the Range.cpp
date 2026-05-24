// Elements in the Range

class Solution {
  public:
    bool checkElements(int s, int e, vector<int> &arr) {
      int n = arr.size();
      
      int count = 0 ; 
      for(auto &x : arr){
          if(x >= s && x <= e) count++;
      }
      return count == (e - s + 1);
        
    }
};
