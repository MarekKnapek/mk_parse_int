# mk_parse_int
String to int (in C89).

Example usage:

```c
#include "parse_int.h"

#include <string.h> /* strlen */
#include <stdio.h> /* printf */


void example_int_a()
{
	char const* text;
	int err;
	char const* new_end;
	int value;

	text = "12345";
	parse_sint(text, text + strlen(text), &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an int: %d, consumed %d characters.\n", value, ((int)(new_end - text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - text)));
		}
		break;
	}
}

void example_int_b()
{
	char const* text;
	int err;
	char const* new_end;
	int value;

	text = "-12345abcd";
	parse_sint(text, text + strlen(text), &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an int: %d, consumed %d characters.\n", value, ((int)(new_end - text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - text)));
		}
		break;
	}
}

void example_int_c()
{
	char const* text;
	int err;
	char const* new_end;
	int value;

	text = "abcd12345";
	parse_sint(text, text + strlen(text), &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an int: %d, consumed %d characters.\n", value, ((int)(new_end - text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - text)));
		}
		break;
	}
}

void example_int_d()
{
	char const* text;
	int err;
	char const* new_end;
	int value;

	text = "3000000000";
	parse_sint(text, text + strlen(text), &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an int: %d, consumed %d characters.\n", value, ((int)(new_end - text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - text)));
		}
		break;
	}
}

void example_int_e()
{
	char const* text;
	int err;
	char const* new_end;
	unsigned long value;

	text = "3000000000";
	parse_ulong(text, text + strlen(text), &err, &new_end, &value);
	switch(err)
	{
		case 0:
		{
			printf("Succesfully parsed an unsigned long: %lu, consumed %d characters.\n", value, ((int)(new_end - text)));
		}
		break;
		case 1:
		{
			printf("Failed to parse number at %d.\n", ((int)(new_end - text)));
		}
		break;
		case 2:
		{
			printf("Overflow at %d.\n", ((int)(new_end - text)));
		}
		break;
	}
}

int main(void)
{
	example_int_a();
	example_int_b();
	example_int_c();
	example_int_d();
	example_int_e();
}
```

Output:

```
Succesfully parsed an int: 12345, consumed 5 characters.
Succesfully parsed an int: -12345, consumed 6 characters.
Failed to parse number at 0.
Overflow at 10.
Succesfully parsed an unsigned long: 3000000000, consumed 10 characters.
```
