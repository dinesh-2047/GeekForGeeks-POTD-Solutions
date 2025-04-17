// Implement Trie


class TrieNode {
    public:
    TrieNode* children[26];
    bool isTerminal ;
};
class Trie {
  public:
  
  TrieNode *getNode(char ch ){
      TrieNode *newNode = new TrieNode();
      newNode->isTerminal = false; 
      
      for(int i = 0 ; i < 26 ; i++){
          newNode->children[i]= NULL;
      }
      return newNode; 
  }
  
  TrieNode * root ; 

    Trie() {
       root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode *crawl =  root;
        
       for(auto &ch : word){
           int idx = ch - 'a';
           
           if(crawl->children[idx] == NULL){
               crawl->children[idx] =  getNode(ch);
               
           }
           crawl =  crawl->children[idx];
           }
           crawl->isTerminal = true; 
    }

    bool search(string &word) {
        TrieNode *crawl = root;
        for(auto &ch : word){
            int idx = ch - 'a';
            
            if(crawl->children[idx]==NULL) return false;
            crawl =  crawl->children[idx];
        }
        
        return crawl->isTerminal; 
    }

    bool isPrefix(string &word) {
        TrieNode *crawl = root;
        for(auto &ch : word){
            int idx = ch - 'a';
            
            if(crawl->children[idx]==NULL) return false; 
            crawl =  crawl->children[idx];
        }
        
      
    
      return true;
    
    }
};