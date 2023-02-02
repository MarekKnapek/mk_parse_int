#include "parse_int.h"

#include <limits.h>


#define func_name parse_schar
#define int_type signed char
#define uint_type unsigned char
#define sint_min SCHAR_MIN
#define sint_max SCHAR_MAX
#define uint_max UCHAR_MAX
#define is_signed 1
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_sshort
#define int_type signed short int
#define uint_type unsigned short int
#define sint_min SHRT_MIN
#define sint_max SHRT_MAX
#define uint_max USHRT_MAX
#define is_signed 1
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_sint
#define int_type signed int
#define uint_type unsigned int
#define sint_min INT_MIN
#define sint_max INT_MAX
#define uint_max UINT_MAX
#define is_signed 1
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_slong
#define int_type signed long int
#define uint_type unsigned long int
#define sint_min LONG_MIN
#define sint_max LONG_MAX
#define uint_max ULONG_MAX
#define is_signed 1
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_sllong
#define int_type signed long long int
#define uint_type unsigned long long int
#define sint_min LLONG_MIN
#define sint_max LLONG_MAX
#define uint_max ULLONG_MAX
#define is_signed 1
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_uchar
#define int_type unsigned char
#define uint_max UCHAR_MAX
#define is_signed 0
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_ushort
#define int_type unsigned short int
#define uint_max USHRT_MAX
#define is_signed 0
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_uint
#define int_type unsigned int
#define uint_max UINT_MAX
#define is_signed 0
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_ulong
#define int_type unsigned long int
#define uint_max ULONG_MAX
#define is_signed 0
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_ullong
#define int_type unsigned long long int
#define uint_max ULLONG_MAX
#define is_signed 0
#define is_wide 0
#include "parse_int.inl.c"

#define func_name parse_scharw
#define int_type signed char
#define uint_type unsigned char
#define sint_min SCHAR_MIN
#define sint_max SCHAR_MAX
#define uint_max UCHAR_MAX
#define is_signed 1
#define is_wide 1
#include "parse_int.inl.c"

#define func_name parse_sshortw
#define int_type signed short int
#define uint_type unsigned short int
#define sint_min SHRT_MIN
#define sint_max SHRT_MAX
#define uint_max USHRT_MAX
#define is_signed 1
#define is_wide 1
#include "parse_int.inl.c"

#define func_name parse_sintw
#define int_type signed int
#define uint_type unsigned int
#define sint_min INT_MIN
#define sint_max INT_MAX
#define uint_max UINT_MAX
#define is_signed 1
#define is_wide 1
#include "parse_int.inl.c"

#define func_name parse_slongw
#define int_type signed long int
#define uint_type unsigned long int
#define sint_min LONG_MIN
#define sint_max LONG_MAX
#define uint_max ULONG_MAX
#define is_signed 1
#define is_wide 1
#include "parse_int.inl.c"

#define func_name parse_sllongw
#define int_type signed long long int
#define uint_type unsigned long long int
#define sint_min LLONG_MIN
#define sint_max LLONG_MAX
#define uint_max ULLONG_MAX
#define is_signed 1
#define is_wide 1
#include "parse_int.inl.c"

#define func_name parse_ucharw
#define int_type unsigned char
#define uint_max UCHAR_MAX
#define is_signed 0
#define is_wide 1
#include "parse_int.inl.c"

#define func_name parse_ushortw
#define int_type unsigned short int
#define uint_max USHRT_MAX
#define is_signed 0
#define is_wide 1
#include "parse_int.inl.c"

#define func_name parse_uintw
#define int_type unsigned int
#define uint_max UINT_MAX
#define is_signed 0
#define is_wide 1
#include "parse_int.inl.c"

#define func_name parse_ulongw
#define int_type unsigned long int
#define uint_max ULONG_MAX
#define is_signed 0
#define is_wide 1
#include "parse_int.inl.c"

#define func_name parse_ullongw
#define int_type unsigned long long int
#define uint_max ULLONG_MAX
#define is_signed 0
#define is_wide 1
#include "parse_int.inl.c"
