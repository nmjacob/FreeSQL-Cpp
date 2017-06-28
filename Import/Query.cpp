#include<sstream>
#include<iostream>
#include "Query.h"
#include<stdlib.h>
#include<string>
using namespace std;

Expression::Expression() {
}


string Expression::getType() {
	return type;
}


TwoVarExpression::~TwoVarExpression() {
	delete lvalue;
	delete rvalue;
}


Mult::Mult(Expression lvalue, Expression rvalue) {
	type = "Mult";
	this->lvalue = &lvalue;
	this->rvalue = &rvalue;
}


Expression *Mult::Eval() {

	lvalue = lvalue->Eval();
	rvalue = rvalue->Eval();

	if(0 == lvalue->getType().compare("Error") || 0 == rvalue->getType().compare("Error")) {
		cout << "Expression is bad!\n" << endl;
		return new Error();
	}
	
	if(0 == lvalue->getType().compare("Int")) {
		if(0 == rvalue->getType().compare("Int")) {
			return new Int(atoi(lvalue->getValue().c_str())
					* atoi(rvalue->getValue().c_str()));
		}
		if(0 == rvalue->getType().compare("Float")) {
			return new Float(atof(lvalue->getValue().c_str())
					* atof(rvalue->getValue().c_str()));
		}
	}
	if(0 == rvalue->getType().compare("Float")
			|| 0 == lvalue->getType().compare("Float")) {
		return new Float(atof(lvalue->getValue().c_str())
					* atof(rvalue->getValue().c_str()));
	}

	return new Error();
}


Int::Int(int input) {
	value = input;
}


//TODO: Test
string Int::getValue() {
	stringstream ss;
	ss << value;
	return ss.str();
}


Float::Float(float input) {
	value = input;
}


//TODO: Test
string Float::getValue() {
	stringstream ss;
	ss << value;
	return ss.str();
}


Error::Error() {
	type = "Error";
}

