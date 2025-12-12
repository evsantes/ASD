#include "queue_list.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(QueueTest, can_create_empty_queue) {
    Queue<int> q;
    EXPECT_TRUE(q.is_empty());
}

TEST(QueueTest, can_push_elements) {
    Queue<int> q;
    q.push(10);
    EXPECT_EQ(q.head(), 10);
}

TEST(QueueTest, can_pop_elements) {
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.pop();
    EXPECT_EQ(q.head(), 20);
}

TEST(QueueTest, size_queue) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    EXPECT_EQ(q.size(), 2);
}

TEST(QueueTest, can_clear_queue) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.clear();
    EXPECT_TRUE(q.is_empty());
}