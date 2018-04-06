#ifndef _LINK_SAMPLE_MATH_H
#define _LINK_SAMPLE_MATH_H

/** Calculates the x^n **/
double power(double x, int n);

/** Calculates GCD of two given numbers **/
int gcd(int a, int b);

/** Checks whether a number is prime of not **/
int is_prime(unsigned int x);

/* 
Calculates future value of given ammouont after 'nperiods' years for
given rate of interest 
*/
double FV(double rate, unsigned int nperiods, double PV);

/*
Calculates present amount when future amount, time (in years) and
rate of interest is given.
*/
double PV(double rate, unsigned int nperiods, double FV);

/** prints all the factors of a given number **/
void factors(int x);

/** prints all the prime factors of a given positive integer **/
void primefactor(unsigned int x);

/** Checks whether a given number is Even or Odd **/
void evenOrOdd(int x);

/** returns lcm of 3 integers **/
int lcm(int a, int b, int c);

/** returns factorial of a givern positive integer **/
long int factorial(int n);

/** Calculates and returns nCr **/
long int nCr(int n, int r);

/**Calculates and returns nPr **/
long int nPr(int n, int r);

/** prints 'n' number of fibonacci series **/
void fibonacci(int n);

#endif
