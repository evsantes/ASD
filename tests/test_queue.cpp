// Copyright 2025 Ekaterina P.
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "../lib_queue/queue.h"
using namespace std;


TEST(TestQueue, can_push_elements) {
	Queue<int> queue;
	EXPECT_EQ(queue.size(), 20);
	queue.push(10);
	EXPECT_FALSE(queue.is_empty());
	EXPECT_EQ(queue.count(), 1);
	queue.push(20);
	queue.push(30);
	EXPECT_EQ(queue.count(), 3);
}

TEST(TestQueue, can_create_empty_queue) {
	Queue<int> queue(10);
	EXPECT_TRUE(queue.is_empty());
	EXPECT_EQ(queue.size(), 10);
}

TEST(TestQueue, can_pop_elements) {
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);

	EXPECT_EQ(queue.top(), 1);
	queue.pop();
	EXPECT_EQ(queue.top(), 2);
	queue.pop();
	EXPECT_EQ(queue.top(), 3); 
	queue.pop();
	EXPECT_TRUE(queue.is_empty());
}

TEST(TestQueue, can_clear_queue) {
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);

	queue.clear();
	EXPECT_TRUE(queue.is_empty());
	EXPECT_EQ(queue.count(), 0);
}
