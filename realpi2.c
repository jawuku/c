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

//input bits (user interaction) - with error catching
long prec;
int input;
printf ("Enter bits of precision ");
input = scanf ("%ld", &prec);
putchar('\n');

//if user just presses non-numerical values -  avoids lock up
//scanf() is buggy
if (!input)
{
printf ("No value entered. Setting precision to 256 bits.\n");
prec = 256;
}

//if puts in a negative number or fraction
if (prec <= 0)
{
prec = 256;
printf ("Enter value greater than 0. Precision set to 256 bits instead.\n");
}

//declare precision of these floating point variables
mpfr_init2 (realpi, prec);

mpfr_init2 (phi, prec);

mpfr_init2 (rt, prec);

mpfr_init2 (c1, prec);

mpfr_init2 (c2, prec);

mpfr_init2 (c4, prec);

//assign constants c1=1, c2=2, c4=4, rt=5 to be inserted into calculations

mpfr_set_d (rt, 5.0, MPFR_RNDD);

mpfr_set_d (c1, 1.0, MPFR_RNDD);

mpfr_set_d (c2, 2.0, MPFR_RNDD);

mpfr_set_d (c4, 4.0, MPFR_RNDD);


//calculate realpi = 4/sqrt((1+sqrt(5))/2) step by step
// almost like a pseudo-assembly type language

//rt = sqrt(rt) to make sqrt(5)
mpfr_sqrt (rt, rt, MPFR_RNDN);

//rt = rt + 1 i.r 1+sqrt(5)
mpfr_add (rt, rt, c1, MPFR_RNDN);

//phi = rt / 2 ; i.e phi = (1+sqrt(5))/2
mpfr_div (phi, rt, c2, MPFR_RNDN);

//square root of phi
mpfr_sqrt (rt, phi, MPFR_RNDN);

//final pi calculation: realpi = 4 / sqare root of phi
mpfr_div (realpi, c4, rt, MPFR_RNDD);

//print result

printf ("Real value of Pi = ");

//format (output stream (screen in this case), base 10, default decimal places, realpi result, round down last digit)
mpfr_out_str (stdout, 10, 0, realpi, MPFR_RNDN);

putchar ('\n');

//clear all variables for a clean exit

mpfr_clears (realpi, phi, rt, c1, c2, c4, (mpfr_ptr) 0);

return 0;
}
