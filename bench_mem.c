#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
        clock_t t1, t2;
        long double elapsed;
        long double rate;
        int a, b;
	void *ptr[1024];

        t1 = clock();
        for (a = 0; a < 64; a++) {
               for (b = 0; b < 1024; b++) {
                        ptr[b] = malloc(1048576); 
                        memset(ptr[b], 0, 1048576 - 1);
                }
                for (b = 0; b < 1024; b++) {
                        free(ptr[b]);
                }
        }
        t2 = clock();
        elapsed = ((long double)t2 - (long double)t1) / CLOCKS_PER_SEC;
        rate =  65536 / (elapsed * 1000);
        printf("%.6Lf megabytes per microsecond (%.1Lf seconds)\n", rate, elapsed);

        return 0;
}
