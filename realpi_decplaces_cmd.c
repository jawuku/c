/* realpi = 4/sqrt((1+sqrt(5))/2)

C Program by Jason Awuku

Copyright (c) Jason Awuku 2019, 2021

To calculate Pi using Arbitrary Precision Mathematics (16384 bits - can be altered to even higher amounts)

Needs GMP and MPFR libraries respectively

from http://www.mpfr.org and https://gmplib.org

Using Debian or Ubuntu Linux, install these libraries:

sudo apt install build-essential libmpfr-dev libgmp-dev

Compile with:

gcc -Wall -O3 -o realpi_decplaces_cmd realpi_decplaces_cmd.c -lmpfr -lgmp

This version takes command line input
Usage: ./realpi_decplaces_cmd <decimal places>
If no argument supplied, defaults to 50 decimal places */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

int main(int argc, char *argv[])
{
    long prec = 512; //bits of precision
    int dec_places;
// checks 1st command line argument - converts string to integer
    if (argc > 1)
    {
        dec_places = atoi (argv[1]);
    }

    else
    {
        puts("No argument entered. Usage: realpi_cmd <decimal places>");
        puts("Setting to 50 decimal places.");
        dec_places = 50;
    }

// if user just presses non-numerical values
    if (!dec_places)
    {
        puts("No numerical value entered. Usage: realpi_cmd <decimal places>");
        puts("Setting to 50 decimal places.");
        dec_places = 50;
    }

// if puts in a negative number or fraction
    if (dec_places < 1)
    {
        puts("Enter value 1 or higher. Usage: realpi_cmd <decimal places>");
        puts("Setting to 50 decimal places.");
        dec_places = 50;
    }

// declare variable types for use with mpfr
    mpfr_t realpi, phi, rt, c1, c2, c4;

// declare precision of these floating point variables (16384 bits)
    mpfr_init2(realpi, prec);

    mpfr_init2(phi, prec);

    mpfr_init2(rt, prec);

    mpfr_init2(c1, prec);

    mpfr_init2(c2, prec);

    mpfr_init2(c4, prec);

// assign constants c1=1, c2=2, c4=4, rt=5 to be inserted into calculations

    mpfr_set_d(rt, 5.0, MPFR_RNDN);

    mpfr_set_d(c1, 1.0, MPFR_RNDN);

    mpfr_set_d(c2, 2.0, MPFR_RNDN);

    mpfr_set_d(c4, 4.0, MPFR_RNDN);


// calculate realpi = 4/sqrt((1+sqrt(5))/2) step by step

// rt = sqrt(rt) to make sqrt(5)
    mpfr_sqrt(rt, rt, MPFR_RNDN);

// rt = rt + 1, i.e 1+sqrt(5)
    mpfr_add(rt, rt, c1, MPFR_RNDN);

// phi = rt / 2 ; i.e phi = (1+sqrt(5))/2
    mpfr_div(phi, rt, c2, MPFR_RNDN);

// square root of phi
    mpfr_sqrt(rt, phi, MPFR_RNDN);

// final pi calculation: realpi = 4 / square root of phi
    mpfr_div(realpi, c4, rt, MPFR_RNDN);

// print result

    printf("Real value of Pi = ");

// format (output stream (screen in this case), base 10, 
// specified decimal places, realpi result, round to nearest digit)
    mpfr_out_str(stdout, 10, dec_places, realpi, MPFR_RNDN);

    putchar('\n');

//clear all variables for a clean exit

    mpfr_clears(realpi, phi, rt, c1, c2, c4, (mpfr_ptr) 0);

    return 0;
}
