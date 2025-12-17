// Sort in specific order

class Solution {
  public:
  static bool cmp(int &a, int &b){
      return ((a%2 == 1 && b%2 == 1) ? a > b : (a%2 ==0 && b%2 == 0 ) ? a < b : a%2 > b%2);
  }
    void sortIt(vector<int>& arr) {
       sort(arr.begin(), arr.end(), cmp);
        
    }
};