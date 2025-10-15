// Copyright 2025 Ekaterina P.
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "../lib_queue/queue.h"
using namespace std;


TEST(TestQueue, can_push_elements) {
	Queue<int> queue;
	queue.push(10);
	EXPECT_FALSE(queue.is_empty());
	EXPECT_EQ(queue.size(), 1);
	queue.push(20);
	queue.push(30);
	EXPECT_EQ(queue.size(), 3);
}

TEST(TestQueue, can_create_empty_queue) {
	Queue<int> queue;
	EXPECT_TRUE(queue.is_empty());
	EXPECT_EQ(queue.size(), 0);
}

TEST(TestStack, can_pop_elements) {
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);

	EXPECT_EQ(queue.pop(), 3);
	EXPECT_EQ(queue.pop(), 2);
	EXPECT_EQ(queue.pop(), 1);
	EXPECT_TRUE(queue.is_empty());
}

TEST(TestQueue, can_clear_queue) {
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);

	queue.clear();
	EXPECT_TRUE(queue.is_empty());
	EXPECT_EQ(queue.size(), 0);
}
