// Last Digit of a^b

class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        
        int ld = (int)(a[a.size()-1]-'0') % 10;
        
        if(b=="0")
        return 1;
        
        int pow = (b.size()==1 ? (int)(b[0]-'0') : stoi(b.substr(b.size()-2)));
        
        if(ld == 0 || ld == 1 || ld == 5 || ld == 6)
        return ld;
        if(ld == 4)
        {
            if(pow%2)
            return 4;
            return 6;
        }
        if(ld == 9)
        {
            if(pow%2)
            return 9;
            return 1;
        }
        if(ld == 3)
        {
            if(pow%4==0)
            return 1;
            if(pow%4==1)
            return 3;
            if(pow%4==2)
            return 9;
            return 7;
        }
        if(ld == 2)
        {
            if(pow%4==0)
            return 6;
            if(pow%4==1)
            return 2;
            if(pow%4==2)
            return 4;
            return 8;
        }
        if(ld == 7)
        {
            if(pow%4==0)
            return 1;
            if(pow%4==1)
            return 7;
            if(pow%4==2)
            return 9;
            return 3;
        }
        if(ld == 8)
        {
            if(pow%4==0)
            return 6;
            if(pow%4==1)
            return 8;
            if(pow%4==2)
            return 4;
            return 2;
        }
        
        return 0;
    }
};