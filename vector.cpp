#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "city.h"
using namespace std;

Vector::Vector()
{
  size = 10;
  count = 0;
  cityArray = new City [size];
  
  for (int i = 0; i < size; i++)
  initialize(&cityArray[i]);
}

~Vector::Vector(cities)
{
  for (int i = 0; i < count; i++)
    ::deallocate(&cityArray[i]);
  delete[] cityArray;
}

void Vector::calcDistance(cities, int index1, int index2) const
{
  ::calcDistance(&cityArray[index1], &cityArray[index2]);
}  // calcDistance()

void Vector::cleanCities(cities)
{
  int i = 0;
  
  while (i < count)
  {
    if (!hasAirport(&cityArray[i]))
    {
      deallocate(&cityArray[i]);
      cityArray[i] = cityArray[--count];
    }  // if city does not have an airport
    else // city has an airport
      i++;
  }  // while more in array
}  // cleanCities())


int Vector::findAirport(cities, char *airport) const
{
  City city;
  
  initialize(&city);
  setAirport(&city, airport);
  
  for (int i = 0; i < count; i++)
    if (isEqual(&cityArray[i], &city))
      return i;
  cout << airport << " is not a valid airport." << endl;
  return -1;
}  // findAirport()


void Vector::readAirports(cities)
{

  char line[1000];
  City city;
  initialize(&city);
  ifstream fp("airportLL.txt");

  while (fp.getline(line, 1000))
  {
    if (line[0] == '[')
    {
      readAirport(&city, line);
      
      for (int i = 0; i < count; i++)
        if (isEqual(&cityArray[i], &city))
        {
          copyLocation(&cityArray[i], &city);
          break;
        }  // if found a matching name
      
      deallocate(&city);
    }  // if an airport line
  }  // while
}  // readAirports()


void Vector::readCities(cities)
{
  ifstream fp("citypopulations.csv");
  
  while(!fp.eof())
  {
    if (size == count)
      resize(cities);
  
    readCity(&cityArray[count++], fp);
  } // while more in file
  
  count--;
  fp.close();
}  // readCities()


void Vector::resize(cities)
{
  int i;
  City *temp;
  temp = new City [2 * size];
  
  for (i = 0; i < size; i++)
    temp[i] = cityArray[i];
  
  size *= 2;
  
  for (; i < size; i++)
    initialize(&temp[i]);
    
  delete[] cityArray;
  cityArray = temp;
}  // resize()


