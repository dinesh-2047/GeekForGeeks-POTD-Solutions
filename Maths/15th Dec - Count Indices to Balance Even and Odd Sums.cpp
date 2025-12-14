// Count Indices to Balance Even and Odd Sums


class Solution {
  public:
     int cntWays(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int, int>>v(n);
        int odd=0, even=0, cnt=0;
        for(int i=arr.size()-1; i>=0; i--){
            if(i%2) odd+=arr[i];
            else even+=arr[i];
            v[i].first=odd;
            v[i].second=even;
        }
        int odd1=0, even1=0;
        for(int i=0; i<arr.size()-1; i++){
            if(odd1+v[i+1].second==even1+v[i+1].first) cnt++;
            if(i%2) odd1+=arr[i];
            else even1+=arr[i];
        }
        if(odd1==even1) cnt++;
        return cnt;
    }


};