// K closest elements

class Solution {
  public:
vector<int> printKClosest(vector<int> arr, int k, int x) {     
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto it:arr){
            if(it==x){
                continue;
            }
            else if(pq.size()<k){
                pq.push({abs(x-it),it});
            }
            else if(pq.top().first>abs(x-it) 
            || pq.top().first==abs(x-it) && pq.top().second<it){
                pq.pop();
                pq.push({abs(x-it),it});
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        for(int i=1;i<ans.size();i++){
            if(abs(ans[i]-x)==abs(ans[i-1]-x)){
                swap(ans[i],ans[i-1]);
            }
        }
        return ans;
    }
};