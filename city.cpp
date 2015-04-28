#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "city.h"
using namespace std;

void initialize(City *city)
{
  city->name = NULL;
  city->state = NULL;
  city->airport[0] = '\0';  // sentinel value
}  // initialize()


void deallocate(City *city)
{
  if (city->name)
    delete[] city->name;
    
  if (city->state)
    delete[] city->state;
    }  // deallocate()


void calcDistance(const City *city1, const City *city2)
{
  int distance, passengers;
  
  passengers = (double) city1->population * city2->population / 250000000;
  distance = acos(
    sin(city1->latitude * M_PI / 180) * sin(city2->latitude * M_PI / 180) 
    + cos(city1->latitude * M_PI / 180) * cos(city2->latitude * M_PI / 180)
    * cos((city1->longitude - city2->longitude) * M_PI / 180)) * 3963;
  
  if (distance < 100)
    passengers = 0;
  cout << passengers << " passengers fly the " << distance << " miles from\n" << city1->name << "," << city1->state << " to " << city2->name << "," << city2->state << endl;
  //printf("%d passengers fly the %d miles from\n%s,%s to %s,%s\n", passengers,
  //  distance, city1->name, city1->state, city2->name, city2->state);
  
}  // calcDistance())

void copyLocation(City *destCity, const City *srcCity)
{
  strcpy(destCity->airport, srcCity->airport);
  destCity->latitude = srcCity->latitude;
  destCity->longitude = srcCity->longitude;
}  // copyLocation()


bool hasAirport(City *city)
{
  return city->airport[0] != '\0';
}  // hasAirport()


bool isEqual(const City *city, const City *city2)
{
  if (city->name && city2->name)
    return strcmp(city->name, city2->name) == 0;
  
  if (city->airport[0] && city2->airport[0])
    return strcmp(city->airport, city2->airport) == 0;
  
  return false;
}  // isName()


void readCity(City *city, istream &fp)
{
  char line[1000], *ptr;
  if (!fp.getline(line, 1000))
  return;
  
  ptr = strtok(line, ",");
  
  if (ptr)
  {  
    city->name = new char [strlen(ptr) + 1];
    strcpy(city->name, ptr);
    ptr = strtok(NULL, ",");
    city->state = new char [strlen(ptr) + 1];
    strcpy(city->state, ptr);
    city->population = atoi(strtok(NULL, ",\n"));
  } // if something on line
}  // readCity()

void readAirport(City *city, char *line)
{
  char *ptr;
  
  strtok(line, "] ");
  strcpy(city->airport, &line[1]);
  city->latitude = atof(strtok(NULL, " "));
  city->longitude = atof(strtok(NULL, " "));
  ptr = strtok(NULL, ",") + 1;
  city->name = new char [strlen(ptr) + 1];
  strcpy(city->name, ptr);
}  // readAirport


void setAirport(City *city, const char *airport)
{
  strcpy(city->airport, airport);
}  // setAirport()
