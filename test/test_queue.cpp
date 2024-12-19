#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> queue);
}

TEST(Queue, is_empty) {
	Queue<int> queue;
	ASSERT_EQ(queue.is_empty(), 1);
}

TEST(Queue, is_not_empty) {
	Queue<int> queue(2);
	queue.push(5);
	ASSERT_EQ(queue.is_empty(), 0);
}

TEST(Queue, correct_get_size) {
	Queue<int> queue(2);
	queue.push(5);
	queue.push(10);
	queue.push(15);
	ASSERT_EQ(queue.get_size(), 3);
}

TEST(Queue, pop) {
	Queue<int> queue(2);
	queue.push(5);
	queue.push(10);
	queue.push(15);
	int num = queue.pop();
	ASSERT_EQ(num, 5);
	ASSERT_EQ(queue.get_size(), 2);
}

TEST(Queue, clear) {
	Queue<int> queue(2);
	queue.push(5);
	queue.push(10);
	queue.push(15);
	queue.clear();
	ASSERT_EQ(queue.is_empty(), 1);
	ASSERT_EQ(queue.get_size(), 0);
}