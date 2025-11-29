// Count of distinct substrings


class Solution
{
public:
    struct Node
    {
        Node *links[26];
        Node()
        {
            for (int i = 0; i < 26; i++)
                links[i] = NULL;
        }
        bool ContainsKey(char ch)
        {
            return (links[ch - 'a'] != NULL);
        }
        void Put(char ch, Node *node)
        {
            links[ch - 'a'] = node;
        }
        Node *Get(char ch)
        {
            return links[ch - 'a'];
        }
    };

    int countSubs(string &s)
    {
        Node *root = new Node();
        int n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            Node *curr = root;
            for (int j = i; j < n; j++)
            {
                if (curr->ContainsKey(s[j]) == false)
                {
                    cnt++;
                    curr->Put(s[j], new Node());
                }
                curr = curr->Get(s[j]);
            }
        }
        return cnt;
    }
};
