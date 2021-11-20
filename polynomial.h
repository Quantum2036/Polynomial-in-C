#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#define _POLYNOMIAL_IO_ON       1       // set boolean value to enables some model
#define _POLYNOMIAL_DEBUG_ON    1       //  1-ON        0-OFF

#include <math.h>
#include <stdlib.h>

#if _POLYNOMIAL_IO_ON
    #include <stdio.h>
#endif // IO model need this header file

#define MAX_POLYNOMIAL_RANK 100

typedef struct {
    int n;                              //Highest degree of polynomial
    double a[MAX_POLYNOMIAL_RANK+1];    //Coefficient array of polynomials
}Polynomial;

Polynomial  InitPoly        (void);

Polynomial  PolyProduct     (Polynomial po_1, Polynomial po_2);
Polynomial  PolyProduct_i   (Polynomial po_1, double num);
Polynomial  PolyAddition    (Polynomial po_1, Polynomial po_2);
Polynomial  PolyAddition_i  (Polynomial po_1, double num);
Polynomial  PolyPower_i     (Polynomial po_1, int num);

double      PolyValue       (Polynomial po_1, double x);

#if _POLYNOMIAL_IO_ON
Polynomial  InputPoly       (void);
void        DispPoly        (Polynomial po_1);
#endif // Enable IO functions

#if _POLYNOMIAL_DEBUG_ON
Polynomial  Debug_LoadPoly  (double* data);
void        Debug_Poly      (Polynomial po_1);
#endif // Enable debug functions

#endif // polynomial header
