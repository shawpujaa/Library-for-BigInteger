
// Coded By Pujaa



#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class bigInt{
private:
	string value;
	char sign;

public:

	//constructors
	bigInt();
	bigInt(const bigInt&);
	bigInt(const long long&);
	bigInt(const string&);

	//assignment operators
	bigInt& operator=(const bigInt&);
	bigInt& operator=(const long long&);
	bigInt& operator=(const string&);
 	
 	//unary
 	//will change (this) only on assignment hence const
 	bigInt operator+() const;   
    bigInt operator-() const; 

    //Arithmetic
	bigInt operator+(const bigInt&) const ;
	bigInt operator-(const bigInt&) const ;
	bigInt operator*(const bigInt&) const ;
	bigInt operator/(const bigInt&) const ;
	bigInt operator%(const bigInt&) const ;
	bigInt operator+(const long long&) const ;
	bigInt operator-(const long long&) const ;
	bigInt operator*(const long long&) const ;
	bigInt operator/(const long long&) const ;
	bigInt operator%(const long long&) const ;
	bigInt operator+(const string&) const ;
	bigInt operator-(const string&) const ;
	bigInt operator*(const string&) const ;
	bigInt operator/(const string&) const ;
	bigInt operator%(const string&) const ;

	//Arithmetic assignment
	bigInt& operator+=(const bigInt&);
	bigInt& operator-=(const bigInt&);
	bigInt& operator*=(const bigInt&);
	bigInt& operator/=(const bigInt&);
	bigInt& operator%=(const bigInt&);
	bigInt& operator+=(const long long&);
	bigInt& operator-=(const long long&);
	bigInt& operator*=(const long long&);
	bigInt& operator/=(const long long&);
	bigInt& operator%=(const long long&);
	bigInt& operator+=(const string&);
	bigInt& operator-=(const string&);
	bigInt& operator*=(const string&);
	bigInt& operator/=(const string&);
	bigInt& operator%=(const string&);

	//increment , decrement
	//pre
	bigInt& operator++();    
	bigInt& operator--();
	//post
	bigInt operator++(int);
	bigInt operator--(int);


	//relational 
	bool operator<(const bigInt&) const;
	bool operator>(const bigInt&) const;
	bool operator<=(const bigInt&) const;
	bool operator>=(const bigInt&) const;
	bool operator==(const bigInt&) const;
	bool operator!=(const bigInt&) const;
	bool operator<(const long long&) const;
	bool operator>(const long long&) const;
	bool operator<=(const long long&) const;
	bool operator>=(const long long&) const;
	bool operator==(const long long&) const;
	bool operator!=(const long long&) const;
	bool operator<(const string&) const;
	bool operator>(const string&) const;
	bool operator<=(const string&) const;
	bool operator>=(const string&) const;
	bool operator==(const string&) const;
	bool operator!=(const string&) const;

	//Input/Output
	friend istream& operator>>(istream&, bigInt&);
	friend ostream& operator<<(ostream&, const bigInt&);

	// Conversion functions:
	string to_String() const;
	int to_Int() const;
	long long to_Long_Long() const;
};


// ----------------------------------------------


//Basic math

// Functions do not end with const as they are not 
// member functions


// Absolute Function ------
bigInt abs(const bigInt& num){
	return num < 0 ? -num : num;
}


// Power Function ----------
bigInt pow(const bigInt &base, long long exp){
	if(exp < 0){
		if(base == 0)
			throw logic_error("Can't divide by zero");
		return abs(base) == 1 ? base : 0;
	}

	if(exp == 0){
		if(base == 0)
			throw logic_error("0 to the power 0 is undefined");
		return 1;
	}

	bigInt res = 1, tempBase = base;
	while(exp){
		if(exp % 2)
			res *= tempBase;
		exp /= 2;
		tempBase *= tempBase;
	}

	return res;

}

bigInt pow(const long long &base, int exp){
	return pow(bigInt(base), exp);
}

bigInt pow(const string &base, int exp){
	return pow(bigInt(base), exp);
}


