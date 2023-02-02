#include <cassert>
#include <charconv>
#include <climits>
#include <cstddef>

#include "parse_int.h"


namespace detail
{
	template<typename, typename> struct dispatcher;
	template<> struct dispatcher<char, signed char> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed char* const value) { return parse_schar(start, end, err, nend, value); } };
	template<> struct dispatcher<char, signed short int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed short int* const value) { return parse_sshort(start, end, err, nend, value); } };
	template<> struct dispatcher<char, signed int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed int* const value) { return parse_sint(start, end, err, nend, value); } };
	template<> struct dispatcher<char, signed long int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed long int* const value) { return parse_slong(start, end, err, nend, value); } };
	template<> struct dispatcher<char, signed long long int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, signed long long int* const value) { return parse_sllong(start, end, err, nend, value); } };
	template<> struct dispatcher<char, unsigned char> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned char* const value) { return parse_uchar(start, end, err, nend, value); } };
	template<> struct dispatcher<char, unsigned short int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned short int* const value) { return parse_ushort(start, end, err, nend, value); } };
	template<> struct dispatcher<char, unsigned int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned int* const value) { return parse_uint(start, end, err, nend, value); } };
	template<> struct dispatcher<char, unsigned long int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned long int* const value) { return parse_ulong(start, end, err, nend, value); } };
	template<> struct dispatcher<char, unsigned long long int> { static void dispatch(char const* const start, char const* const end, int* const err, char const** const nend, unsigned long long int* const value) { return parse_ullong(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, signed char> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, signed char* const value) { return parse_scharw(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, signed short int> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, signed short int* const value) { return parse_sshortw(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, signed int> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, signed int* const value) { return parse_sintw(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, signed long int> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, signed long int* const value) { return parse_slongw(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, signed long long int> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, signed long long int* const value) { return parse_sllongw(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, unsigned char> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, unsigned char* const value) { return parse_ucharw(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, unsigned short int> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, unsigned short int* const value) { return parse_ushortw(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, unsigned int> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, unsigned int* const value) { return parse_uintw(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, unsigned long int> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, unsigned long int* const value) { return parse_ulongw(start, end, err, nend, value); } };
	template<> struct dispatcher<wchar_t, unsigned long long int> { static void dispatch(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, unsigned long long int* const value) { return parse_ullongw(start, end, err, nend, value); } };
}

template<typename char_type, typename int_type>
void parse_int_1(char_type const* const start, char_type const* const end, int* const err, char_type const** const nend, int_type* const value)
{
	assert(start);
	assert(end);
	assert(end >= start);
	assert(err);
	assert(nend);
	assert(value);

	detail::dispatcher<char_type, int_type>::dispatch(start, end, err, nend, value);
}

template<typename int_type>
void parse_int_2(char const* const start, char const* const end, int* const err, char const** const nend, int_type* const value)
{
	assert(start);
	assert(end);
	assert(end >= start);
	assert(err);
	assert(nend);
	assert(value);

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
	else
	{
		assert(false);
	}
}

template<typename int_type>
void parse_int_2(wchar_t const* const start, wchar_t const* const end, int* const err, wchar_t const** const nend, int_type* const value)
{
	static constexpr int const s_max_buff = 64;

	int i;
	char buff[s_max_buff];
	char const* start_n;
	char const* end_n;
	char const* nend_n;

	assert(start);
	assert(end);
	assert(end >= start);
	assert(err);
	assert(nend);
	assert(value);

	assert(end - start <= s_max_buff);

	for(i = 0; i != end - start; ++i)
	{
		if(start[i] < CHAR_MIN || start[i] > CHAR_MAX)
		{
			buff[i] = '\0';
		}
		else
		{
			buff[i] = ((char)(start[i]));
		}
	}
	start_n = buff;
	end_n = buff + (end - start);
	parse_int_2(start_n, end_n, err, &nend_n, value);
	*nend = start + (nend_n - start_n);
}

template<typename char_type, typename int_type>
void parse_int_test(unsigned char const* data, size_t size)
{
	#define test(x) do{if(!(x)){int volatile*volatile ptr;ptr=NULL;*ptr=0;}}while(0);

	char_type const* input;
	int err1;
	int err2;
	char_type const* nend1;
	char_type const* nend2;
	int_type value1;
	int_type value2;

	input = ((char_type const*)(data));
	err1 = 42;
	err2 = 42;
	nend1 = ((char_type const*)(0x16));
	nend2 = ((char_type const*)(0x16));
	value1 = 24;
	value2 = 24;
	parse_int_1(input, input + size / sizeof(char_type), &err1, &nend1, &value1);
	parse_int_2(input, input + size / sizeof(char_type), &err2, &nend2, &value2);
	test(err1 == err2);
	test(nend1 == nend2);
	test(value1 == value2);

	#undef test
}


extern "C" int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size)
{
	parse_int_test<char, signed char>(data, size);
	parse_int_test<char, signed short int>(data, size);
	parse_int_test<char, signed int>(data, size);
	parse_int_test<char, signed long int>(data, size);
	parse_int_test<char, signed long long int>(data, size);
	parse_int_test<char, unsigned char>(data, size);
	parse_int_test<char, unsigned short int>(data, size);
	parse_int_test<char, unsigned int>(data, size);
	parse_int_test<char, unsigned long int>(data, size);
	parse_int_test<char, unsigned long long int>(data, size);
	parse_int_test<wchar_t, signed char>(data, size);
	parse_int_test<wchar_t, signed short int>(data, size);
	parse_int_test<wchar_t, signed int>(data, size);
	parse_int_test<wchar_t, signed long int>(data, size);
	parse_int_test<wchar_t, signed long long int>(data, size);
	parse_int_test<wchar_t, unsigned char>(data, size);
	parse_int_test<wchar_t, unsigned short int>(data, size);
	parse_int_test<wchar_t, unsigned int>(data, size);
	parse_int_test<wchar_t, unsigned long int>(data, size);
	parse_int_test<wchar_t, unsigned long long int>(data, size);
	return 0;
}
