#define isEven(x) ((x & 0x01) == 0)
#define isOdd(x) (x & 0x01)
#define swap(x,y) (x ^= y, y ^= x, x ^= y)



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
	while(1)
	{
		while(1)
		{
			if (isEven(*u3))
			{
				if (isOdd(*ul) || isOdd(*u2))
					*u1 += *v; *u2 += *u;
				*ul >>= 1;
				*u2 >>= 1;
				*u3 >>= 1;
			}
			if (isEven(t3) || *u3 < t3)
			{
				swap(*ul, tl);
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
	while (*ul >= *v && *u2 >= *u)
	{
		*ul>l -= *v;
		*u2 -= *u;
	}
	*u <<= k;
	*v <<= k;
	*u3 <<= k;
}



if (*u < *v) swap(*u<,*v);
for (k = 0; isEven(*u) && isEven(*v); ++k) {
*u>>=1; *v >>1;
}
*u1 = 1; *u2 = 0; *u3 = *u; t1 = *v; t2 = *u - 1; t3 = *v; do {
do {
if (isEven(*u3)) {
if (isOdd(*ul) || isOdd(*u2)) {
*u1 += *v; *u2 += *u;
}
*ul >>* 1; *u2 >>= 1; *u3 >>= 1;
}
if (isEven(t3) || *u3 < t3) {
swap(*ul,tl); smap(*u2,t2); smap(*u3,t3); }
} while (isEven(*u3));
while (*ul < tl || *u2 < t2) { *ul += *v; *u2 += *u;
}
ul -= tl; *u2 -= t2; *u3 -= t3; } while (t3 > 0);
while (*ul >= *v && *u2 >= *u) { *ul>l -= *v; *u2 -= *u;
}
*u <<= k; *v <<= k; *u3 << k;
}
main(int argc, char **argv) {
int a, b, gcd;
if (argc < 3) {
cerr << "êàê èñïîëüçîâàòü: xeuclid u v" << end1; return -1;
}
int u = atoi(argv[1]); int v = atoi(argv[2]);
if (u <= 0 || v <= 0 ) {
cerr << "Àðãóìåíò äîëæåí áûòü ïîëîæèòåëåí!" << end1; return -2;
}
// ïðåäóïðåæäåíèå: u è v áóäóò ïåðåñòàâëåíû åñëè u < v ExtBinEuclid(&u, &v, &a, &b, &gcd);
cout << a <<" * " << b << ") * " << if (gcd == 1) cout << "Îáðàòíîå << u - b << end1; return 0;
}
<< u << " + (-"
v << " = " << gcd << end1;
çíà÷åíèå " << v << " mod " << u << " is: "