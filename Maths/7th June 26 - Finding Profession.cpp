// Finding Profession

class Solution {
  public:
    string profession(int level, int pos) {
         int f = __builtin_popcount(pos - 1);
         return (f%2 == 0 ) ? "Engineer" : "Doctor";
        
    }
};