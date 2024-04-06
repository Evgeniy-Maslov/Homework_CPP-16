#include <iostream>
//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {       
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

    //юнит-тест

TEST_CASE("Testing the PushFront", "[list.PushFront()]") {
    List list;
    list.PushFront(5);
    list.PushFront(6);
    REQUIRE(list.Size() == 2);
}
TEST_CASE("Testing the PushBack", "[list.PushBack()]") {
    List list;
    list.PushBack(5);
    list.PushBack(6);
    REQUIRE(list.Size() == 2);
}
TEST_CASE("Testing the PopBack", "[list.PopBack()]") {
    List list;
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        list.PushBack(i);
    }
    try
    {
        while (!list.Empty())
        {
            REQUIRE(list.PopBack() == n);
            --n;
        }
        REQUIRE(list.PopBack() == n);
    }
    catch (std::runtime_error& err) { std::cout << err.what(); }
}
TEST_CASE("Testing the PopFront", "[list.PopFront()]") {
    List list;
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        list.PushFront(i);
    }
    try
    {
        while (!list.Empty())
        {
            REQUIRE(list.PopFront() == n);
            --n;
        }
        REQUIRE(list.PopFront() == n);
    }
    catch (std::runtime_error& err) { std::cout << err.what(); }
}
