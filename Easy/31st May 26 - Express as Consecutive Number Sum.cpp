// Express as Consecutive Number Sum


class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        return (n & (n-1))!=0;
        
    }
};