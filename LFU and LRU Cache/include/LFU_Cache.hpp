#include "../interface/I_Cache.hpp"
#include <unordered_map>
#include <utility>
#pragma once

class LFU_Cache : public I_Cache
{
private:
    int size;
    struct Node
    {
        int key, val, curr;
        Node *up = nullptr, *down = nullptr, *next = nullptr, *prev = nullptr;

        Node()
        {
            key = -1;
            val = -1;
            curr = -1;
        }

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            curr = 1;
        }
    };

    Node *head;
    std::unordered_map<int, Node *> mapping;
    std::unordered_map<int, std::pair<Node *, Node *>> cnt;

    Node *removeFromLast(Node *node);

    void addToCurr(Node *node, Node *last);

public:
    LFU_Cache(int n) : size(n)
    {
        head = new Node();
    }

    void insert(int key, int value) override;

    std::optional<int> get(int key) override;
};