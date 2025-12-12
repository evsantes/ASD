#include "stack_list.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(StackTest, can_create_empty_stack) {
    Stack<int> stack;

    // Проверяем, что стек пустой
    EXPECT_TRUE(stack.is_empty());
    EXPECT_EQ(stack.size(), 0);
    EXPECT_FALSE(stack.is_full());
}

TEST(StackTest, can_push_one_elememt) {
    Stack<int> stack;

    stack.push(42);

    // Проверяем, что стек не пустой
    EXPECT_FALSE(stack.is_empty());
    EXPECT_EQ(stack.size(), 1);

    // Проверяем верхний элемент
    EXPECT_EQ(stack.top(), 42);
}

TEST(StackTest, can_push_multiple_elements) {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    EXPECT_FALSE(stack.is_empty());
    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.top(), 30);  // Последний добавленный наверху
}

TEST(StackTest, can_pop_elements) {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Удаляем верхний элемент
    stack.pop();

    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.top(), 20);  // Теперь 20 наверху

    // Удаляем еще раз
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 10);

    // Последний раз
    stack.pop();
    EXPECT_TRUE(stack.is_empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, can_clear_stack) {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.size(), 3);

    stack.clear();

    EXPECT_TRUE(stack.is_empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, can_work_after_clear) {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.clear();

    // После очистки можно снова использовать
    stack.push(30);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 30);
}

TEST(StackTest, can_work_with_mixed_operations) {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.top(), 2);

    stack.pop();
    EXPECT_EQ(stack.top(), 1);

    stack.push(3);
    EXPECT_EQ(stack.top(), 3);

    stack.push(4);
    EXPECT_EQ(stack.size(), 3);

    stack.pop();
    stack.pop();
    EXPECT_EQ(stack.top(), 1);
}