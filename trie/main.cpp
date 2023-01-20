#include <iostream>
#include "trie.h"

int main()
{
    Trie *trie = new Trie();
    trie->add("dog");
    trie->add("cat");

    cout << "Search cat: " << trie->search("cat") << endl;
    cout << "Search dog: " << trie->search("dog") << endl;
    cout << "Search horse: " << trie->search("horse") << endl;

    trie->deleteNode();
    delete trie;

    return 0;
}
