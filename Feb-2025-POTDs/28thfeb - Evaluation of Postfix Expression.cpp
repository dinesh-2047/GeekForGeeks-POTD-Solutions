// Evaluation of Postfix Expression


class Solution {
    public:
    bool isoperator(string s){
        if(s=="*" || s=="+" || s=="-"|| s=="/") return true;
        else return false;
    }
      int evaluate(vector<string>& arr) {
          stack<int>st;
          int n = arr.size();
          int ans=0;
          for(int i=0; i<n;i++){
              if(isoperator(arr[i])){
                  if(st.size()<2) return -1;
                  int first = st.top();
                  st.pop();
                  int second = st.top();
                  st.pop();
                  
                  if(arr[i]=="*") ans=second*first;
                  if(arr[i]=="+") ans=second+first;
                  if(arr[i]=="-") ans= second-first;
                  if(arr[i]=="/"){
                      if (first==0) return -1;
                      ans=second/first;
                  }
                  st.push(ans);
              }
              else
              st.push(stoi(arr[i]));
          }
          return st.top();
      }
  };