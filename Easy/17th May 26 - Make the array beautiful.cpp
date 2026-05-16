// Make the array beautiful

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        int n = arr.size();
        vector<int> result; 
        result.push_back(arr[0]);
        for(int i = 1; i  < n; i++){
            if(!result.empty() && ((arr[i] < 0 && result.back() >= 0 ) || ( arr[i] >= 0 && result.back() < 0))){
                result.pop_back();
            }
            else result.push_back(arr[i]);
        }
        return result; 
    }
};