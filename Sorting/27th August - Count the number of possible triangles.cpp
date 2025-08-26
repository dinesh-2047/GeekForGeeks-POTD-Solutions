// Count the number of possible triangles

// Approach 1 USing Binary Search 
class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
         int count = 0 ; 
        for(int i = 0 ; i < n;i++){
            for(int j =i+1 ; j < n; j++){
              
             int idx = lower_bound(begin(arr)+ j + 1, end(arr), arr[i] + arr[j])-begin(arr);
             count += idx - j - 1; 
        }
        }
        return count; 
        
    }
};





//Approach 2 USing sorting  + two Pointer 
class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
         int count = 0 ; 
        for(int k = n-1; k>=2; k--){
            int i = 0 ; 
             int j = k-1; 

             while(  i < j ){
                if(arr[i] + arr[j] > arr[k]){
                  count += j- i;
                  j--;
                }
                else i++;
             }
            
        }
        return count; 
        
    }
};
