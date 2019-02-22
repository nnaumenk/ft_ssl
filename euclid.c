void	gcdex2(int a, int b)
{
	size_t buf = b;
	size_t p;
	size_t q;
	size_t r;
	size_t s;
	size_t x;
	size_t y;
	
	p = 1;
	q = 0;
	r = 0;
	s = 1;
	while (a && b)
	{
		if (a>=b)
		{
			a = a - b;
			p = p + r;
			q = q + s;
		}
		else
		{
			b = b - a;
			r = r + p;
			s = s + q;
		}
	}
	if (a)
	{
		x = p;
		y = q;
	}
	else
	{
		x = r;
		y = s;
	}
	printf("%zu %zu\n", buf - x, y);
}