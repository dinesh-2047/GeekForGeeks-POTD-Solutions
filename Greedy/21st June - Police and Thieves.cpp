// Police and Thieves


// Approach 1 using queue

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        
        queue<int>police; 
        queue<int>thief; 
        int result = 0 ; 
        
        for(int i = 0 ; i <n; i++){
            if(arr[i] == 'P') police.push(i);
            else thief.push(i);
            
            while(!thief.empty() && !police.empty()){
                if(abs(thief.front() - police.front()) <= k){
                    result++;
                    thief.pop();
                    police.pop();
                }
                    else if(thief.front() < police.front()){
                        thief.pop();
                    }
                    else police.pop();
                
            }
        }
        return result; 
        
    }
};