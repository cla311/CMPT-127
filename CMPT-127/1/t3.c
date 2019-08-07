#include <stdio.h>
#include <math.h>

int main()
{
	float f = 0.0;
	scanf("%f", &f);
	printf("%d %d %d\n", (int)floor(f), (int)round(f),(int)ceil(f));
	return 0;
}
