// Sum of Mode

class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
            int n = arr.size();
    int sum = 0;

    // Stores frequency of elements 
    // in current window
    unordered_map<int, int> mp;

    // Stores (frequency, -value) to maintain
    // order of mode selection
    set<pair<int, int>> st;

    // Build frequency map for the first window
    for (int i = 0; i < k; i++) {
        mp[arr[i]]++;
    }

    // Populate the set with initial frequency pairs
    for (auto x : mp) {
        st.insert({x.second, -x.first});
    }

    // Add mode of the first window
    int mode = -st.rbegin()->second;
    sum += mode;

    // Slide the window across the array
    for (int i = k; i < n; i++) {
        int out = arr[i - k];
        int in = arr[i];

        // Remove the outgoing element's 
        // previous frequency pair
        st.erase({mp[out], -out});

        // Decrement frequency of 
        // outgoing element
        mp[out]--;

        // If frequency is still positive, 
        // reinsert updated pair
        if (mp[out] > 0) {
            st.insert({mp[out], -out});
        } else {
            mp.erase(out);
        }

        // Increment frequency of incoming element
        mp[in]++;

        // Insert updated frequency pair 
        // for incoming element
        st.insert({mp[in], -in});

        // Get current mode and add to sum
        mode = -st.rbegin()->second;
        sum += mode;
    }

    return sum;
    }
};