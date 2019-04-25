#ifndef EXEPTIONS_42RUN_HPP
# define EXEPTIONS_42RUN_HPP

#include <string>

class Exeptions_42run : public std::exception
{
	public :

		explicit Exeptions_42run(void);
		virtual ~Exeptions_42run(void) throw();
		Exeptions_42run(Exeptions_42run const &src);
		Exeptions_42run &operator=(Exeptions_42run const &rhs);
		virtual const char *what(void) const throw();

	protected :

		std::string _msg;
};

#endif
