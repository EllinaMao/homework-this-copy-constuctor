#include "strmetods.h"

char* copy_str(const char* str)
{
	if (str == nullptr) {
		return nullptr;
	}
	size_t size = strlen(str) + 1;
	char* copy = new char[size];

	strcpy_s(copy, size, str);

	return copy;
}
