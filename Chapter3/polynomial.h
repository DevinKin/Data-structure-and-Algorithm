#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#define  MaxDegree 1000

/* array way */
typedef struct {
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} * Polynomial;


typedef struct Node *PtrToNode;

struct Node {
    int Cofficient;
    int Exponent;
    PtrToNode Next;
};

/* Nodes sorted by exponent */
/* typedef PtrToNode Polynomial; */

void
ZeroPolynomial(Polynomial Poly);

void
AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum);


void
MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);

#endif
