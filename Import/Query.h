#ifndef QUERY_H
#define QUERY_H

#include<string>
using namespace std;

class Expression {
	protected:
		string type;
	public:
		Expression();
		virtual ~Expression(){};
		string getType();
		virtual Expression *Eval(){};
		virtual string getValue(){};
};

class TwoVarExpression: public Expression {
	protected:
		Expression *lvalue;
		Expression *rvalue;
	public:
		~TwoVarExpression();
};

class OneVarExpression: public Expression {
	protected:
		Expression *value;
};

class Mult: public TwoVarExpression {
	public:
		Mult(Expression lvalue, Expression rvalue);
		~Mult(){};
		Expression *Eval();
};

class Div: public TwoVarExpression {
	public:
		Div();
};

class Add: public TwoVarExpression {
	public:
		Add();
};

class Sub: public TwoVarExpression {
	public:
		Sub();
};

class Not: public OneVarExpression {
	public:
		Not();
};

class Equals: public TwoVarExpression {
	public:
		Equals();
};

class NEquals: public TwoVarExpression {
	public:
		NEquals();
};

class GreaterThen: public TwoVarExpression {
	public:
		GreaterThen();
};

class LessThen: public TwoVarExpression {
	public:
		LessThen();
};

class GTE: public TwoVarExpression {
	public:
		GTE();
};

class LTE: public TwoVarExpression {
	public:
		LTE();
};

//TODO: Between
//TODO: Like
//TODO: In

/* TODO: Add variables. Requires database implementation
class Variable: public Expression {
	private:
		Variable *value;
		String type;
	public:
		
		Variable eval();
		Variable(Table table);
}
*/

class Bool: public Expression {
	private:
		bool value;
	public:
		string getValue();
		Bool(bool input);
};

class Int: public Expression {
	private:
		int value;
	public:
		string getValue();
		Int(int input);
		~Int(){};
};

class Char: public Expression {
	private:
		string value;
	public:
		string getValue();
		Char(string input);
};

class Float: public Expression {
	private:
		float value;
	public:
		string getValue();
		Float(float value);
		~Float(){};
};

class Error: public Expression {
	public:
		Error();
		~Error(){};
};

/*TODO implement date form checking and logic later
class Date: public Expression {
	private:
		String value;
	public:
		Date(String input);
}*/

#endif
