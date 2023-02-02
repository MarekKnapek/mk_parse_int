# mk_parse_int
String to int (in C89).

Supports signed and unsigned char, short, int, long and long long integers, narrow and wide strings.

Example usage:

```c
#include "parse_int.h"

#include <stdio.h> /* printf */


int main(void)
{
	/* String to int. */

	static char const s_text[] = "12345";

	int text_len;
	int err;
	char const* new_end;
	int value;

	text_len = sizeof(s_text) / sizeof(*s_text);
	parse_sint(s_text, s_text + text_len, &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an int: %d, consumed %d characters.\n", value, ((int)(new_end - s_text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - s_text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - s_text)));
		}
		break;
	}
}
```
```
Succesfully parsed an int: 12345, consumed 5 characters.
```
```c
#include "parse_int.h"

#include <stdio.h> /* printf */


int main(void)
{
	/* String to int (negative). */

	static char const s_text[] = "-12345abcd";

	int text_len;
	int err;
	char const* new_end;
	int value;

	text_len = sizeof(s_text) / sizeof(*s_text);
	parse_sint(s_text, s_text + text_len, &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an int: %d, consumed %d characters.\n", value, ((int)(new_end - s_text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - s_text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - s_text)));
		}
		break;
	}
}
```
```
Succesfully parsed an int: -12345, consumed 6 characters.
```
```c
#include "parse_int.h"

#include <stdio.h> /* printf */


int main(void)
{
	/* String to int (invalid). */

	static char const s_text[] = "abcd12345";

	int text_len;
	int err;
	char const* new_end;
	int value;

	text_len = sizeof(s_text) / sizeof(*s_text);
	parse_sint(s_text, s_text + text_len, &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an int: %d, consumed %d characters.\n", value, ((int)(new_end - s_text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - s_text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - s_text)));
		}
		break;
	}
}
```
```
Failed to parse number at 0.
```
```c
#include "parse_int.h"

#include <stdio.h> /* printf */


int main(void)
{
	/* String to int (overflow). */

	static char const s_text[] = "3000000000";

	int text_len;
	int err;
	char const* new_end;
	int value;

	text_len = sizeof(s_text) / sizeof(*s_text);
	parse_sint(s_text, s_text + text_len, &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an int: %d, consumed %d characters.\n", value, ((int)(new_end - s_text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - s_text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - s_text)));
		}
		break;
	}
}
```
```
Overflow at 10.
```
```c
#include "parse_int.h"

#include <stdio.h> /* printf */


int main(void)
{
	/* String to unsigned long. */

	static char const s_text[] = "3000000000";

	int text_len;
	int err;
	char const* new_end;
	unsigned long value;

	text_len = sizeof(s_text) / sizeof(*s_text);
	parse_ulong(s_text, s_text + text_len, &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an unsigned long: %lu, consumed %d characters.\n", value, ((int)(new_end - s_text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - s_text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - s_text)));
		}
		break;
	}
}
```
```
Succesfully parsed an unsigned long: 3000000000, consumed 10 characters.
```
```c
#include "parse_int.h"

#include <stddef.h> /* wchar_t */
#include <stdio.h> /* printf */


int main(void)
{
	/* String to unsigned long (wide). */

	static wchar_t const s_text[] = L"3000000000";

	int text_len;
	int err;
	wchar_t const* new_end;
	unsigned long value;

	text_len = sizeof(s_text) / sizeof(*s_text);
	parse_ulongw(s_text, s_text + text_len, &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an unsigned long: %lu, consumed %d characters.\n", value, ((int)(new_end - s_text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - s_text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - s_text)));
		}
		break;
	}
}
```
```
Succesfully parsed an unsigned long: 3000000000, consumed 10 characters.
```
