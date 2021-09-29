#include <iostream>
#include "pch.h"
#include <sstream>
#include <string>
#include <cstdlib>
#include <exception>
#include "FractionHome.h"
#include "Exception.h"

int Fraction::next_ID = 0;

Fraction:: Fraction(): ID(++next_ID) {
	this->numerator = 0;
	this->denominator = 1;
}


Fraction::Fraction(Fraction &a):ID(++next_ID) {
	if (a.numerator < 0) {
		throw "You entered numerator with -";
	}
	else {
		denominator = a.denominator;
		numerator = a.numerator;
		reduce();
	}
}
Fraction::~Fraction() {}


int Fraction::nod(long a, long b) {
	return b == 0 ? a : this->nod(b, a % b);
}


int Fraction::getID()
{
	return ID;
}

int Fraction::getNumerator(void) {
	return this->numerator;
}

/**
 * Getter for the denominator
*/
int Fraction::getDenominator(void) {
	return this->denominator;
}

/**
 * Setter for the numerator
*/
void Fraction::setNumerator(long Numerator) {
	this->numerator = Numerator;
}

/**
 * Setter for the denominator
*/
void Fraction::setDenominator(long Denominator) {
	this->denominator = Denominator;
}

/**
 * Reduce the fraction as low as possible
*/
bool Fraction::reduce(void) {
	long gcd(this->nod(this->numerator, this->denominator));

	if (1 < gcd) {
		this->numerator /= gcd;
		this->denominator /= gcd;

		return true;
	}
	else {
		return false;
	}
}

void Fraction::convertDoubleToFraction(double Number) {
	this->denominator = 1;

	while (((double)(int)Number) != Number) {
		Number = Number * 10;
		this->denominator = this->denominator * 10;
	}

	this->numerator = (long)Number;

	this->reduce();
}


double Fraction::convertFractionToDouble(void) {
	return (double)this->numerator / (double)this->denominator;
}


bool Fraction::convertStringToFraction(std::string FractionString) {
	std::size_t pos = FractionString.find("/");

	if (pos != std::string::npos) {
		try {
			this->numerator = atol(FractionString.substr(0, pos).c_str());
			this->denominator = atol(FractionString.substr(pos + 1).c_str());
		}
		catch (...) {
			return false;
		}

		return (this->denominator == 0) ? false : true;
	}

	return false;
}


bool Fraction::operator<(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) < (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

bool Fraction::operator<=(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) <= (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

bool Fraction::operator>(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) > (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

/**
 * Bigger than or equal operator overloading
*/
bool Fraction::operator>=(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) >= (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

/**
 * Equal operator overloading
*/
bool Fraction::operator==(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) == (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

/**
 * Non-Equal operator overloading
*/
bool Fraction::operator!=(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) != (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}


int Fraction::operator%(Fraction fraction) {
	long result;

	result = ((this->numerator * fraction.getDenominator()) % (this->denominator * fraction.getNumerator())) / (this->denominator * fraction.getDenominator());

	return result;
}

Fraction& Fraction::operator=(const Fraction& a){
	if (this == &a){
		throw (MyException( "You are trying to assign a value to itself"));
	}
	this->numerator = a.numerator;
	this->denominator = a.denominator;
	return *this;
}

Fraction Fraction::operator+(Fraction fraction) {
	Fraction resultFraction;

	if (this->denominator == fraction.getDenominator()) {
		resultFraction.setNumerator(this->numerator + fraction.getNumerator());
		resultFraction.setDenominator(this->denominator);
	}
	else {
		resultFraction.setNumerator((this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator));
		resultFraction.setDenominator(this->denominator * fraction.getDenominator());
	}

	return resultFraction;
}

Fraction Fraction::operator+=(Fraction fraction) {
	if (this->denominator == fraction.getDenominator()) {
		this->numerator += fraction.getNumerator();
	}
	else {
		this->numerator = (this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator);
		this->denominator *= fraction.getDenominator();
	}

	return *this;
}

Fraction Fraction::operator-(Fraction fraction) {
	Fraction resultFraction;

	if (this->denominator == fraction.getDenominator()) {
		resultFraction.setNumerator(this->numerator - fraction.getNumerator());
		resultFraction.setDenominator(this->denominator);
	}
	else {
		resultFraction.setNumerator((this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator));
		resultFraction.setDenominator(this->denominator * fraction.getDenominator());
	}

	return resultFraction;
}

Fraction Fraction::operator-=(Fraction fraction) {
	if (this->denominator == fraction.getDenominator()) {
		this->numerator -= fraction.getNumerator();
	}
	else {
		this->numerator = (this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator);
		this->denominator *= fraction.getDenominator();
	}

	return *this;
}

 Fraction operator * (int a,const Fraction &d){
	Fraction resultFraction;

	resultFraction.setDenominator(d.denominator * a);

	return resultFraction;
}

Fraction Fraction::operator*(Fraction fraction) {
	Fraction resultFraction;

	resultFraction.setNumerator(this->numerator * fraction.getNumerator());
	resultFraction.setDenominator(this->denominator * fraction.getDenominator());

	return resultFraction;
}

Fraction Fraction::operator*=(Fraction fraction) {
	this->denominator *= fraction.getDenominator();
	this->numerator *= fraction.getNumerator();

	return *this;
}

Fraction Fraction::operator/(Fraction fraction) {
	Fraction resultFraction;

	resultFraction.setDenominator(this->denominator * fraction.getNumerator());
	resultFraction.setNumerator(this->numerator * fraction.getDenominator());

	return resultFraction;
}

Fraction Fraction ::operator /(int a){
	Fraction resultFraction;

	if (a == 0)
	{
		throw (MyException("Division on zero"));
	}
	else
	{
		resultFraction.setNumerator(this->numerator * a);
	}
	return resultFraction;
}

Fraction Fraction::operator/=(Fraction fraction) {
	this->denominator *= fraction.getNumerator();
	this->numerator *= fraction.getDenominator();

	return *this;
}

/**
 * Complement operator overloading
*/
Fraction Fraction::operator~(void) {
	Fraction resultFraction;

	if (this->numerator > this->denominator) {
		return *this;
	}
	else {
		resultFraction.setNumerator(this->denominator - this->numerator);
		resultFraction.setDenominator(this->denominator);

		return resultFraction;
	}
}

Fraction Fraction::operator++(int) {
	this->numerator += 1;

	return *this;
}

Fraction Fraction::operator --(int) {
	this->numerator -= 1;

	return *this;
}

Fraction Fraction::operator++(void) {
	this->numerator += 1;

	return *this;
}

Fraction Fraction::operator--(void) {
	this->numerator -= 1;

	return *this;
}

std::ostream& operator<<(std::ostream &out, Fraction &Fraction) {
	out << Fraction.getNumerator() << "/" << Fraction.getDenominator();

	return out;
}