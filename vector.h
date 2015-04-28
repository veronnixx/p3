#ifndef VECTOR_H
#define	VECTOR_H

#include "city.h"

class Vector
{
  City *cityArray;
  int size;
  int count;

    void initialize();
    void deallocate();
    
   
    void resize();
    
  public:
    Vector()
    {
        size = 10;
        count = 0;
        cityArray = new City [size];
  
        for (int i = 0; i < size; i++)
        ::initialize(&cityArray[i]);
    }
    
    ~Vector()
    {
       for (int i = 0; i < count; i++)
       ::deallocate(&cityArray[i]);
       delete[] cityArray;
    }
    
    void calcDistance(int index1, int index2) const;
    int findAirport(const char *airport) const;
    void cleanCities();
    void readCities();
    void readAirports();
    

};
#endif	// VECTOR_H 

