
#include <stdio.h>

int main(void)
{
	size_t num1 = 0x795a38d4279d1754;
	size_t num2 = 0x86ffad2c;
	printf("%zu\n", num1 / num2);
	printf("%zu\n", num1 % num2);
}