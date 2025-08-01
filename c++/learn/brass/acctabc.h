#ifdef ACCTABC_H_
#define ACCTABC_H_
#include<iostream>
#include<string>

class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string & FullName() const {return fullName;}
	long AcctNum() const {return acctNum;}
	Formatting SetFormat() const;
	void Restore(Formatting & f) const;
public:
	AcctABC(const std::string & s = "Nullbody", long an = -1, double bal - 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;
	double Balance() const {return balance;}
	virtual void ViewAcct() const = 0;
	virtual	~AcctABC() {};
};

class Brass : public AcctABC
{
	brass(const std::string & s = "NullBody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal){}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

class BrassPlus : public AcctABC
{
private:
	double maxloan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s = "NullBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass & ba, double ml=500, double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) {maxloan = m;}
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};
#endif
