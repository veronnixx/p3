#ifndef CITY_H
#define	CITY_H

#include <iostream>
#include <fstream>
using namespace std;

typedef struct
{
  double longitude;
  double latitude;
  char *name;
  char *state;
  char airport[4];
  int population;
} City;

void initialize(City *city);
void deallocate(City *city);
void calcDistance(const City *city1, const City *city2);
void copyLocation(City *destCity, const City *srcCity);
bool hasAirport(City *city);
bool isEqual(const City *city, const City *city2);
void readAirport(City *city, char *line);
void readCity(City *city, istream &fp);
void setAirport(City *city, const char *airport);
#endif	// CITY_H 

