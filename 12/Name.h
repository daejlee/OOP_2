#ifndef NAME_H
# define NAME_H
# include <string>

class Name {
public:
	explicit Name(std::string="no", std::string="name");
	void setFirstName(std::string);
	void setLastName(std::string);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getFullName() const;
private:
	std::string firstName;
	std::string lastName;
};

#endif