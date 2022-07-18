#pragma once

#include <iostream>

template <typename T>
struct list_node
{
	list_node<T>* prev{ nullptr };
	list_node<T>* next{ nullptr };
	T value{};

	list_node() { std::cout << "[CL] Node create\n"; }
	~list_node() { std::cout << "[CL] Node destroy\n"; }
};

template <typename T>
class custom_list
{
public:

	custom_list() = default;
	~custom_list();

	void insert(T&& value);

private:
	list_node<T>* head{ nullptr };
};

template<typename T>
inline custom_list<T>::~custom_list()
{

}

template<typename T>
inline void custom_list<T>::insert(T&& value)
{
	list_node<T> *node = new list_node<T>{};
	node->prev = head;
	node->value = value;

	if (head != nullptr) {
		head->next = node;
	}

	head = node;
}
