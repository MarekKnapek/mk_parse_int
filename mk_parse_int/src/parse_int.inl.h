#ifndef func_name
#define func_name parse_int
#endif
#ifndef int_type
#define int_type signed int
#endif
#ifdef __cplusplus
#define mk_extern_c extern "C"
#else
#define mk_extern_c
#endif


mk_extern_c void func_name(char const* const start, char const* const end, int* const err, char const** const nend, int_type* const value);


#undef func_name
#undef int_type
#undef mk_extern_c
