#pragma once

namespace idiom
{

	class nonaddressable
	{
	public:
		typedef double useless_type;
	private:
		useless_type operator&() const;
	};

	template <typename T>
	T* address_of(T& v)
	{
		return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char&>(v)));
	}

}
