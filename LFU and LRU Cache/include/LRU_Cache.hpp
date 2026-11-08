#include "../interface/I_Cache.hpp"
#include <unordered_map>
#pragma once

class LRU_Cache : public I_Cache
{
private:
    struct Node
    {
        int val, key;
        Node *prev = nullptr, *next = nullptr;

        Node()
        {
            val = -1, key = -1;
        }

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    int size;
    std::unordered_map<int, Node *> store;
    Node *head, *tail;

    Node *removeFromHead();

    void addToTail(Node *node);

    void removeNode(Node *node);

public:
    LRU_Cache(int n) : size(n)
    {
        head = new Node();
        tail = head;
    }

    void insert(int key, int value) override;

    std::optional<int> get(int key) override;
};