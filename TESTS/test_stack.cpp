#include <gtest.h>
#include "../LIBS/lib_stack/customStack.h"

TEST(Stack, can_push) {
	CustomStack<int> stack;
	stack.push(1);

	EXPECT_EQ(1, stack.top());
}

TEST(Stack, can_push_data) {
	CustomStack<int> stack;
	for (int i = 0; i < 200; i++) {
		stack.push(i);
	}
	stack.push(1);

	EXPECT_EQ(1, stack.top());
}

TEST(Stack, can_pop) {
	CustomStack<int> stack;
	stack.push(10);

	EXPECT_EQ(10, stack.pop());
}

TEST(Stack, get_top) {
	CustomStack<int> stack;
	stack.push(20);
	EXPECT_EQ(20, stack.top());
}

TEST(Stack, get_is_empty) {
	CustomStack<int> stack;

	EXPECT_EQ(true, stack.isEmpty());
}
