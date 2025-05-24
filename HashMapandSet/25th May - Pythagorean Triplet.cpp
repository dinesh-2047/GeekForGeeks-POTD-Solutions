// Pythagorean Triplet


class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
       int n = arr.size();
       
       unordered_map<int, int>mp ; 
       for(int i = 0 ; i<n; i++) arr[i] = arr[i]*arr[i];
       for(int i = 0 ;i<n; i++)mp[arr[i]]++;
       
       
       for(int i = 0 ; i<n; i++){
           for(int j = i + 1; j<n; j++){
               if(mp[arr[i] + arr[j]] >= 1  ) return true; 
           }
       }
        return false; 
        
    }
};