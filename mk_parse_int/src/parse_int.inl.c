#include <assert.h>
#include <limits.h>


#ifndef func_name
#define func_name parse_int
#endif
#ifndef is_signed
#define is_signed 1
#endif
#ifndef int_type
#define int_type signed int
#endif
#ifndef uint_type
#if is_signed == 1
#define uint_type unsigned int
#else
#define uint_type int_type
#endif
#endif
#ifndef sint_min
#define sint_min INT_MIN
#endif
#ifndef sint_max
#define sint_max INT_MAX
#endif
#ifndef uint_max
#define uint_max UINT_MAX
#endif
#ifndef is_wide
#define is_wide 0
#endif
#if is_wide == 0
#define char_t char
#define char_c(x) x
#elif is_wide == 1
#include <stddef.h>
#define char_t wchar_t
#define char_c(x) L ## x
#endif
#ifdef __cplusplus
#define mk_extern_c extern "C"
#else
#define mk_extern_c
#endif


#ifdef _MSC_VER
#pragma warning(push)
/* warning C4701: potentially uninitialized local variable 'overflow' used */
/* warning C4701: potentially uninitialized local variable 'val' used */
#pragma warning(disable:4701)
#endif


mk_extern_c void func_name(char_t const* const start, char_t const* const end, int* const err, char_t const** const nend, int_type* const value)
{
	#define bool_t int

	#define s_false ((bool_t)(0))
	#define s_true ((bool_t)(1))
	#define s_err_no ((int)(0))
	#define s_err_invalid ((int)(1))
	#define s_err_overflow ((int)(2))
	#if is_signed == 1
	#define s_minus ((char_t)(char_c('-')))
	#define s_border_pos_val ((uint_type)(((uint_type)(((int_type)(sint_max)))) / ((uint_type)(10))))
	#define s_border_pos_dig ((uint_type)(((uint_type)(((int_type)(sint_max)))) % ((uint_type)(10))))
	#define s_border_neg_val ((uint_type)(((uint_type)(((uint_type)(((int_type)(-((int_type)(((int_type)(sint_min)) + ((int_type)(16)))))))) + ((uint_type)(16)))) / ((uint_type)(10))))
	#define s_border_neg_dig ((uint_type)(((uint_type)(((uint_type)(((int_type)(-((int_type)(((int_type)(sint_min)) + ((int_type)(16)))))))) + ((uint_type)(16)))) % ((uint_type)(10))))
	#define s_neg_pos_diff ((uint_type)(((int_type)(((int_type)(-((int_type)(((int_type)(sint_min)) + ((int_type)(16)))))) - ((int_type)(((int_type)(sint_max)) - ((int_type)(16))))))))
	#else
	#define s_border_pos_val ((uint_type)(((uint_type)(uint_max)) / ((uint_type)(10))))
	#define s_border_pos_dig ((uint_type)(((uint_type)(uint_max)) % ((uint_type)(10))))
	#endif
	
	static char_t const s_digits[] =
	{
		char_c('0'),
		char_c('1'),
		char_c('2'),
		char_c('3'),
		char_c('4'),
		char_c('5'),
		char_c('6'),
		char_c('7'),
		char_c('8'),
		char_c('9')
	};

	char_t const* it;
	#if is_signed == 1
	bool_t negative;
	#endif
	bool_t overflow;
	uint_type val;
	char_t ch;
	int i;
	int_type ret;

	assert(start);
	assert(end);
	assert(end >= start);
	assert(err);
	assert(nend);
	assert(value);
	assert(sizeof(s_digits) / sizeof(*s_digits) == 10);
	#if is_signed == 1
	assert(((int_type)(-((int_type)(((int_type)(sint_min)) + ((int_type)(16)))))) >= ((int_type)(((int_type)(sint_max)) - ((int_type)(16)))));
	assert(((uint_type)(((uint_type)(uint_max)) - ((uint_type)(16)))) >= ((uint_type)(((int_type)(-((int_type)(((int_type)(sint_min)) + ((int_type)(16)))))))));
	#endif

	it = start;
	#if is_signed == 1
	negative = s_false;
	if(it != end)
	#endif
	{
		overflow = s_false;
		val = ((uint_type)(0));
		#if is_signed == 1
		if(*it == s_minus)
		{
			negative = s_true;
			++it;
		}
		#endif
		for(; it != end; ++it)
		{
			ch = *it;
			for(i = 0; i != 10; ++i)
			{
				if(ch == s_digits[i])
				{
					break;
				}
			}
			if(i == 10)
			{
				break;
			}
			if(!overflow)
			{
				if
				(
					#if is_signed == 1
					negative ?
					((val < s_border_neg_val) || (val == s_border_neg_val && i <= s_border_neg_dig)) :
					#endif
					((val < s_border_pos_val) || (val == s_border_pos_val && i <= s_border_pos_dig))
				)
				{
					val = ((uint_type)(((uint_type)(val * ((uint_type)(10)))) + ((uint_type)(i))));
				}
				else
				{
					overflow = s_true;
				}
			}
		}
	}
	if
	(
		(it - start) ==
		(
			#if is_signed == 1
			negative ?
			1 :
			#endif
			0
		)
	)
	{
		*err = s_err_invalid;
		*nend = start;
	}
	else if(overflow)
	{
		*err = s_err_overflow;
		*nend = it;
	}
	else
	{
		#if is_signed == 1
		if(negative)
		{
			ret = ((int_type)(((int_type)(-((int_type)(((uint_type)(val - s_neg_pos_diff)))))) - ((int_type)(s_neg_pos_diff))));
		}
		else
		#endif
		{
			ret = ((int_type)(val));
		}
		*err = s_err_no;
		*nend = it;
		*value = ret;
	}

	#undef bool_t
	#undef s_false
	#undef s_true
	#undef s_err_no
	#undef s_err_invalid
	#undef s_err_overflow
	#undef s_minus
	#undef s_border_pos_val
	#undef s_border_pos_dig
	#undef s_border_neg_val
	#undef s_border_neg_dig
	#undef s_neg_pos_diff
}


#ifdef _MSC_VER
#pragma warning(pop)
#endif


#undef func_name
#undef int_type
#undef uint_type
#undef sint_min
#undef sint_max
#undef uint_max
#undef is_signed
#undef is_wide
#undef char_t
#undef char_c
#undef mk_extern_c
