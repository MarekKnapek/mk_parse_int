#ifndef func_name
#define func_name parse_int
#endif
#ifndef int_type
#define int_type signed int
#endif
#ifndef is_wide
#define is_wide 0
#endif
#if is_wide == 0
#define char_t char
#elif is_wide == 1
#include <stddef.h>
#define char_t wchar_t
#endif
#ifdef __cplusplus
#define mk_extern_c extern "C"
#else
#define mk_extern_c
#endif


mk_extern_c void func_name(char_t const* const start, char_t const* const end, int* const err, char_t const** const nend, int_type* const value);


#undef func_name
#undef int_type
#undef is_wide
#undef char_t
#undef mk_extern_c
