#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct TrieNode
{
    TrieNode()
    {
        valid = false;
    }

    unordered_map<char, TrieNode *> next;
    bool valid;
};

class Trie
{

    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    /**
     * Add a new word into this trie.
     * @param word
     */
    void add(const string &word)
    {
        TrieNode *node = root;

        for (char c : word)
        {
            // add this char into the trie if it doesn't exit
            if (node->next.find(c) == node->next.end())
            {
                node->next[c] = new TrieNode();
            }
            // go one step down
            node = node->next[c];
        }
        node->valid = true;
    }

    /**
     * Search a specific word.
     * @param word
     * @return true if we have it.
     */
    bool search(const string &word)
    {
        TrieNode *node = root;

        for (char c : word)
        {
            if (node->next.find(c) == node->next.end())
            {
                return false;
            }
            // go one step down
            node = node->next[c];
        }

        return node->valid;
    }

    /**
     * Delete this trie.
     */
    void deleteNode()
    {
        queue<TrieNode*> queue;
        queue.push(root);

        while (!queue.empty())
        {
            TrieNode* node = queue.front();
            queue.pop();

            for (auto item : node->next)
            {
                queue.push(item.second);
            }

            delete node;
        }
    }
};
