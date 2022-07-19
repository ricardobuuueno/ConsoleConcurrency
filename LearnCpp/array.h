#pragma once

#include <memory>

namespace course
{

	template<typename T, size_t sz>
	class Array
	{
		std::unique_ptr<T[]> a_{ std::make_unique<T[]>(sz) };

	public:

		T& operator[](size_t i) { return a_[i]; }

		T* begin() { return &a_[0]; }
		T* end() { return &a_[sz]; }

		size_t size() { return sz; }
		bool empty() { return sz == 0; }
		
		T& at(size_t i) 
		{ 
			if (i >= sz) {
				throw std::out_of_range("out of range");
			}
			return a_[0];
		}

	};

}