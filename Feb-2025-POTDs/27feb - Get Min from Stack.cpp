// Get Min from Stack



class Solution {
    public:
    stack<int>st;
    stack<int>minStack;
    
      Solution() {
          
      }
  
      // Add an element to the top of Stack
      void push(int x) {
          st.push(x);
          if(minStack.empty() || x<= minStack.top()){
              minStack.push(x);
          }
      }
  
      // Remove the top element from the Stack
      void pop() {
         if(st.empty())return;
         
          if(st.top()==minStack.top()){
              minStack.pop();
          }
          st.pop();
      }
  
      // Returns top element of the Stack
      int peek() {
          if(st.empty()) return -1;
          else return st.top();
      }
  
      // Finds minimum element of Stack
      int getMin() {
          if(minStack.empty() )return -1;
          else
          return minStack.top();
      }
  };