// Square Root Function --------
bigInt sqrt(const bigInt& num){
	if(num < 0)
		throw invalid_argument("Number must be non negative!");

	if(num == 1)
		return 1;

	//num1xnum2=num. Max value of numi = num/2
	bigInt start = 0, end = num / 2;
	bigInt ans = 0;
	while(start <= end){
		bigInt mid = (start + end) / 2;
		
		if(mid * mid == num)
			return mid;
	
		else if(mid * mid < num){
			start = mid+1;
			ans = mid;
		}

		else
			end = mid-1;

	}

	return ans;

}


// GCD Function ---------
bigInt gcd(const bigInt &num1, const bigInt &num2){
	bigInt absNum1 = abs(num1);
	bigInt absNum2 = abs(num2);

	if(absNum1 == 0)
		return absNum2;

	if(absNum2 == 0)
		return absNum1;

	if(absNum2 > absNum1)
		return gcd(num2, num1);

	bigInt rem = absNum2;

	while(rem != 0){
		rem = absNum1 % absNum2;
		absNum1 = absNum2;
		absNum2 = rem;
	}

	return absNum1;
}


bigInt gcd(const bigInt& num1, const long long& num2){
    return gcd(num1, bigInt(num2));
}


bigInt gcd(const bigInt& num1, const string& num2){
    return gcd(num1, bigInt(num2));
}


bigInt gcd(const long long& num1, const bigInt& num2){
    return gcd(bigInt(num1), num2);
}


bigInt gcd(const string& num1, const bigInt& num2){
    return gcd(bigInt(num1), num2);
}


// LCM Function --------
bigInt lcm(const bigInt& num1, const bigInt& num2){
	if(num1 == 0 || num2 == 0)
		return 0;

	return abs(num1 * num2) / gcd(num1,num2);
}


bigInt lcm(const bigInt& num1, const long long& num2){
    return lcm(num1, bigInt(num2));
}


bigInt lcm(const bigInt& num1, const string& num2){
    return lcm(num1, bigInt(num2));
}


bigInt lcm(const long long& num1, const bigInt& num2){
    return lcm(bigInt(num1), num2);
}


bigInt lcm(const string& num1, const bigInt& num2){
    return lcm(bigInt(num1), num2);
}


bool isValidNumber(const string& magnitude){
	for(auto ch : magnitude){
		if(ch < '0' || ch > '9')
			return false;
	}
	return true;
}

void stripLeadingZeros(string &value){
	long long i = 0;
	for(i; i < value.size(); i++){
		if(value[i] != '0')
			break;
	}
	if(i == value.size())
		value = "0";
	else
		value = value.substr(i);
}



// ----------------------------------------------

//Constructors

//Default
bigInt::bigInt(){
	value = "0";
	sign = '+';
}

//Copy
bigInt::bigInt(const bigInt &num){
	value = num.value;
	sign = num.sign;
}

bigInt::bigInt(const long long& num) {
    value = to_string(abs(num));
    if (num < 0)
        sign = '-';
    else
        sign = '+';
}

//string to bigInt
bigInt::bigInt(const string &num){
	//if string is signed
	if(num[0] == '+' || num[0] == '-'){
		string magnitude = num.substr(1);

		if(isValidNumber(magnitude)){
			value = magnitude;
			sign = num[0];
		}else{
            throw invalid_argument("Expected an integer, got \'" + num + "\'");
		}
	}
	//if sign isn't specified assign +ve
	else{
		string magnitude = num;
		if(isValidNumber(magnitude)){
			value = magnitude;
			sign = '+';
		}else{
            throw invalid_argument("Expected an integer, got \'" + num + "\'");
		}	
	}


	stripLeadingZeros(value);
	
}
// ----------------------------------------------

//assignment

bigInt& bigInt::operator=(const bigInt& num){
	value = num.value;
	sign = num.sign;

	return *this;
}

bigInt& bigInt::operator=(const long long& num){
	bigInt temp(num);
	value = temp.value;
	sign = temp.sign;

	return *this;
}

bigInt& bigInt::operator=(const string& num) {
    bigInt temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}





// ----------------------------------------------

//Conversions



string bigInt::to_String() const{
	if(this->sign == '-')
		return "-" + this->value;

	return this->value;
}


int bigInt::to_Int() const {
    return stoi(this->to_String());
}

long long bigInt::to_Long_Long() const {
    return stoll(this->to_String());
}


