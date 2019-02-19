#define isEven(x) ((x & 0x01) == 0)
#define isOdd(x) (x & 0x01)
#define swap(x,y) (x ^= y, y ^= x, x ^= y)

a = 3
b = 9167368

while (1)
{
	size_t	value;

	value = 0;
	if ((a - 1) == b)
		break ;
	if (a < b)
	{
		while (1)
		{
			a *= 2;
			value++;
			if (a > b)
				break ;
		}
	}
	else
	{
		while (1)
		{
			b *= 2;
			if (a > b)
				break ;
		}
	}
}












void ExtBinEuclid(int *u, int *v, int *u1, int *u2, int *u3)
{
	int k;
	int t1;
	int t2;
	int t3;

	if (*u < *v)
		swap(*u, *v);
	for (k = 0; isEven(*u) && isEven(*v); ++k)
	{
		*u >>= 1;
		*v >>= 1;
	}
	*u1 = 1;
	*u2 = 0;
	*u3 = *u;
	t1 = *v;
	t2 = *u - 1;
	t3 = *v;
	while (1)
	{
		while (1)
		{
			if (isEven(*u3))
			{
				if (isOdd(*u1) || isOdd(*u2))
					*u1 += *v; *u2 += *u;
				*u1 >>= 1;
				*u2 >>= 1;
				*u3 >>= 1;
			}
			if (isEven(t3) || *u3 < t3)
			{
				swap(*u1, t1);
				swap(*u2, t2);
				swap(*u3, t3);
			}
			if (isEven(*u3) == 0)
				break ;
		}
		while (*u1 < t1 || *u2 < t2)
		{
			*u1 += *v;
			*u2 += *u;
		}
		*u1 -= t1;
		*u2 -= t2;
		*u3 -= t3;
		if (t3 <= 0)
			break ;
	}
	while (*u1 >= *v && *u2 >= *u)
	{
		*u1 -= *v;
		*u2 -= *u;
	}
	*u <<= k;
	*v <<= k;
	*u3 <<= k;
}
