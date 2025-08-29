// The Celebrity Problem




// Approach 1 using map 

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        unordered_map<int , set<int>>mp ; 
        
        for(int i = 0 ; i < n; i++ ){
            for(int j = 0 ; j  < n; j++){
                if(mat[i][j] == 1){
                    mp[i].insert(j);
                }
            }
        }
        int result = -1; 
        for(auto &pair : mp){
            auto key = pair.first; 
            auto st = pair.second; 
             
            if(st.size() == 1 && *st.begin()== key) {
                bool valid = true; 
                for(auto &p : mp){
                    auto s = p.second ; 
                    if(!s.count(key)){ 
                        valid = false; 
                        break; 
                    }
                    
                }
                if(valid) result = key; 
            } 
        }
        return result; 
    }
};










//Approach 2 iterative 
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i = 0 ; i < n; i++){
            bool isCelebrity = true; 
            for(int j = 0 ; j  < n ;j++){
                if(i!=j && (mat[i][j] == 1  || mat[j][i] == 0 )){
                    isCelebrity = false; 
                    break; 
                }
            }
            if(isCelebrity) return i; 
        }
        return -1; 
        
    }
};













//Approach 3 stack 

class Solution {
public:
    bool knows(vector<vector<int>> &mat , int a, int b){
        return mat[a][b] == 1;
    }
  
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        stack<int> st; 
        for(int i = 0; i < n; i++) {
            st.push(i);
        }
       
        // eliminate until one candidate remains
        while(st.size() > 1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(knows(mat, a, b)) {
                st.push(b); // a can't be celeb
            } else {
                st.push(a); // b can't be celeb
            }
        }
       
        int last = st.top(); st.pop();
        
        // check column: everyone knows last
        for(int i = 0; i < n; i++) {
            if(i != last && mat[i][last] == 0) return -1;
        }
        
        // check row: last knows nobody
        for(int j = 0; j < n; j++) {
            if(j != last && mat[last][j] == 1) return -1;
        }
        
        return last; 
    }
};

















//Approach 4 two pointer
class Solution{
public:
int celebrity(vector<vector<int>> & mat) {
    int n = mat.size();

    int i = 0, j = n - 1;
    while (i < j) {
        
        // j knows i, thus j can't be celebrity
        if (mat[j][i] == 1) 
            j--;

        // else i can't be celebrity
        else
            i++;
    }

    // i points to our celebrity candidate
    int c = i;

    // check if c is actually
    // a celebrity or not
    for (i = 0; i < n; i++) {
        if(i == c) continue;

        // if any person doesn't
        // know 'c' or 'c' doesn't
        // know any person, return -1
        if (mat[c][i] || !mat[i][c])
            return -1;
    }

    return c;
}
};