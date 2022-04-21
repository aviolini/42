#pragma once
#include <exception>

class ServExc : public std::exception
{
	const char *err_s;
	int err_n;
public:
	ServExc(const char *err_s, const int & err_n = 1) : err_s(err_s), err_n(err_n){}

	virtual ~ServExc() throw(){}
	virtual const char* what() const throw()
	{
		return err_s;
	}
	const int & getErr() const throw()
	{
		return this->err_n;
	}
};