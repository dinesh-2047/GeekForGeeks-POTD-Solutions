// Maximum Reachable Index Difference

class Solution {
public:
    int maxIndexDifference(string &s) {
        int maxi = 0;
        int k = -1;
        for(int i = 0;i<s.length();i++){
            if(s[i] == 'a'){
                k = i;
                break;
            }
        }
        if(k == -1){
            return k;
        }
        int l = -1;
        for(int i = k+1;i<s.length();i++){
            int a = s[i]-'a';
            if(s[i] == 'a'){
                continue;
            }
            if(maxi >= a-1){
                l = i;
                maxi = max(maxi,s[i]-'a');
            }
        }
        if(l == -1){
            return 0;
        }
        return l-k;
    }
};

