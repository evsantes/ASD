#include <gtest/gtest.h>
#include "algirithms.h"
using namespace std;

TEST(TestBrackets, test_empty_string) {
	string s = "";

	EXPECT_EQ(checkBrackets(s), true);
}
TEST(TestBrackets, test_twice_round_bracket) {
	string s = "()";

	EXPECT_EQ(checkBrackets(s), true);

}
TEST(TestBrackets, test_twice_round_bracket_with_symbols) {
	string s = "a(dcs)b";

	EXPECT_EQ(checkBrackets(s), true);

}
TEST(TestBrackets, test_round_bracket) {
	string s = "(";

	EXPECT_EQ(checkBrackets(s), false);

}

TEST(TestBrackets, test_figure_bracket) {
	string s = "{";

	EXPECT_EQ(checkBrackets(s), false);

}
TEST(TestBrackets, test_brackets_hard_true_1) {
	string s = "((()))";

	EXPECT_EQ(checkBrackets(s), true);

}

TEST(TestBrackets, test_brackets_hard_true_2) {
	string s = "([[{{}}]])";

	EXPECT_EQ(checkBrackets(s), true);

}

TEST(TestBrackets, test_brackets_hard_false_1) {
	string s = "([[{{}}]]]";

	EXPECT_EQ(checkBrackets(s), false);

}
