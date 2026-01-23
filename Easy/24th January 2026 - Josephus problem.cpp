// Josephus problem


// Approach 1 

class Solution {
  public:
    int josephus(int n, int k) {
        vector<int> rem(n, false);

        int removed = 0;
        int i = 0;

        while (removed < n - 1) {
            int cnt = 0;

            while (true) {
                if (!rem[i]) {
                    cnt++;
                    if (cnt == k) break;
                }
                i = (i + 1) % n;
            }

            rem[i] = true;
            removed++;

            do {
                i = (i + 1) % n;
            } while (rem[i]);
        }

        for (int j = 0; j < n; j++) {
            if (!rem[j]) return j + 1;
        }

        return -1;
    }
};






//Approach 2 
class Solution {
  public:
    int josephus(int n, int k) {
        queue<int>q; 
        
       for(int i = 1; i  <= n; i++) q.push(i);
       
       int cnt = k;
       
       while(q.size() > 1){
           while(cnt > 1){
               auto curr = q.front();
               q.pop();
               q.push(curr);
               cnt--;
           }
           cnt = k ; 
           q.pop();
       }
       return q.front();
    }
};



//Approach 3
class Solution {
  public:
    int josephus(int n, int k) {
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = (res + k) % i;
        }
        return res + 1;
    }
};