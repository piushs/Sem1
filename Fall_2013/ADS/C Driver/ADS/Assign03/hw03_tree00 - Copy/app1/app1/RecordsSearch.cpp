#include "RecordsSearch.h"
#include <iostream>

void quicksort_firstname (std :: vector<Employee> &records, int first, int last)
{
	int i=first, j=last;
	Employee tmp;
	Employee pivot = records[abs((i + j)/2)];

	while (i<=j)
	{
		while (records[i].first_name.compare(pivot.first_name) < 0)
			i++;
		while (records[j].first_name.compare(pivot.first_name) > 0)
			j--;
		if (i<=j)
		{
			tmp=records[i];
			records[i]=records[j];
			records[j]=tmp;
			i++;
			j--;
		}
	}

	if (first < j)
		quicksort_firstname(records,first,j);
	
	if (i < last)
		quicksort_firstname(records,i,last);
}

void quicksort_lastname (std :: vector<Employee> &records, int first, int last)
{
	int i=first, j=last;
	Employee tmp;
	Employee pivot = records[abs((i + j)/2)];

	while (i<=j)
	{
		while (records[i].last_name.compare(pivot.last_name) < 0)
			i++;
		while (records[j].last_name.compare(pivot.last_name) > 0)
			j--;
		if (i<=j)
		{
			tmp=records[i];
			records[i]=records[j];
			records[j]=tmp;
			i++;
			j--;
		}
	}

	if (first < j)
		quicksort_lastname(records,first,j);
	
	if (i < last)
		quicksort_lastname(records,i,last);
}

void quicksort_password (std :: vector<Employee> &records, int first, int last)
{
	int i=first, j=last;
	Employee tmp;
	Employee pivot = records[abs((i + j)/2)];

	while (i<=j)
	{
		while (records[i].password.compare(pivot.password) < 0)
			i++;
		while (records[j].password.compare(pivot.password) > 0)
			j--;
		if (i<=j)
		{
			tmp=records[i];
			records[i]=records[j];
			records[j]=tmp;
			i++;
			j--;
		}
	}

	if (first < j)
		quicksort_password(records,first,j);
	
	if (i < last)
		quicksort_password(records,i,last);
}


void RecordsSearch :: bulkInsert(std::vector<Employee> records)
{
	
	records_firstname = records;
	quicksort_firstname(records_firstname,0,records_firstname.size() -1);

	
	records_lastname = records;
	quicksort_lastname (records_lastname,0, records_lastname.size() -1);

	records_password = records;
	quicksort_password (records_password,0,records_password.size() -1);
}


Employee RecordsSearch :: binary_search_firstname(std :: string	first_name)
{
	int low =0;
	int mid;
	int high = records_firstname.size() -1;

	while (low <= high)
	{
		mid = (low+high)/2;
		if (first_name.compare (records_firstname[mid].first_name) < 0)
		{
			high = mid -1;
		}
		else if (records_firstname[mid].first_name.compare( (first_name)) < 0)
		{
			low = mid +1 ;
		}
		else
			return(records_firstname[mid]);
	}
}

Employee RecordsSearch :: binary_search_lastname(std :: string	last_name)
{
	int low =0;
	int mid;
	int high = records_lastname.size() -1;


	while (low <= high)
	{
		mid = (low+high)/2;
		std :: string str1 = last_name;
		std :: string str2 = records_lastname[mid].last_name;
		
		if (str1.compare (0,str1.length(),str2,0,str2.length()) < 0)
		{
			high = mid -1;
		}
		else if (records_lastname[mid].last_name.compare( last_name) < 0)
		{
			low = mid +1 ;
		}
		else
			return(records_lastname[mid]);
	}
}

Employee RecordsSearch :: binary_search_password(std :: string	password)
{
	int low =0;
	int mid;
	int high = records_password.size() -1;

	while (low <= high)
	{
		mid = (low+high)/2;
		if (password.compare (records_password[mid].password) < 0)
		{
			high = mid -1;
		}
		else if (records_password[mid].password.compare( (password)) < 0)
		{
			low = mid +1 ;
		}
		else
			return(records_password[mid]);
	}
}

Employee RecordsSearch :: searchFirstName(std::string first_name)
{
	return(binary_search_firstname(first_name));
}

Employee RecordsSearch :: searchLastName(std::string last_name)
{
	return(binary_search_lastname(last_name));
}

Employee RecordsSearch :: searchPassword(std::string password)
{
	return(binary_search_password(password));
}