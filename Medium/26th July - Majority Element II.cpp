// Majority Element II



// Approach 1 -> using map /
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int>result;
        
        unordered_map<int , int>mp ; 
        
        for(int i = 0 ; i <n; i++){
            mp[arr[i]]++;
        }
        
        for(auto &pair : mp){
            int num = pair.first; 
            int freq = pair.second; 
            
            if(freq > n/3) result.push_back(num);
        }
        
        sort(result.begin(), result.end());
        return result; 
        
    }
};








//Approach 2 
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        
     int cnt1 = 0 ;  
     int cnt2 = 0 ; 
     int maj1 = -1; 
     int maj2 = -1 ;
     vector<int>result; 
     
     
     for(int i = 0 ; i <n; i++){
         if(arr[i] == maj1) {
             cnt1++;
         }
         else if(arr[i] == maj2){
             cnt2++;
         }
         else if(cnt1 == 0 ){
             maj1 = arr[i];
             cnt1++;
         }
         
         else if(cnt2 == 0 ){
             maj2 = arr[i];
             cnt2++;
         }
         else {
             cnt1--; 
             cnt2--; 
         }
     }
     
     int freq1 = 0 ; 
     int freq2 = 0 ; 
     
     for(int i = 0 ; i <n; i++){
         if(arr[i] == maj1) freq1++;
         else if(arr[i] == maj2) freq2++;
     }
     
     if(freq1*3 > n ) result.push_back(maj1);
     if(freq2 *3 > n && maj1 != maj2) result.push_back(maj2);
     sort(result.begin(), result.end());
     
     return result; 
        
    }
};