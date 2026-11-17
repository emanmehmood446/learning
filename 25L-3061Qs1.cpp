#include <iostream>
using namespace std;

class Pokemon
{
private:
    int powerLevel;

public:

    // Default constructor
    Pokemon()
    {
        powerLevel = 0;
    }

    // Parameterized constructor
    Pokemon(int p)
    {
        powerLevel = p;
    }

    // Mutator
    void setPowerLevel(int p)
    {
        powerLevel = p;
    }

    // Accessor
    int getPowerLevel()
    {
        return powerLevel;
    }

    // Pre-increment
    Pokemon operator++()
    {
        powerLevel = powerLevel + 1;
        return *this;
    }

    // Pre-decrement
    Pokemon operator--()
    {
        powerLevel = powerLevel - 1;
        return *this;
    }

    // Addition
    Pokemon operator+(Pokemon p)
    {
        Pokemon temp(powerLevel + p.powerLevel);
        return temp;
    }

    // Subtraction
    Pokemon operator-(Pokemon p)
    {
        Pokemon temp;

        if (powerLevel - p.powerLevel >= 0)
        {
            temp.powerLevel = powerLevel - p.powerLevel;
        }
        else
        {
            temp.powerLevel = p.powerLevel - powerLevel;
        }

        return temp;
    }

    // Multiplication
    Pokemon operator*(Pokemon p)
    {
        Pokemon temp(powerLevel * p.powerLevel);
        return temp;
    }

    // Division
    Pokemon operator/(Pokemon p)
    {
        Pokemon temp;

        if (p.powerLevel == 0)
        {
            temp.powerLevel = powerLevel;
        }
        else
        {
            temp.powerLevel = powerLevel / p.powerLevel;
        }

        return temp;
    }

    // Modulus
    Pokemon operator%(Pokemon p)
    {
        Pokemon temp;

        if (p.powerLevel == 0)
        {
            temp.powerLevel = powerLevel;
        }
        else
        {
            temp.powerLevel = powerLevel % p.powerLevel;
        }

        return temp;
    }

    // Insertion operator
    friend ostream& operator<<(ostream& out, Pokemon p)
    {
        out << "Power Level: " << p.powerLevel;
        return out;
    }

    // Extraction operator
    friend istream& operator>>(istream& in, Pokemon& p)
    {
        cout << "Enter Power Level: ";
        in >> p.powerLevel;
        return in;
    }
};

int main()
{
    Pokemon p1(20);
    Pokemon p2(6);

    cout << "Pokemon 1: " << p1 << endl;
    cout << "Pokemon 2: " << p2 << endl;

    // Pre-increment
    ++p1;
    cout << "After ++p1: " << p1 << endl;

    // Pre-decrement
    --p2;
    cout << "After --p2: " << p2 << endl;

    // Addition
    Pokemon add = p1 + p2;
    cout << "Addition: " << add << endl;

    // Subtraction
    Pokemon sub = p1 - p2;
    cout << "Subtraction: " << sub << endl;

    // Multiplication
    Pokemon mul = p1 * p2;
    cout << "Multiplication: " << mul << endl;

    // Division
    Pokemon div = p1 / p2;
    cout << "Division: " << div << endl;

    // Modulus
    Pokemon mod = p1 % p2;
    cout << "Modulus: " << mod << endl;

    // Testing division by zero
    Pokemon zero(0);

    Pokemon divZero = p1 / zero;
    cout << "Division by zero: " << divZero << endl;

    // Testing modulus by zero
    Pokemon modZero = p1 % zero;
    cout << "Modulus by zero: " << modZero << endl;

    // Extraction operator
    Pokemon p3;

    cin >> p3;

    cout << "Entered Pokemon: " << p3 << endl;

    return 0;
}
