#ifndef FRACTION_H
#define FRACTION_H

struct Fraction {
    int numerator;
    int denominator;
};

void simplifyFraction(Fraction& fraction);
void getIntegerAndFractionalParts(const Fraction& fraction, int& integerPart, Fraction& fractionalPart);
Fraction addFractions(const Fraction& fraction1, const Fraction& fraction2);
Fraction subtractFractions(const Fraction& fraction1, const Fraction& fraction2);
Fraction multiplyFractions(const Fraction& fraction1, const Fraction& fraction2);
Fraction divideFractions(const Fraction& fraction1, const Fraction& fraction2);
int findGCD(int a, int b);

#endif // FRACTION_H
