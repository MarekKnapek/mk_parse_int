#include <cassert>
#include <charconv>
#include <cstddef>

#include "parse_int.h"


namespace detail
{
	template<typename> struct dispatcher;
	template<> struct dispatcher<signed char> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed char* const value) { return parse_schar(start, end, err, nend, value); } };
	template<> struct dispatcher<signed short int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed short int* const value) { return parse_sshort(start, end, err, nend, value); } };
	template<> struct dispatcher<signed int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed int* const value) { return parse_sint(start, end, err, nend, value); } };
	template<> struct dispatcher<signed long int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed long int* const value) { return parse_slong(start, end, err, nend, value); } };
	template<> struct dispatcher<signed long long int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed long long int* const value) { return parse_sllong(start, end, err, nend, value); } };
	template<> struct dispatcher<unsigned char> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned char* const value) { return parse_uchar(start, end, err, nend, value); } };
	template<> struct dispatcher<unsigned short int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned short int* const value) { return parse_ushort(start, end, err, nend, value); } };
	template<> struct dispatcher<unsigned int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned int* const value) { return parse_uint(start, end, err, nend, value); } };
	template<> struct dispatcher<unsigned long int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned long int* const value) { return parse_ulong(start, end, err, nend, value); } };
	template<> struct dispatcher<unsigned long long int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned long long int* const value) { return parse_ullong(start, end, err, nend, value); } };
}

template<typename int_type>
void parse_int_1(char const* const start, char const* const end, int* const err, char const** const nend, int_type* const value)
{
	detail::dispatcher<int_type>::dispatch(start, end, err, nend, value);
}

template<typename int_type>
void parse_int_2(char const* const start, char const* const end, int* const err, char const** const nend, int_type* const value)
{
	std::from_chars_result r = std::from_chars(start, end, *value, 10);
	if(r.ec == std::errc{})
	{
		*err = 0;
		*nend = r.ptr;
	}
	else if(r.ec == std::errc::invalid_argument)
	{
		*err = 1;
		*nend = r.ptr;
	}
	else if(r.ec == std::errc::result_out_of_range)
	{
		*err = 2;
		*nend = r.ptr;
	}
}

template<typename int_type>
void parse_int_test(unsigned char const* data, size_t size)
{
	#define check(x) do{if(!(x)){int volatile*volatile ptr;ptr=NULL;*ptr=0;}}while(0);

	char const* input;
	int err1;
	int err2;
	char const* nend1;
	char const* nend2;
	int_type value1;
	int_type value2;

	input = ((char const*)(data));
	err1 = 42;
	err2 = 42;
	nend1 = ((char const*)(0x16));
	nend2 = ((char const*)(0x16));
	value1 = 24;
	value2 = 24;
	parse_int_1(input, input + size, &err1, &nend1, &value1);
	parse_int_2(input, input + size, &err2, &nend2, &value2);
	check(err1 == err2);
	check(nend1 == nend2);
	check(value1 == value2);

	#undef check
}


extern "C" int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size)
{
	parse_int_test<signed char>(data, size);
	parse_int_test<signed short int>(data, size);
	parse_int_test<signed int>(data, size);
	parse_int_test<signed long int>(data, size);
	parse_int_test<signed long long int>(data, size);
	parse_int_test<unsigned char>(data, size);
	parse_int_test<unsigned short int>(data, size);
	parse_int_test<unsigned int>(data, size);
	parse_int_test<unsigned long int>(data, size);
	parse_int_test<unsigned long long int>(data, size);
	return 0;
}
