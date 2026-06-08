// Seating Arrangement

class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        int n = seats.size();
        int count = 0 ; 
        if(n == 1 && k == 1 && seats[0] == 0 ) return true; 
        
        for(int i = 0 ; i  < n; i++){
            if(seats[i] == 0){
                if(i == 0 && i + 1 < n && seats[i + 1] == 0  ){
                     seats[i] = 1; 
                     count++;
                }
                else if(i == n - 1 && i - 1 >= 0 && seats[i - 1] == 0 ){
                    seats[i] = 1; 
                    count++;
                }
                else if(i - 1 >= 0 && i + 1 < n ){
                    if(seats[i - 1] == 0 && seats[i + 1] == 0 ) {
                        seats[i] = 1; 
                        count++;
                    }
                }
                
                if(count == k ) return true; 
            }
        }
        return count == k ; 
        
    }
};