// Maximum Number of People Defeated

class Solution {
  public:
    int maxPeopleDefeated(int p) {
       int dem = 0 ; 
       int i = 1 ; 
       
       while(p - (i * i ) >= 0 ){
           dem++;
           p  = p - i * i ; 
           i++;
       }
       return dem ; 
        
    }
};