// ----------------------------------------------


//unary arithmetic

bigInt bigInt::operator+() const{
	return *this;
}

bigInt bigInt::operator-() const{
	bigInt num;
	
	if(value != "0"){
		if(sign == '+'){
			num.sign = '-';
		}
		else{
			num.sign = '+';
		}
	}

	num.value = value;

	return num;
}



// ----------------------------------------------

// Binary arithmetic


// Addition --------
bigInt bigInt::operator+(const bigInt &num) const{

	if(this->sign == '+' && num.sign == '-'){
		bigInt rhs = num;
		rhs.sign = '+';
		return *this - rhs;
	}

	else if(this->sign == '-' && num.sign == '+'){
		bigInt lhs = *this;
		lhs.sign = '+';
		return -(lhs - num);
	}

	string larger = this->to_String();
	string smaller = num.to_String();

	if(smaller.size() > larger.size())
		swap(smaller, larger);

	long long j = smaller.size() - 1;
	for(long long i = larger.size() - 1; j >= 0; i--, j--){
		larger[i] = larger[i] + (smaller[j]-'0');
	}
	int carry = 0, sum = 0;
	for(long long i = larger.size()-1; i >= 0; i--){
		sum = carry + (larger[i]-'0');
		carry = sum / 10;
		larger[i] = (sum%10) + '0';
	}

	if(carry){
		larger = to_string(carry) + larger;
	}

	stripLeadingZeros(larger);
	bigInt res(larger);

	if(this->sign == '-' && res.value != "0")
		res.sign = '-';

	return res;

}

bigInt bigInt::operator+(const long long& num) const {
    return *this + bigInt(num);
}

bigInt operator+(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) + rhs;
}
bigInt bigInt::operator+(const string& num) const {
    return *this + bigInt(num);
}

bigInt operator+(const string& lhs, const bigInt& rhs) {
    return bigInt(lhs) + rhs;
}



// Subtraction --------
bigInt bigInt::operator-(const bigInt& num) const{
	if(this->sign == '+' && num.sign == '-'){
		bigInt rhs = num;
		rhs.sign = '+';
		return *this + rhs;
	}

	else if(this->sign == '-' && num.sign == '+'){
		bigInt lhs = *this;
		lhs.sign = '+';
		return -(lhs + num);
	}

	bigInt result;
	string larger, smaller;
	if(abs(*this) > abs(num)){
		larger = this->value;
		smaller = num.value;

		if(this->sign == '-')
			result.sign = '-';
	}

	else{
		larger = num.value;
		smaller = this->value;

		if(num.sign == '+')
			result.sign = '-';
	}


	long long j = smaller.size() - 1;
	long long i = larger.size() - 1;
	int carry = 0, sum = 0;
	for(j,i; j >= 0; i--,j--){
		sum = (larger[i]-'0') - (smaller[j]-'0') - carry;
		if(sum < 0){
			sum += 10;
			carry = 1; 
		}

		else
			carry = 0;

		larger[i] = sum+'0';
	}

	while(carry && i >= 0){
		sum = (larger[i]-'0')- carry;
		if(sum < 0){
			sum += 10;
			carry = 1; 
		}

		else
			carry = 0;

		larger[i] = sum+'0';
		i--;
	}

	stripLeadingZeros(larger);

	result.value = larger;

	if(result.value == "0")
		result.sign = '+';

	return result;


}

bigInt bigInt::operator-(const long long& num) const {
    return *this - bigInt(num);
}

bigInt operator-(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) - rhs;
}
bigInt bigInt::operator-(const string& num) const {
    return *this - bigInt(num);
}

bigInt operator-(const string& lhs, const bigInt& rhs) {
    return bigInt(lhs) - rhs;
}


