#include <gtest/gtest.h>
#include "../linear_list/linear_list.h"

TEST(TestLibLib, can_iterate) {
	List<int> list;

	for (int i = 0; i < 10; i++) {
		list.push_back(i + 1);
	}

	int expected_val = 1;
	for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
		EXPECT_EQ(*it, expected_val);
		expected_val++;
	}

	int expected_val = 1;
	for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
		*it = expected_val;
		expected_val++;
	}

	int expected_val = 1;
	for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
		EXPECT_EQ(*it, expected_val);
		expected_val++;
	}

	List<int> list;
	for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
		*it = 0;
	}
}
