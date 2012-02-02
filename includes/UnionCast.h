#pragma once

template <typename TO, typename FROM>
union union_cast
{
public:
	typedef TO to_type;
	typedef FROM from_type;
	typedef union_cast<TO, FROM> class_type;

public:
	union_cast(from_type const from): from(from) {}

	operator to_type() const
	{
		return to;
	}
private:
	from_type from;
	to_type to;
};
