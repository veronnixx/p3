#include <iostream>
using namespace std; 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void run(const Vector *cities)
{
  char airport1[80], airport2[80];
  int index1, index2;
  
  while (1)
  {
    cout << "\nPlease enter two airport abbreviations (XXX XXX = done): ";
//    printf("\nPlease enter two airport abbreviations (XXX XXX = done): ");
    cin >> airport1 >> airport2;
//    scanf("%s %s", airport1, airport2);
    
    if (strcmp(airport1, "XXX") == 0 && strcmp(airport2, "XXX") == 0)
      break;
    
    index1 = findAirport(cities, airport1);
    index2 = findAirport(cities, airport2);
    
    if (index1 >= 0 && index2 >= 0)
      calcDistance(cities, index1, index2);
  }  // infinite while loop
}  // run())


int main(int argc, char** argv) 
{
  Vector cities;
  initialize(&cities);
  readCities(&cities);
  readAirports(&cities);
  cleanCities(&cities);
  run(&cities);
  deallocate(&cities);
  return 0;
} // main()

