
#include <iostream>

#define ENUM_MY_EXAMPLE_VALUES \
	_CALL(ExampleA) \
	_CALL(ExampleB) \
	_CALL(ExampleC) \
	_CALL(ExampleD) \
	_CALL(ExampleE)

struct EMyExample
{
	#define _CALL(_VALUE) _VALUE,
	enum Enum {
		Invalid = -1,
		ENUM_MY_EXAMPLE_VALUES
		Count
	};
	#undef _CALL

	static const char* AsStr(Enum _eEnum)
	{
	#define _CALL(_VALUE) \
	if (_eEnum == _VALUE) \
	{ \
		return #_VALUE; \
	}
	ENUM_MY_EXAMPLE_VALUES
	#undef _CALL
			if (_eEnum == Count)
			{
				return "Count";
			}
		return "Invalid";
	}

	static Enum AsEnum(const char* _sValue)
	{
	#define _CALL(_VALUE) \
	if (strcmp(_sValue, #_VALUE) == 0) \
	{ \
		return _VALUE; \
	}
		ENUM_MY_EXAMPLE_VALUES
	#undef _CALL

	else if (strcmp(_sValue, "Count") == 0)
	{
		return Count;
	}
	return Invalid;
	}
};

int main()
{
	for (unsigned int uIndex = 0; uIndex < EMyExample::Count; ++uIndex)
	{
		printf("%d. %s\n", uIndex, EMyExample::AsStr(static_cast<EMyExample::Enum>(uIndex)));
	}

	printf("Ejemplo %s\n", EMyExample::AsStr(EMyExample::AsEnum("ExampleA")));
	printf("Ejemplo %s\n", EMyExample::AsStr(EMyExample::AsEnum("ExampleB")));
	printf("Ejemplo %s\n", EMyExample::AsStr(EMyExample::AsEnum("ExampleC")));
	printf("Ejemplo %s\n", EMyExample::AsStr(EMyExample::AsEnum("ExampleD")));
}