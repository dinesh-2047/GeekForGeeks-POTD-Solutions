// Difference Check



// Approach 1 using sorting 

class Solution {
public:
    int convertToSeconds(string &t) {
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3, 2));
        int s = stoi(t.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }

    int minDifference(vector<string> &arr) {
        vector<int> seconds;
        
        for (auto &t : arr) {
            seconds.push_back(convertToSeconds(t));
        }
        
        sort(seconds.begin(), seconds.end());
        
        int diff = INT_MAX;
        int n = seconds.size();

        for (int i = 1; i < n; i++) {
            diff = min(diff, seconds[i] - seconds[i - 1]);
        }

        diff = min(diff, 86400 - (seconds[n - 1] - seconds[0]));

        return diff;
    }
};













//Approach one in O(n) and O(86400)
class Solution {
public:
    int convertToSeconds(string &t) {
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3, 2));
        int s = stoi(t.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }

    int minDifference(vector<string> &arr) {
        int n = arr.size();
        
        vector<int>seen(86400, false);
        
        for (auto &t : arr) {
            int sec = convertToSeconds(t);
            if(seen[sec]) return 0;
            seen[sec] = true; 
        }
        int first = -1 ; 
        int prev = -1 ; 
        int last = -1; 
        int diff = INT_MAX;
        
        
        for(int i =0 ; i < 86400; i++){
            if(!seen[i]) continue ; 
            if(prev!=-1) diff= min(diff, i - prev);
            else first = i ; 
            prev = i; 
            last = i ; 
        }
        
        diff = min(diff , first  + 86400-last);
        return diff; 
        
        
        
      
    }
};