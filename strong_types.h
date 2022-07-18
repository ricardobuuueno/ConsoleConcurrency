#pragma once

template <typename UnderlyingType, typename PhantomTag, typename Ratio>
class StrongTypeImpl
{
public:
	explicit StrongTypeImpl(UnderlyingType const& value) : value_(value) {}
	UnderlyingType get() { return value_; }

	template <typename OtherRatio>
	operator StrongTypeImpl<UnderlyingType, PhantomTag, OtherRatio>() const
	{
		return StrongTypeImpl<UnderlyingType, PhantomTag, OtherRatio>(
			get() *
			Ratio::num / Ratio::den *
			OtherRatio::den / OtherRatio::num
		);
	}

private:
	UnderlyingType value_;

};

template <typename UnderlyingType, typename PhantomTag>
using StrongType = StrongTypeImpl<UnderlyingType, PhantomTag, std::ratio<1>>;

template <typename UnderlyingType, typename Ratio>
using MultipleOf = StrongTypeImpl<UnderlyingType, struct MassTag, Ratio>;

using Gram = StrongType<double, struct MassTag>;

using Kilogram = MultipleOf<Gram, std::kilo>;
using Pound = MultipleOf<Kilogram, std::ratio<56699, 125000>>;

