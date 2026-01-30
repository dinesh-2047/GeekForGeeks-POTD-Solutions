// Implement k Queues in a Single Array


class kQueues {
  public:
  vector<int>arr; 
  vector<int>front; 
  vector<int>rear; 
  vector<int>next; 
  int n , k ; 
  int freeIdx ; 
    kQueues(int N, int K) {
        n = N , k = K ;
       freeIdx = 0 ; 
       arr.resize(n);
       next.resize(n);
       front.resize(k,-1);
       rear.resize(k, -1);
       
       for(int i = 0; i < n-1; i++) next[i] = i +1 ; 
       next[n-1] = -1;
    }

    void enqueue(int x, int i) {
      int idx = freeIdx; 
      freeIdx = next[idx];
      
      if(front[i] == -1) front[i] = idx; 
      else next[rear[i]] = idx; 
      
      rear[i] = idx ; 
      arr[idx] = x; 
      
      next[idx] = -1; 
      
       
    }

    int dequeue(int i) {
        if(front[i] == -1) return -1; 
        int idx = front[i];
        front[i] = next[idx];
        
        if(front[i] == -1) rear[i] = -1; 
        next[idx] = freeIdx; 
        freeIdx = idx ; 
        return arr[idx];
    }

    bool isEmpty(int i) {
        return front[i] == -1; 
    }

    bool isFull() {
       return freeIdx == -1 ; 
    }
};
