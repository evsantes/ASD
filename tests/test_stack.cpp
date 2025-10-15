// Copyright 2025 Ekaterina P.
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "../lib_stack/stack.h"
using namespace std;


TEST(TestStack, can_push_elements) {
	Stack<int> stack;
	stack.push(10);
	EXPECT_FALSE(stack.is_empty());
	EXPECT_EQ(stack.size(), 1);
	stack.push(20);
	stack.push(30);
	EXPECT_EQ(stack.size(), 3);
}

TEST(TestStack, can_create_empty_stack) {
	Stack<int> stack;
	EXPECT_TRUE(stack.is_empty());
	EXPECT_EQ(stack.size(), 0);
}

TEST(TestStack, can_pop_elements) {
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	EXPECT_EQ(stack.pop(), 3);
	EXPECT_EQ(stack.pop(), 2);
	EXPECT_EQ(stack.pop(), 1);
	EXPECT_TRUE(stack.is_empty());
}

TEST(TestStack, top_element) {
	Stack<int> stack;
	stack.push(100);
	EXPECT_EQ(stack.top(), 100);

	stack.push(200);
	EXPECT_EQ(stack.top(), 200);
}

TEST(TestStack, can_clear_stack) {
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	stack.clear();
	EXPECT_TRUE(stack.is_empty());
	EXPECT_EQ(stack.size(), 0);
}