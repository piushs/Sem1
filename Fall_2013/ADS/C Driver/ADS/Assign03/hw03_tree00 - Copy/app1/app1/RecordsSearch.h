#pragma once

#include "Interfaces03.h"

class RecordsSearch : public IRecordsSearch
{
public :
	std :: vector <Employee> records_firstname;
	std :: vector<Employee> records_password;
	std :: vector<Employee> records_lastname;

	RecordsSearch(){};
	~RecordsSearch(){};
	void bulkInsert(std::vector<Employee> records) ;
    Employee searchFirstName(std::string first_name) ;
    Employee searchLastName(std::string last_name) ;
    Employee searchPassword(std::string password) ;
	Employee binary_search_firstname(std :: string	first_name);
	Employee binary_search_lastname(std :: string	last_name);
	Employee binary_search_password(std :: string	password);
};