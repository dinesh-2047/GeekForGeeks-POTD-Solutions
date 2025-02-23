// Stock span problem 



class Solution {
    public:
      vector<int> calculateSpan(vector<int>& arr) {
          int n = arr.size();
          vector<int> ans(n, 1); // Initialize answer array with 1, as min span is 1 for each element.
  
          stack<pair<int, int>> st; // Stack stores pairs of (price, span)
  
          // Iterate through each element in the array
          for (int i = 0; i < n; i++) {
              int span = 1; // Default span for the current price
              
              // Pop elements from the stack while the current price is greater or equal to stack top
              while (!st.empty() && arr[i] >= st.top().first) {
                  span += st.top().second; // Add the span of previous smaller elements
                  st.pop();
              }
  
              ans[i] = span; // Store the computed span for the current price
              
              st.push({arr[i], span}); // Push the current price and its span onto the stack
          }
          return ans; 
      }
  };
  
  /*
  Time Complexity: O(N)
  - The `for` loop runs **N** times as we iterate through the array.
  - Each element is pushed onto the stack **once**.
  - Each element is popped from the stack **at most once**.
  - Since every element is pushed and popped at most **once**, the total number of stack operations is **at most 2N**.
  - Therefore, the **overall time complexity is O(N)**.
  
  Why Not O(N²)?
  - The `while` loop **does not run for every element individually in worst cases**.
  - Instead, the `while` loop only pops elements that were previously pushed, meaning each element contributes to the loop **at most once**.
  - This results in an **amortized O(N) complexity** rather than O(N²).
  
  Space Complexity: O(N)
  - The stack stores at most `N` elements in the worst case (when prices are strictly increasing).
  - The output array `ans` also takes `O(N)` space.
  - Hence, the **overall space complexity is O(N)**.
  */
  