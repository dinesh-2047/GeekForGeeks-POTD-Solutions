// Sum of Subarrays




// Approach 1 Brute force ->TLE



//Approach 2 optimized 
class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int result = 0 ; 
        int n = arr.size();
        
        for(int i = 0 ; i <n; i++){
            int start = i + 1; 
            int end = n-i ; 
            
            int occurences = start * end; 
            
            result += (arr[i] * occurences);
        }
        return result; 
        
    }
};