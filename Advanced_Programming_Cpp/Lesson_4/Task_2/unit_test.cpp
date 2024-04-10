#include "main.cpp"
//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>



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
    while (!list.Empty())
    {
        INFO("PopBack() != n");
        REQUIRE(list.PopBack() == n);
        --n;
    }
    REQUIRE_THROWS(list.PopBack() == n);

}
TEST_CASE("Testing the PopFront", "[list.PopFront()]") {
    List list;
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        list.PushFront(i);
    }
    while (!list.Empty())
    {
        INFO("PopFront() != n");
        REQUIRE(list.PopFront() == n);
        --n;
    }
    REQUIRE_THROWS(list.PopFront() == n);
}
