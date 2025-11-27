// Subset XOR


class Solution {
public:
    int getSkip(int n){
        int rem=n%4;

        if(rem==0) {
            return -1;          // keep all
        }
        else if(rem==3) {
            return n;           // remove n
        }
        else if(rem==2) {
            return 1;           // remove 1
        }
        else { // rem== 1
            if(n==1) return -1; 
            return n-1;       // remove n-1
        }
    }

    vector<int> subsetXOR(int n) {
        vector<int> ans;

        int skip=getSkip(n);   // get element to skip

        for(int i=1; i<=n;i++){
            if (i==skip){
                continue;
            }
            
            ans.push_back(i);
        }

        return ans;
    }
};