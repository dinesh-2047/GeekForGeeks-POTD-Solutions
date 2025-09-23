// Design MinMax Queue

class SpecialQueue {

  public:
  queue<int>q; 
  multiset<int>st; 

    void enqueue(int x) {
        q.push(x);
       st.insert(x);
    }

    void dequeue() {
       int element = q.front();
       q.pop();
       auto it = st.find(element);
       st.erase(it);
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return *st.begin();
    }

    int getMax() {
       return *prev(st.end());
    }
};