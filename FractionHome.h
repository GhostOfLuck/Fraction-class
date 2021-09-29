#pragma once

class Fraction {
private:
	int numerator, denominator;
	static int next_ID;
	const int ID;
	int nod(long a, long b);
public:
	Fraction();
	Fraction(Fraction &a );
	~Fraction(void);

	int getID();
	int getNumerator(void);
	int getDenominator(void);
	void setNumerator(long Numerator);
	void setDenominator(long Denominator);

	bool reduce(void);
	void convertDoubleToFraction(double Number);
	double convertFractionToDouble(void);
	bool convertStringToFraction(std::string FractionString);

	bool operator<(Fraction fraction);
	bool operator<=(Fraction fraction);
	bool operator>(Fraction fraction);
	bool operator>=(Fraction fraction);
	bool operator==(Fraction fraction);
	bool operator!=(Fraction fraction);
	int operator%(Fraction fraction);

	Fraction& operator = (const Fraction& a);

	Fraction operator+(Fraction fraction);
	Fraction operator+=(Fraction fraction);
	Fraction operator-=(Fraction fraction);
	Fraction operator-(Fraction fraction);
	Fraction operator*(Fraction fraction);
	friend Fraction operator*(int a,const Fraction &d);
	Fraction operator*=(Fraction fraction);
	Fraction operator/(Fraction fraction);
	Fraction operator/(int a);
	Fraction operator/=(Fraction fraction);
	Fraction operator~(void);
	Fraction operator++(int);
	Fraction operator--(int);
	Fraction operator++(void);
	Fraction operator--(void);
};


/** Left Shift Operator overloading functions (need to be declared global) */
std::ostream& operator<<(std::ostream &out, Fraction &Fraction);


