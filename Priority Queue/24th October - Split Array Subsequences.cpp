// Split Array Subsequences


// Approach 1 
class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
       int n= arr.size();
       
       unordered_map<int , int>freq ;
       for(auto &num :arr) freq[num]++;
        
        unordered_map<int , int>need; 
        
        for(auto &num : arr){
            if(freq[num] == 0 ) continue; 
            
            if(need[num - 1] > 0 ){
                need[num - 1]--;
                need[num ]++;
                freq[num]--;
            }
            else{
                bool isPossible = true; 
                for(int i = 0; i < k ; i++){
                    if(freq[num + i ] <= 0  ){
                        isPossible = false; 
                        break; 
                    }
                }
                if(!isPossible) return false; 
                
                for(int i = 0; i  < k; i++){
                    freq[num + i ]--;
                    
                }
                need[num + k - 1]++;
            }
        }
        return true; 
    }
};








//Approach 2 
class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
       int n = arr.size();
       
       auto comp = [](pair<int,int> a, pair<int,int> b) {
            if(a.first == b.first)
                return a.second > b.second; 
            return a.first > b.first;      
        };
        
        priority_queue<pair<int , int>, vector<pair<int , int>>, decltype(comp)> pq(comp);
        int i =0 ; 
       while(i < n ){
           if(pq.empty()){
               pq.push({ arr[i], 1});
               i++;
           }
           else{
               auto curr = pq.top();
               if(arr[i] == curr.first){
                   pq.push({ arr[i], 1});
                   i++;
               }
               else if(arr[i] == curr.first + 1){
                   pq.pop();
                   pq.push({ arr[i], curr.second + 1});
                   i++;
               }
               else {
                  if(curr.second < k) return false; 
                   pq.pop();
               }
           }
           
           
       }
       while(!pq.empty()){
           if(pq.top().second < k ) return false; 
           pq.pop();
       }
       return true; 
        
    }

};