// Multiplication --------
bigInt bigInt::operator*(const bigInt &num) const{

	if(*this == 0 || num == 0)
		return bigInt(0);

	if(*this == 1)
		return num;

	if(num == 1)
		return *this;

	bigInt product;


	string num1 = this->to_String();
	string num2 = num.to_String();

	string res(num1.size()+num2.size(),'0');

	if(num1.size() < num2.size())
		swap(num1,num2);

    for(long long i = num1.size()-1; i >= 0; i--){
        for(long long j = num2.size()-1; j >= 0; j--){
            long long number = (num1[i]-'0') * (num2[j]-'0') + (res[i+j+1] - '0');
            res[i+j] = res[i+j] + number/10;
            res[i+j+1] = (number % 10) + '0'; 
            
        }
    }
    
   	stripLeadingZeros(res);
 	product = res;

 	if(this->sign == num.sign)
 		product.sign = '+';

 	else
 		product.sign = '-';

 	return product;

}

bigInt bigInt::operator*(const long long& num) const {
    return *this * bigInt(num);
}

bigInt operator*(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) * rhs;
}

bigInt bigInt::operator*(const string& num) const {
    return *this * bigInt(num);
}


bigInt operator*(const string& lhs, const bigInt& rhs) {
    return bigInt(lhs) * rhs;
}



// Division ---------
bigInt bigInt::operator/(const bigInt &num) const{

	bigInt dividend = abs(*this);
	bigInt divisor = abs(num);

	if(num == 0)
		throw logic_error("Divisor can't be zero");

	if(dividend < divisor)
		return bigInt(0);

	if(num == 1)
		return *this;

	if(num == -1)
		return *this;

	bigInt quotent = 0, factor = 1;
	while(dividend >= divisor){
		factor = 1;
		while(2*divisor <= dividend){
			divisor *= 2;
			factor *= 2;
		}

		dividend -= divisor;
		quotent += factor;
		divisor = abs(num);
	}

	stripLeadingZeros(quotent.value);

	if(this->sign == num.sign)
		quotent.sign = '+';
	else
		quotent.sign = '-';

	return quotent;


}



bigInt bigInt::operator/(const long long& num) const {
    return *this / bigInt(num);
}

bigInt operator/(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) / rhs;
}


bigInt bigInt::operator/(const string& num) const {
    return *this / bigInt(num);
}

bigInt operator/(const string& lhs, const bigInt& rhs) {
    return bigInt(lhs) / rhs;
}


// Modulo ----------
bigInt bigInt::operator%(const bigInt &num) const{

	bigInt dividend = abs(*this);
	bigInt divisor = abs(num);

	if(num == 0)
		throw logic_error("Divisor can't be zero");

	if(divisor == 1 || dividend == divisor)
		return bigInt(0);

	bigInt quotent = dividend / divisor;
	bigInt remainder = dividend - (quotent * divisor);

	remainder.sign = this->sign;
	if(remainder.value == "0")
		remainder.sign = '+';

	return remainder;

}


bigInt bigInt::operator%(const long long& num) const {
    return *this % bigInt(num);
}


bigInt operator%(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) % rhs;
}



bigInt bigInt::operator%(const string& num) const {
    return *this % bigInt(num);
}


bigInt operator%(const string& lhs, const bigInt& rhs) {
    return bigInt(lhs) % rhs;
}



// ----------------------------------------------

// I/O Stream

istream& operator>>(istream &in, bigInt &num){
	string input;
	in >> input;
	num = bigInt(input);

	return in;
}

ostream& operator<<(ostream &out, const bigInt& num){
	if(num.sign == '-')
		out << num.sign;
	out << num.value;
	return out;
}

// ----------------------------------------------

// relational arithmetic

bool bigInt::operator==(const bigInt& num) const{
	return (sign == num.sign) && (value == num.value);
}

bool bigInt::operator!=(const bigInt& num) const{
	return !(*this == num);
}

bool bigInt::operator<(const bigInt& num) const{
	if(sign == num.sign){
		if(sign == '+'){
			if(value.length() == num.value.length())
				return value < num.value;
			else
				return value.length() < num.value.length();
		}
		else
			return -(*this) > -num;
	}

	else
		return sign == '-';
}


bool bigInt::operator>(const bigInt& num) const{
	return !((*this < num) || (*this == num));
}


bool bigInt::operator<=(const bigInt& num) const{
	return (*this < num) || (*this == num);
}

bool bigInt::operator>=(const bigInt& num) const{
	return !(*this < num);
}


bool bigInt::operator==(const long long& num) const {
    return *this == bigInt(num);
}

bool operator==(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) == rhs;
}


