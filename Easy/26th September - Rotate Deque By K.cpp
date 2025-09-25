// Rotate Deque By K


class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        if(type == 1){
            while(k--){
                int value = dq.back();
                dq.pop_back();
                dq.push_front(value);
            }
        }
        else{
            while(k--){
                int value = dq.front();
                dq.pop_front();
                dq.push_back(value);
            }
            
        }
    }
};