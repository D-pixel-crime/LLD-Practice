#include "../include/LFU_Cache.hpp"

LFU_Cache::Node *LFU_Cache::removeFromLast(Node *node)
{
    auto &[h, t] = cnt[node->curr];

    auto next = node->next, prev = node->prev;
    if (next)
    {
        next->prev = prev;
    }
    prev->next = next;

    if (t == node)
    {
        t = prev;
    }
    node->prev = node->next = nullptr;

    if (!h->next)
    {
        auto up = h->up, down = h->down;
        if (up)
        {
            up->down = down;
        }
        down->up = up;

        delete h;
        cnt.erase(node->curr);

        return down;
    }

    return h;
}

void LFU_Cache::addToCurr(Node *node, Node *last)
{
    if (!cnt.count(node->curr))
    {
        auto h = new Node();
        auto t = h;
        cnt[node->curr] = std::make_pair(h, t);

        auto up = last->up;
        if (up)
        {
            up->down = h;
        }
        last->up = h;
        h->up = up;
        h->down = last;
    }

    auto &t = cnt[node->curr].second;

    node->prev = t;
    t->next = node;
    node->next = nullptr;
    t = node;
}

void LFU_Cache::insert(int key, int value)
{
    Node *node;

    if (!mapping.count(key))
    {
        node = new Node(key, value);
        mapping[key] = node;

        if (!size)
        {
            auto toRem = head->up->next;
            removeFromLast(toRem);
            mapping.erase(toRem->key);
            delete toRem;
        }
        else
        {
            size--;
        }

        addToCurr(node, head);

        return;
    }

    node = mapping[key];
    auto last = removeFromLast(node);
    node->curr++;
    node->val = value;
    addToCurr(node, last);
}

std::optional<int> LFU_Cache::get(int key)
{
    if (mapping.count(key))
    {
        auto node = mapping[key];
        auto last = removeFromLast(node);
        node->curr++;
        addToCurr(node, last);

        return node->val;
    }

    return std::nullopt;
}