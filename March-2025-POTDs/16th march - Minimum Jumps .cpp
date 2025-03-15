// Minimum Jumps 

class Solution {
    public:
        int minJumps(vector<int>& arr) {
            int n = arr.size();
          
            // If the first element is 0, we cannot move forward
            if(arr[0] == 0) return -1; 
            
            // If there's only one element, no jumps are needed
            if(n == 1) return 0; 
            
            int ans = 1;  // Minimum jumps required
            int jumps = arr[0];  // Steps we can take from the current position
            int maxReach = arr[0];  // Maximum index we can reach
            
            for(int i = 1; i < n; i++) {
                maxReach--; // Decrease maxReach as we move forward
                jumps--;  // Decrease the available jumps
                
                // Update maxReach with the maximum steps possible from the current index
                maxReach = max(maxReach, arr[i]);
                
                // If we run out of jumps before reaching the end
                if(jumps == 0 && i != n - 1) {
                    // If we can't reach any further, return -1
                    if(maxReach <= 0) return -1; 
                    
                    // Refill jumps with the maximum reachable steps
                    jumps = maxReach; 
                    maxReach = 0;  // Reset maxReach
                    ans++;  // Increment jump count
                }
            }
            return ans; 
        }
    };
    