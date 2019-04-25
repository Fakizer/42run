#include "Exeptions_42run.hpp"

Exeptions_42run::Exeptions_42run(void)
{
	this->_msg = "General Exception : An Error happend !";
}

Exeptions_42run::~Exeptions_42run(void) throw()
{
}

Exeptions_42run::Exeptions_42run(Exeptions_42run const &src)
{
	this->_msg = src._msg.c_str();
}

Exeptions_42run &Exeptions_42run::operator=(Exeptions_42run const &rhs)
{
	this->_msg = rhs._msg.c_str();
	return (*this);
}

const char *Exeptions_42run::what(void) const throw()
{
	return (this->_msg.c_str());
}
