#pragma once

#include <memory>

template<typename T>
class single_linked_queue
{
private:
	struct node
	{
		T data;
		std::unique_ptr<node> next;
		node(T data_) : data(std::move(data_)) {}
	};

	std::unique_ptr<node> head;
	node* tail;

public:
	single_linked_queue() : tail(nullptr) {}

	single_linked_queue(const single_linked_queue& other) = delete;

	single_linked_queue& operator=(const single_linked_queue& other) = delete;

	std::shared_ptr<T> try_pop()
	{
		if (!head) {
			return std::shared_ptr<T>();
		}
		const std::shared_ptr<T> res(std::make_shared<T>(std::move(head->data)));
		const std::unique_ptr<node> old_head = std::move(head);
		head = std::move(old_head->next);
		if (!head) {
			tail = nullptr;
		}
		return res;
	}

	void push(T new_value)
	{
		std::unique_ptr<node> p(new node(std::move(new_value)));
		const node* new_tail = p.get();
		if (tail) {
			tail->next = std::move(p);
		}
		else {
			head = std::move(p);
		}
		tail = new_tail;
	}

};