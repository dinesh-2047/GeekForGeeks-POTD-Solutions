// Maximum XOR of two numbers in an array 

class Solution {
    public:
        struct trieNode {
            trieNode* left;
            trieNode* right;
        };
        
        void insert(trieNode* head, int& num) {
            trieNode* pCrawl = head;
            for(int i = 31; i>=0; i--) {
                int ith_bit = (num>>i)&1;
                if(ith_bit == 0) {
                    if(!pCrawl->left) {
                        pCrawl->left = new trieNode();
                    }
                    pCrawl = pCrawl->left;
                } else {
                    if(!pCrawl->right) {
                        pCrawl->right = new trieNode();
                    }
                    pCrawl = pCrawl->right;
                }
            }
        }
        
        int maxxXor(trieNode* head, int &num) {
            int maxXor = 0;
            trieNode* pCrawl = head;
            //I am moving from left most bit(MSB) to right most(LSB) to get max answer so as to get set bit 1 in left most position (MSB) to get large decimal value
            for(int i = 31; i>=0; i--) {
                int ith_bit = (num>>i)&1;
                //I want maximum one in my result of xor
                //so, if I have current bit of 'num' = 1, I will select path where I get 0 in some other number
                if(ith_bit == 1) {
                    if(pCrawl->left) {
                        maxXor += pow(2, i); //if I am able to go to left, I can get 1 as XOR result of ith bit of both numbers (which is required)
                        pCrawl =  pCrawl->left;
                    } else {
    
                        pCrawl =  pCrawl->right;
                    }
                } else {
                    if(pCrawl->right) {
                        maxXor += pow(2, i); //if I am able to go to right, I can get 1 as XOR result of ith bit of both numbers (which is required)
                        pCrawl=  pCrawl->right;
                    } else {
                        pCrawl=  pCrawl->left;
                    }
                }
            }
            return maxXor;
        }
        
        int maxXor(vector<int>& arr) {
            trieNode* root = new trieNode();
            for(int &x: arr) {
                insert(root, x);
            }
    
            int result = 0;
    
            for(int &x : arr) {
                result = max(result, maxxXor(root, x));
            }
            return result;
        }
    };