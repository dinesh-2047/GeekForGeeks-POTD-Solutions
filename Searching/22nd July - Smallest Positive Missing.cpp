// Smallest Positive Missing


// Approach  1 

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        unordered_set<int>st(arr.begin(), arr.end());
        
        for(int i=1; i<=1e6;i++){
            if(!st.count(i)) return i;
        }
        return -1;
    }
};









//Approach 2

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        unordered_set<int>st(arr.begin(), arr.end());
        
        for(int i=1; i<=n;i++){
            if(!st.count(i)) return i;
        }
        return n + 1;
    }
};














//Approach 3
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
         int count = 1; 
        for(int i = 0 ; i < n; i++){
            
           if(arr[i] ==count) count++;
           else if(arr[i] > count) break; 
            
        }
        return count; 
    }
};









//Approach 4
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0 ;i <n; i++){
            while(arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i]-1] ) { 
                swap(arr[i], arr[arr[i]-1]);
        }
        }
        
        for(int i = 1 ;i <= n; i++){
            if(i!=arr[i-1]) return i;
        }
        return n + 1;
    }
};