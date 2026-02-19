// Form the Largest Number

class Solution {
  public:
  static bool cmp(string a, string b){
    return a + b > b + a;
  }
    string findLargest(vector<int> &arr) {
        int n = arr.size();
        vector<string>vec; 
        for(auto &x : arr){
            vec.push_back(to_string(x));
        }
        
        sort(begin(vec), end(vec), cmp);
        
        string result = "";
        
        for(auto &x : vec) result += x; 
        if(result[0] ==  '0') return "0";
        return result; 
        
        
    }
};