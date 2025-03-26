// Minimum Platforms

class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          int n = arr.size();
          
          sort(arr.begin(), arr.end());
          sort(dep.begin(), dep.end());
          
          int i = 0, j = 0;  // Pointers for arrival and departure
      int platforms = 0, maxPlatforms = 0;
  
      while (i < n && j < n) {
          if (arr[i] <= dep[j]) { // A train arrives
              platforms++;
              i++;
          } else { // A train departs
              platforms--;
              j++;
          }
          maxPlatforms = max(maxPlatforms, platforms);
      }
      return maxPlatforms;
  }
  };