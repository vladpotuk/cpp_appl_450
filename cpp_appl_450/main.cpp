#include <iostream>
#include <cmath>


int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


struct Fraction {
    int numerator;   // чисельник
    int denominator; // знаменник
};
void simplifyFraction(Fraction& fraction) {
    int gcd = findGCD(abs(fraction.numerator), abs(fraction.denominator));
    fraction.numerator /= gcd;
    fraction.denominator /= gcd;
}


void getIntegerAndFractionalParts(const Fraction& fraction, int& integerPart, Fraction& fractionalPart) {
    integerPart = fraction.numerator / fraction.denominator;
    fractionalPart.numerator = fraction.numerator % fraction.denominator;
    fractionalPart.denominator = fraction.denominator;
    simplifyFraction(fractionalPart);
}


Fraction addFractions(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    result.numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
    result.denominator = fraction1.denominator * fraction2.denominator;
    simplifyFraction(result);
    return result;
}


Fraction subtractFractions(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    result.numerator = fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator;
    result.denominator = fraction1.denominator * fraction2.denominator;
    simplifyFraction(result);
    return result;
}


Fraction multiplyFractions(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    result.numerator = fraction1.numerator * fraction2.numerator;
    result.denominator = fraction1.denominator * fraction2.denominator;
    simplifyFraction(result);
    return result;
}


Fraction divideFractions(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    result.numerator = fraction1.numerator * fraction2.denominator;
    result.denominator = fraction1.denominator * fraction2.numerator;
    simplifyFraction(result);
    return result;
}

int main() {
    system("chcp 1251");
    system("cls");

    Fraction fraction1;
    std::cout << "Введіть чисельник першого дробу: ";
    std::cin >> fraction1.numerator;
    std::cout << "Введіть знаменник першого дробу: ";
    std::cin >> fraction1.denominator;


    Fraction fraction2;
    std::cout << "Введіть чисельник другого дробу: ";
    std::cin >> fraction2.numerator;
    std::cout << "Введіть знаменник другого дробу: ";
    std::cin >> fraction2.denominator;


    Fraction sumResult = addFractions(fraction1, fraction2);
    Fraction differenceResult = subtractFractions(fraction1, fraction2);
    Fraction productResult = multiplyFractions(fraction1, fraction2);
    Fraction quotientResult = divideFractions(fraction1, fraction2);


    std::cout << "Сума: " << sumResult.numerator << "/" << sumResult.denominator << std::endl;
    std::cout << "Різниця: " << differenceResult.numerator << "/" << differenceResult.denominator << std::endl;
    std::cout << "Добуток: " << productResult.numerator << "/" << productResult.denominator << std::endl;
    std::cout << "Частка: " << quotientResult.numerator << "/" << quotientResult.denominator << std::endl;


    int integerPart;
    Fraction fractionalPart;
    getIntegerAndFractionalParts(quotientResult, integerPart, fractionalPart);
    std::cout << "Ціла частина від ділення: " << integerPart << std::endl;
    std::cout << "Залишкова частина від ділення: " << fractionalPart.numerator << "/" << fractionalPart.denominator << std::endl;

    return 0;
}