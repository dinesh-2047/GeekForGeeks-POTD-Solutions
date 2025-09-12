// Minimum Cost to cut a board into squares


class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
       
       sort(rbegin(x), rend(x));
       sort(rbegin(y), rend(y));
       
       int n1 = x.size();
       int n2 = y.size();
       
      int v_seg = 1; 
      int h_seg = 1; 
      int cost = 0 ; 
      
       int i = 0 ; 
       int j = 0 ; 
       
       while(i < n1 && j < n2){
           if(x[i] >= y[j]){
               cost  += x[i] * h_seg;
               v_seg++;
               i++;
           }
           else{
               cost += y[j] * v_seg;
               h_seg++;
               j++;
           }
       }
       while(i < n1){
           cost += x[i] * h_seg;
           v_seg++;
           i++;
       }
       while(j < n2){
           cost += y[j] * v_seg;
           h_seg++;
           j++;
       }
        return cost ; 
    }
};
