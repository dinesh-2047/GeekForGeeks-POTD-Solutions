// Prime List


class Solution {
    public:
      Node *primeList(Node *head) {
          
          Node *temp = head; 
          int n = 0; 
          while(temp){
              n = max(n , temp->val);
              temp = temp->next; 
          }
          
          //precompute prime numbers 
          vector<bool>isPrime(11000, true);
          isPrime[0] = isPrime[1] = false; 
          for(int i = 2; i <=11000; i++){
              if(isPrime[i]){
                  for(int j = i*i; j<11000; j+=i){
                      isPrime[j] = false; 
                  }
              }
          }
          vector<int>primeNumbers;
          for(int i  = 0 ; i < isPrime.size(); i++){
              if(isPrime[i]) primeNumbers.push_back(i);
          }
          
          temp = head; 
        
          while(temp){
             int val = temp->val;
           
           
  
              auto right = lower_bound(primeNumbers.begin(), primeNumbers.end(), val); // ≥ val
              auto left = (right == primeNumbers.begin()) ? right : prev(right);
  
              // Choose closest prime
              if (right == primeNumbers.end() || 
                 (left != primeNumbers.end() && abs(*left - val) <= abs(*right - val))) {
                  temp->val = *left;
              } else {
                  temp->val = *right;
              }
  
              temp = temp->next; 
          }
          return head; 
      }
  };