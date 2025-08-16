// Sort by Absolute Difference


// Approach 1 
class Solution {
  public:
  
  static bool cmp(pair<int , pair<int , int>>&a, pair<int , pair<int , int>>&b){
      if(a.first == b.first){
          return a.second.second < b.second.second; 
      }
      
      return a.first < b.first; 
  }
  

    void rearrange(vector<int> &arr, int x) {

        int n = arr.size();
        vector<pair<int , pair<int , int>>>vec(n); 
        
        for(int i = 0 ; i < n; i++){
            vec[i] = {abs(arr[i]-x), {arr[i], i}};
        }
        sort(vec.begin() , vec.end(), cmp);
        
        for(int i = 0 ; i <n; i++){
            arr[i] = vec[i].second.first; 
        }
    }
};class Solution {
  public:
  
  static bool cmp(pair<int , pair<int , int>>&a, pair<int , pair<int , int>>&b){
      if(a.first == b.first){
          return a.second.second < b.second.second; 
      }
      
      return a.first < b.first; 
  }
  

    void rearrange(vector<int> &arr, int x) {

        int n = arr.size();
        vector<pair<int , pair<int , int>>>vec(n); 
        
        for(int i = 0 ; i < n; i++){
            vec[i] = {abs(arr[i]-x), {arr[i], i}};
        }
        sort(vec.begin() , vec.end(), cmp);
        
        for(int i = 0 ; i <n; i++){
            arr[i] = vec[i].second.first; 
        }
    }
};







// Approach 2 
class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        auto cmp = [&](int a, int b){
            return abs(a-x) < abs(b-x); 
        };
        
        stable_sort(arr.begin(), arr.end(), cmp);
    }
};