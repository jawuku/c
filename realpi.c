/* realpi = 4/sqrt((1+sqrt(5))/2)

C Program by Jason Awuku 2018 <j.awuku@gmail.com>

To calculate Pi using Arbitrary Precision Mathematics (16384 bits - can be altered to even higher amounts)

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

// declare variable types for use with mpfr
mpfr_t realpi, phi, rt, c1, c2, c4;


//declare precision of these floating point variables (16384 bits)
mpfr_init2 (realpi, 16384);

mpfr_init2 (phi, 16384);

mpfr_init2 (rt, 16384);

mpfr_init2 (c1, 16384);

mpfr_init2 (c2, 16384);

mpfr_init2 (c4, 16384);

//assign constants c1=1, c2=2, c4=4, rt=5 to be inserted into calculations

mpfr_set_d (rt, 5.0, MPFR_RNDD);

mpfr_set_d (c1, 1.0, MPFR_RNDD);

mpfr_set_d (c2, 2.0, MPFR_RNDD);

mpfr_set_d (c4, 4.0, MPFR_RNDD);


//calculate realpi = 4/sqrt((1+sqrt(5))/2) step by step
// almost like a pseudo-assembly type language

//rt = sqrt(rt) to make sqrt(5)
mpfr_sqrt (rt, rt, MPFR_RNDD);

//rt = rt + 1 i.r 1+sqrt(5)
mpfr_add (rt, rt, c1, MPFR_RNDU);

//phi = rt / 2 ; i.e phi = (1+sqrt(5))/2
mpfr_div (phi, rt, c2, MPFR_RNDD);

//square root of phi
mpfr_sqrt (rt, phi, MPFR_RNDD);

//final pi calculation: realpi = 4 / sqare root of phi
mpfr_div (realpi, c4, rt, MPFR_RNDD);

//print result

printf ("Real value of Pi = ");

//format (output stream (screen in this case), base 10, default decimal places, realpi result, round down last digit)
mpfr_out_str (stdout, 10, 0, realpi, MPFR_RNDD);

putchar ('\n');

//clear all variables for a clean exit

mpfr_clears (realpi, phi, rt, c1, c2, c4, (mpfr_ptr) 0);

return 0;
}
