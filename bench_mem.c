/* stupidbenchmark - bench_mem.c
 *
 * Copyright 2015 by Thomas Stewart <thomas@stewarts.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

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
