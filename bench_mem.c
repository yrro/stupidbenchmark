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
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
        struct rusage startusage, endusage;
        long double utime, stime, ttime;
        long double rate;
        int a, b;
	void *ptr[1024];

        getrusage(RUSAGE_SELF, &startusage);
        for (a = 0; a < 64; a++) {
               for (b = 0; b < 1024; b++) {
                        ptr[b] = malloc(1048576); 
                        memset(ptr[b], 0, 1048576 - 1);
                }
                for (b = 0; b < 1024; b++) {
                        free(ptr[b]);
                }
        }
        getrusage(RUSAGE_SELF, &endusage);

        utime =      (long double)endusage.ru_utime.tv_sec
                +   ((long double)endusage.ru_utime.tv_usec / 1000000)
                -  (long double)startusage.ru_utime.tv_sec
                + ((long double)startusage.ru_utime.tv_usec / 1000000);

        stime =      (long double)endusage.ru_stime.tv_sec
                +   ((long double)endusage.ru_stime.tv_usec / 1000000)
                -  (long double)startusage.ru_stime.tv_sec
                + ((long double)startusage.ru_stime.tv_usec / 1000000);
        ttime = utime + stime;

        rate =  65536 / (ttime * 1000);
        printf("%.2Lf megabytes per microsecond ", rate);
        printf("(%.2Lfs user, %.2Lfs sys, %.2Lfs total)\n",
        utime, stime, ttime);

        return 0;
}
