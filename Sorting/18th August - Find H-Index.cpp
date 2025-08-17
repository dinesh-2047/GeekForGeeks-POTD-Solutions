// Find H-Index



// Approach 1 - Binary search on answer 
class Solution {
  public:
  
  bool isPossible(vector<int>& citations, int mid){
      int n = citations.size();
       int count = 0  ;
      for(int i = 0 ; i  < n; i++){
          if(citations[i] >= mid){
              count++;
          }
      }
      return count>=mid; 
  }
  
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        
        int l = 0 ; 
        int r = n ; 
        
        int result = 0 ; 
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(isPossible(citations, mid)){
               result = mid ; 
               l = mid + 1; 
            }
            else r = mid -1; 
        }
        return result; 
    }
};


// Approach 2 Sorting 
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.rbegin(), citations.rend());
        
        int count = 0 ; 
        
        for(int i = 0 ; i < n; i++){
          
            if(citations[i] >= i + 1){
               count++; 
            }
        }
        return count ; 
        
    }
};


//Approach 3 also sorting 
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.rbegin(), citations.rend());
        
        int count = 0 ; 
        
        for(int i = 0 ; i < n; i++){
          
            if(citations[i] >count){
               count++; 
            }
            else break; 
        }
        return count ; 
        
    }
};


//Approach 4 Counting sort 
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        
        vector<int>freq(n + 1, 0);
        
        for(int i = 0 ; i < n; i++){
            if(citations[i] >= n ){
                freq[n]++;
            }
            else freq[citations[i]]++;
        }
        
        int i = n; 
        int cnt = freq[n];
        
        while( cnt < i){
            i--;
            cnt += freq[i];
            
        }
        return i ;
    }
};