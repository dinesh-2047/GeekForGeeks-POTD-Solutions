
// Longest Bounded-Difference Subarray

vector<int> longestSubarray(vector<int>& arr, int x) {
    int n = arr.size();
   int l = 0, maxLen = 0, startIdx = 0; // l: left pointer, maxLen: longest subarray length, startIdx: starting index

   priority_queue<pair<int, int>> maxHeap; // Max-Heap to track the maximum element in the window
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // Min-Heap for minimum element
   unordered_map<int, int> freq; // Frequency map to handle outdated elements in heaps

   // Sliding window approach
   for (int r = 0; r < n; r++) {
       // Insert current element into both heaps and update frequency map
       maxHeap.push({arr[r], r});
       minHeap.push({arr[r], r});
       freq[arr[r]]++;

       // Ensure max-min condition is satisfied
       while (!maxHeap.empty() && !minHeap.empty() && (maxHeap.top().first - minHeap.top().first > x)) {
           // Reduce frequency of the outgoing element and move left pointer
           freq[arr[l]]--;
           l++;

           // Remove outdated elements (whose frequency is 0) from heaps
           while (!maxHeap.empty() && freq[maxHeap.top().first] == 0) maxHeap.pop();
           while (!minHeap.empty() && freq[minHeap.top().first] == 0) minHeap.pop();
       }

       // Update the longest subarray details if a better one is found
       if (r - l + 1 > maxLen) {
           maxLen = r - l + 1;
           startIdx = l;
       }
   }

   // Construct the result manually instead of slicing
   vector<int> result;
   for (int i = startIdx; i < startIdx + maxLen; i++) {
       result.push_back(arr[i]);
   }
   
   return result;
   }
};