#include "stdafx.h"
#include "MyHelperLib.h"

void MyHelperLib::floatToString(char * p_buffer, float p_float)
{
	int ret = snprintf(p_buffer, sizeof p_buffer, "%f", p_float); //snprintf is a better option than sprintf as it guarantees it will never write past the size of the buffer you supply in argument 2.
	if (ret < 0) {
		// TODO throw exception
	}
	if (ret >= sizeof p_buffer) {
		// Result was truncated - resize the buffer and retry.
	}
}

bool MyHelperLib::approx(float a, float b, float ish)
{

	if (a <= b + ish && a >= b - ish)
	{
		return true;
	}
	else
	{
		return false;
	}
}
