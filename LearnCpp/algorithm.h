#pragma once

#include <iostream>

namespace course
{

	template<typename iter>
	void print(iter begin, iter end)
	{
		for (iter i = begin; i != end; ++i) {
			std::cout << *i << '\n';
		}
	}

	template<typename iter>
	auto max(iter begin, iter end)
	{
		auto value = *begin;
		for (iter i = begin; i != end; ++i) {
			if (*i > value) {
				value = *i;
			}
		}
		return value;
	}
	 
	template<typename iter>
	auto min(iter begin, iter end)
	{
		auto value = *begin;
		for (iter i = begin; i != end; ++i) {
			if (*i < value) {
				value = *i;
			}
		}
		return value;
	}

	template<typename iter>
	auto sum(iter begin, iter end)
	{
		auto value = *begin;
		for (iter i = begin + 1; i != end; ++i) {
			value += *i;
		}
		return value;
	}

	template<typename iter>
	void reverse(iter begin, iter end)
	{
		for (iter i = begin, j = end - 1; i < j; ++i, --j) 
		{
			auto temp = *j;
			*j = *i;
			*i = temp;
		}
	}

	template<typename iter>
	bool is_sorted(iter begin, iter end)
	{
		for (iter i = begin; i != (end - 1); ++i) {
			if (*i > *(i + 1)) {
				return false;
			}
		}
		return true;
	}

	template<typename T>
	void swap(T& first, T& second)
	{
		T tmp = first;
		first = second;
		second = tmp;
	}

	template<typename iter, typename T>
	iter find(iter begin, iter end, T value)
	{
		for (iter i = begin; i != end; ++i) {
			if (*i == value) {
				return i;
			}
		}
		return end;
	}

	template<typename iter, typename T>
	iter find_with_transposition(iter begin, iter end, T value)
	{
		for (iter i = begin; i != end; ++i) {
			if (*i == value) {
				if (i != begin) {
					swap<T>(*i, *(i - 1));
				}
				return i;
			}
		}
		return end;
	}

	template<typename iter, typename T>
	iter binary_search_iterative(iter begin, iter end, T value)
	{
		iter low = begin;
		iter high = end;
		iter mid = low + (high - low) / 2;
		while (mid != high)
		{
			if (value > *mid) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
			
			mid = low + (high - low) / 2;
		}
		 
		if (value == *mid) {
			return mid;
		} 

		return end;
	}

	template<typename iter>
	auto find_missing_element(iter begin, iter end)
	{
		auto total = sum(begin, end);
		auto n = end - begin;
		auto s = (n * (n - 1)) / 2;
		return s - total;
	}


}