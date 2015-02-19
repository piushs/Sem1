#include "VectorDoubleSort1.h"
#include <iostream>


void quicksort (std :: vector <double> &vec, int first, int last)
{
	/*
	int pivot, i, j;
	double temp;
	

	if (first < last)
	{
		pivot=(first+last)/2;
		i=first;
		j=last;

		while (i<j)
		{
			while (vec[i] <= vec[pivot] && i<=last)
				i++;
			while (vec[j] >= vec[pivot] && j>first)
				j--;

			if (i<j )
			{
				temp=vec[i];
				vec[i]=vec[j];
				vec[j]=temp;
			}
		}
		
		if (i > last)
		{
			i--;
		}

		/*if ((vec[i] > vec[pivot] &&  i<pivot) ||
			(vec[pivot] > vec[i] && i > pivot))
		{
			temp=vec[pivot];
			vec[pivot]=vec[i];
			vec[i]=temp; 
		}
		

		quicksort(vec, first, i-1);
		//if (vec[j] > vec[last] ) //&& last - j > 1)
		//if (first != j)
		quicksort(vec, i+1, last);
	} */
	/*
	int pivot, l_hold, r_hold;
	
	l_hold = first;
	r_hold = last;

	pivot = vec[(first+last)/2];

	while (first < last)
	{
		while (vec[last] >= pivot && first < last)
		last--;

		if (first != last)
		{
			vec[first]=vec[last];
			first++;
		}

		while (vec[first] <= pivot && first < last)
		first++;

		if (first != last)
		{
			vec[last]=vec[first];
			last--;
		}
	}

	vec[first]=pivot;
	pivot=(first+last)/2;
	first=l_hold;
	last=r_hold;

	if (first < pivot)
		quicksort (vec, first, pivot-1);
	if (last > pivot)
		quicksort(vec,pivot+1,last); */

	int i=first, j=last;
	int tmp;
	int pivot = vec[abs((first + last)/2)];

	while (i<=j)
	{
		while (vec[i] < pivot)
			i++;
		while (vec[j] > pivot)
			j--;
		if (i<=j)
		{
			tmp=vec[i];
			vec[i]=vec[j];
			vec[j]=tmp;
			i++;
			j--;
		}
	}

	if (first < j)
		quicksort(vec,first,j);
	
	if (i < last)
		quicksort(vec,i,last);


}

void VectorDoubleSort1:: sort (std :: vector <double> &vec)
{
	int pivot, j, temp, i;
	/*
	vec[0]=55;
	vec[1]=12;
	vec[2]=88;
	vec[3]=7;
	vec[4]=4;
	vec[5]=27;
	vec[6]=90;
	vec[7]=0;
	vec[8]=96;
	vec[9]=33;
	vec[10]=84;  */
	/*
	for (int i=0; i<50; i++)
	{
		vec[i]=rand()%50;
	}
	
	
	quicksort(vec,0,49 ); */
	quicksort(vec,0,vec.size() - 1);


	std:: cout << "Piush ";
}
