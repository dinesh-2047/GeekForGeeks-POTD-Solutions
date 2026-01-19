// Implement UNDO & REDO

class Solution {
  public:
  string document; 
  string u; 
    void append(char x) {
        document.push_back(x);
    }

    void undo() {
        char element = document.back();
        document.pop_back();
        u.push_back(element);
        
    }

    void redo() {
        char element = u.back();
        u.pop_back();
        document.push_back(element);
    }

    string read() {
       return document; 
    }
};