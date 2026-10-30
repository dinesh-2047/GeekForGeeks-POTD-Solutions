// Maximum Packages within Time

class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int n = arr.size();

        if(n <= totalTime){
            return accumulate(begin(arr), end(arr), 0);
        }
        vector<int> pref(n);
        pref[0] = arr[0];
        
        for(int i = 1 ; i  < n; i++){
            pref[i] = pref[i-1] + arr[i];
        }
        
        int i = 0;
        int j = 0 ; 
        int result = 0 ;
        
        while(j < n ){
            if(j - i + 1 == totalTime ){
                int sum = pref[j];
                if(i - 1 >=0 ){
                    sum -= pref[i-1];
                }
                result = max(result, sum);
                i++;
            }
            j++;
        }
        return result;
        
    }
};