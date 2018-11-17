#include "polynomial.h"
#include "utils.h"
#include <stdio.h>

void ZeroPolynomial(Polynomial poly) {
    for(int i = 0; i < MaxDegree; i++) {
        poly->CoeffArray[i] = 0;
    }
    poly->HighPower = 0;
}

void
AddPolynomial(const Polynomial Poly1,
              const Polynomial Poly2, const Polynomial PolySum) {
    int i;
    ZeroPolynomial(PolySum);
    PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);

    for(i = PolySum->HighPower; i >= 0; i--) {
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
    }
}

void
MultPolynomial(const Polynomial Poly1,
               const Polynomial Poly2, const Polynomial PolyProd) {
    int i, j;
    ZeroPolynomial(PolyProd);
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

    if (PolyProd->HighPower > MaxDegree) {
        perror("Exceeded array size");
    } else {
        for (int i = 0; i <= Poly1->HighPower; i++) {
            for (int j = 0; j <= Poly2->HighPower; j++) {
                PolyProd->CoeffArray[i + j] +=
                    Poly1->CoeffArray[i] *
                    Poly2->CoeffArray[j];
            }
        }
    }
}
