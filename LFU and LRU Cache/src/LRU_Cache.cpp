#include "../include/LRU_Cache.hpp"

void LRU_Cache::addToTail(Node *node)
{
    node->prev = tail;
    tail->next = node;
    node->next = nullptr;
    tail = node;
}

void LRU_Cache::removeNode(LRU_Cache::Node *node)
{
    if (!node)
    {
        return;
    }

    auto prev = node->prev, next = node->next;
    if (next)
    {
        next->prev = prev;
    }

    if (node == tail)
    {
        tail = prev;
    }

    prev->next = next;
    node->next = node->prev = nullptr;
}

LRU_Cache::Node *LRU_Cache::removeFromHead()
{
    auto node = head->next;
    removeNode(node);

    return node;
}

void LRU_Cache::insert(int key, int value)
{
    Node *node;

    if (!store.count(key))
    {
        if (!size)
        {
            auto toRem = removeFromHead();
            store.erase(toRem->key);
            delete toRem;
        }
        else
        {
            size--;
        }

        node = new Node(key, value);
        store[key] = node;
        addToTail(node);

        return;
    }

    node = store[key];
    node->val = value;
    removeNode(node);
    addToTail(node);
}

std::optional<int> LRU_Cache::get(int key)
{
    if (store.count(key))
    {
        auto node = store[key];
        removeNode(node);
        addToTail(node);

        return node->val;
    }

    return std::nullopt;
}