bool bigInt::operator!=(const long long& num) const {
    return *this != bigInt(num);
}

bool operator!=(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) != rhs;
}


bool bigInt::operator<(const long long& num) const {
    return *this < bigInt(num);
}

bool operator<(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) < rhs;
}

bool bigInt::operator>(const long long& num) const {
    return *this > bigInt(num);
}

bool operator>(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) > rhs;
}

bool bigInt::operator<=(const long long& num) const {
    return *this <= bigInt(num);
}

bool operator<=(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) <= rhs;
}


bool bigInt::operator>=(const long long& num) const {
    return *this >= bigInt(num);
}

bool operator>=(const long long& lhs, const bigInt& rhs) {
    return bigInt(lhs) >= rhs;
}


bool bigInt::operator==(const string& num) const {
    return *this == bigInt(num);
}

bool operator==(const std::string& lhs, const bigInt& rhs) {
    return bigInt(lhs) == rhs;
}


bool bigInt::operator!=(const std::string& num) const {
    return *this != bigInt(num);
}

bool operator!=(const std::string& lhs, const bigInt& rhs) {
    return bigInt(lhs) != rhs;
}


bool bigInt::operator<(const std::string& num) const {
    return *this < bigInt(num);
}

bool operator<(const std::string& lhs, const bigInt& rhs) {
    return bigInt(lhs) < rhs;
}


bool bigInt::operator>(const std::string& num) const {
    return *this > bigInt(num);
}

bool operator>(const std::string& lhs, const bigInt& rhs) {
    return bigInt(lhs) > rhs;
}


bool bigInt::operator<=(const std::string& num) const {
    return *this <= bigInt(num);
}

bool operator<=(const std::string& lhs, const bigInt& rhs) {
    return bigInt(lhs) <= rhs;
}


bool bigInt::operator>=(const std::string& num) const {
    return *this >= bigInt(num);
}


bool operator>=(const std::string& lhs, const bigInt& rhs) {
    return bigInt(lhs) >= rhs;
}



// ----------------------------------------------

//Arithmetic assignment 


bigInt& bigInt::operator+=(const bigInt& num){
	*this = *this + num;

	return *this;
}


bigInt& bigInt::operator-=(const bigInt& num){
	*this = *this - num;

	return *this;
}

bigInt& bigInt::operator*=(const bigInt& num){
	*this = *this * num;

	return *this;
}

bigInt& bigInt::operator/=(const bigInt& num){
	*this = *this / num;

	return *this;
}

bigInt& bigInt::operator%=(const bigInt& num){
	*this = *this % num;

	return *this;
}


bigInt& bigInt::operator+=(const long long& num) {
    *this = *this + bigInt(num);

    return *this;
}

bigInt& bigInt::operator-=(const long long& num) {
    *this = *this - bigInt(num);

    return *this;
}

bigInt& bigInt::operator*=(const long long& num) {
    *this = *this * bigInt(num);

    return *this;
}

bigInt& bigInt::operator/=(const long long& num) {
    *this = *this / bigInt(num);

    return *this;
}

bigInt& bigInt::operator%=(const long long& num) {
    *this = *this % bigInt(num);

    return *this;
}


bigInt& bigInt::operator+=(const string& num) {
    *this = *this + bigInt(num);

    return *this;
}


bigInt& bigInt::operator-=(const string& num) {
    *this = *this - bigInt(num);

    return *this;
}


bigInt& bigInt::operator*=(const string& num) {
    *this = *this * bigInt(num);

    return *this;
}



bigInt& bigInt::operator/=(const string& num) {
    *this = *this / bigInt(num);

    return *this;
}


bigInt& bigInt::operator%=(const string& num) {
    *this = *this % bigInt(num);

    return *this;
}

	

// ----------------------------------------------

// Increment / Decrement


//Pre
bigInt& bigInt::operator++(){
	*this += 1;
	return *this;
}


bigInt& bigInt::operator--(){
	*this -= 1;
	return *this;
}

//Post

bigInt bigInt::operator++(int){
	bigInt temp = *this;
	*this += 1;
	return temp;
}

bigInt bigInt::operator--(int){
	bigInt temp = *this;
	*this -= 1;
	return temp;
}



// ----------------------------------------------