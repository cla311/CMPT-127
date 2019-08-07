#include <stdio.h>
#include <math.h>

int main()
{
	float f = 0.0;
	int n;
	
	n = scanf("%f", &f);
	if (n == 1) {
		printf("%d %d %d\n", (int)floor(f), (int)round(f),(int)ceil(f));
	} else {
		printf("scanf error: (%d)\n", n);
	}
	return 0;
}
