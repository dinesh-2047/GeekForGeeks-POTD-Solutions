// Smallest range in K lists


class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
      int k = arr.size();

        //{element, listIdx, idx} //vector<int>{a, b, c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEl = INT_MIN;
        for(int i = 0; i < k; i++) {
            pq.push({arr[i][0], i, 0});
            maxEl = max(maxEl, arr[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listIdx = curr[1];
            int idx     = curr[2];

            if(maxEl - minEl < resultRange[1] -  resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            //decrease the rangen fro minimums ide
            if(idx+1 < arr[listIdx].size()) {
                int nextElement = arr[listIdx][idx+1];
                pq.push({nextElement, listIdx, idx+1});
                maxEl = max(maxEl, nextElement);
            } else {
                break;
            }
        }

        return resultRange;
    }
};