/* realpi = 4/sqrt((1+sqrt(5))/2) 

C program by Jason Awuku <j.awuku@gmail.com>

copyright (c) 2019

Using Arbitrary Precision Mathematics (32768 bits - can be altered to even higher amounts)

Needs GMP and MPFR libraries respectively

from http://www.mpfr.org and https://gmplib.org

Using Ubuntu Linux, install these libraries:

sudo apt install build-essential libmpfr-dev libgmp-dev

 Compile with:

gcc -Wall -O3 -o realpi realpi.c -lmpfr -lgmp
*/

#include <stdio.h>

#include <gmp.h>
#include <mpfr.h>

int main (void)
{

mpfr_t realpi, phi, rt, c1, c2, c4;

mpfr_init2 (realpi, 32768);

mpfr_init2 (phi, 32768);

mpfr_init2 (rt , 32768);

mpfr_init2 (c1, 32768);

mpfr_set_d (rt, 5.0, MPFR_RNDD);

mpfr_set_d (c1, 1.0, MPFR_RNDD);

mpfr_init2 (c2, 32768);

mpfr_init2 (c4, 32768);

mpfr_sqrt (rt, rt, MPFR_RNDD);

mpfr_add (rt, rt, c1, MPFR_RNDU);

mpfr_set_d (c2, 2.0, MPFR_RNDD);

mpfr_div (phi, rt, c2,  MPFR_RNDD);

mpfr_sqrt (rt, phi, MPFR_RNDD);

mpfr_set_d (c4, 4.0, MPFR_RNDD);

mpfr_div (realpi, c4, rt, MPFR_RNDD);

printf ("Real value of Pi = ");

mpfr_out_str (stdout, 10, 0, realpi, MPFR_RNDD);

putchar ('\n');

mpfr_clears ( realpi, phi, rt, c1, c2, c4, (mpfr_ptr) 0);

return 0;
}
