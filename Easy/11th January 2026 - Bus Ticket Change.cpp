// Bus Ticket Change

class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int n = arr.size();
        
        int five = 0 ; 
        int ten = 0 ; 
        
        for(int i = 0 ; i  < n; i++){
            if(arr[i] == 5) five++;
            else if(arr[i] == 10){
                if(!five) return false;
                ten++;
                five--;
            }
            else {
                if(five >= 1 && ten >= 1 ){
                    five--;
                    ten--;
                }
                else if(five >= 3) five -= 3; 
                else return false; 
            }
        }
        return true;
    }
};