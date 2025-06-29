// Max min Height


// Approach 1 / Binary Search

class Solution {
  public:
  bool isPossible(vector<int> &arr, int k , int w , int mid){
      vector<int>vec =arr; 
      int n = arr.size();
      for(int i= 0 ; i <n; i++){
          if(vec[i] < mid){
              int temp = mid - vec[i];
              if(temp >k) return false; 
              k-=temp; 
              vec[i] = mid; 
              
              for(int j = i + 1; j <n && j < i+w; j++){
                  vec[j] += temp ; 
              }
          }
          
      }
      return true; 
  }
  
  
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        
        
        int st = *min_element(begin(arr), end(arr));
        int end = st  + k; 
        
        int result = 0 ; 
        
        while(st <= end){
            int mid = st + (end - st)/2;
            
            if(isPossible(arr, k , w , mid)){
                result = mid; 
                st = mid + 1;
            }
            else end = mid -1 ; 
        }
        return result; 
    }
};






//Approach 2 Optimized binary search using diff array technique
class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int w, int mid) {
        int n = arr.size();
        vector<int> diff(n + 2, 0);  // n+2 to safely access i+w
        int used = 0;
        int curr_add = 0;

        for (int i = 0; i < n; i++) {
            curr_add += diff[i];
            int currentHeight = arr[i] + curr_add;

            if (currentHeight < mid) {
                int inc = mid - currentHeight;
                used += inc;
                if (used > k) return false;

                // Apply inc from i to i + w - 1 using diff array
                diff[i] += inc;
                diff[min(n, i + w)] -= inc;  // safe bound check
                curr_add += inc;  // also update for current index
            }
        }

        return true;
    }

    int maxMinHeight(vector<int>& arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

