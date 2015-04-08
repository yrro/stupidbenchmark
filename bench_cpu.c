#include <stdio.h>
#include <time.h>

int main(void) {
        clock_t t1, t2;
        long double elapsed;
        long double rate;
        int a, b;

        t1 = clock();
        for (a = 0; a < 100000; a++) {
                for (b = 0; b < 100000; b++) {
                        ;
                }
        }
        t2 = clock();
        elapsed = ((long double)t2 - (long double)t1) / CLOCKS_PER_SEC;
        rate = 10000000000 / (elapsed * 1000 * 1000);
        printf("%.3Lf loops per nanosecond (%.1Lf seconds)\n", rate, elapsed);

        return 0;
}
