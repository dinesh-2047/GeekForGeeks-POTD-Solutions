// Max Equal Sum in 3 Stacks

class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        int sum1 = 0; 
        int sum2 = 0 ; 
        int sum3 = 0 ; 
        
        for(auto &x : s1) sum1 += x ; 
        for(auto &x : s2) sum2 += x; 
        for(auto &x : s3) sum3 += x; 
        
        
        int i = 0 ; 
        int j = 0 ; 
        int k = 0 ; 
        
        while(i < s1.size() || j < s2.size() || k < s3.size()){
            if(sum1 == sum2 && sum2 == sum3) return sum1; 
            else if(sum1 >= sum2 && sum1 >= sum3) sum1 -= s1[i++];
            else if(sum2 >= sum1 && sum2 >= sum3){
                sum2 -= s2[j++];
            }
            else sum3 -= s3[k++];
        }
        return 0 ;
        
    }
};