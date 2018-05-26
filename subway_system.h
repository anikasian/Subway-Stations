/******************************************************************************************

   Processing MTA Subway Entrance Data

   Title:         subway_system.h
   Author:        Anika Sian
   Created on:    5/10/18
   Description:   To organize all the subway_entrances into a set of subway stations and
                  subway lines. 
   Purposes:      To interact with the command file and output results.
   Build with:    Use Makefile from zipfile.
   Modifications: 5/13/18 -- Changed functions so Subway_System can access the two hash
                             tables and to better encapsulate the Subway_Station_Hash and
                             Subway_Line_Hash objects.
                          -- Fixed the issue where the longitude doubles were not negative.

******************************************************************************************/


#ifndef ___SUBWAY_SYSTEM_H___
#define ___SUBWAY_SYSTEM_H___

#include "subway_line_hash.h"

const double R = 6372.8;
const double TO_RAD = M_PI / 180.0;

class Subway_System {
public:

   /** Constructor.
    * @Pre:  None.
    * @Post: An object is created.
    */
   Subway_System() {}

   /** Destructor.
    * @Pre:  Subway_System object must've been created.
    * @Post: All pointers in the vector have been deleted and the vector is cleared.
    */
   ~Subway_System();

   /** Returns the Subway_System array.
    * @Pre:  Must be entries in the array meaning that the .csv file must've been read.
    * @Post: Returns _system.
    */
   vector<Subway_Entrance*> getVector() { return _system; }

   /** Insert Subway_Entrance into _system array, check if it belongs in a set and change
    *  its nodeNum to either a negative number or the index to the set it belongs to.
    * @Pre:  None.
    * @Post: Object has been inserted.
    * @Param obj: Subway_Entrance object that's being inserted.
    */
   void insert(Subway_Entrance & obj);

   /** Creates the hashtables for Subway_Station_Hash and Subway_Line_Hash.
    * @Pre:  All entrances have been inserted into the _system array.
    * @Post: setHash() function has been called for both hashes.
    */
   void createHashes();

   /** Helper function for insert() to check if the current object being inserted is
    *  part of any set.
    * @Pre:  None.
    * @Post: Returns a -1 if the entrance is not part of a set and an index if it is part
    *        of a set.
    * @Param obj: Subway_Entrance pointer that being checked on.
    */
   int isPartOfSet(Subway_Entrance * obj);

   /** Prints all the stations from the .csv file.
    * @Pre:  Subway_Station_Hash must've been created and its hash table must've been filled.
    * @Post: Calls the Subway_Station_Hash's printAllStations() function.
    */
   void printAllStations() const { stations.printAllStations(); }

   /** Prints all stations in a specific MTA line.
    * @Pre:  Subway_Line_Hash must've been created & its hashtable must've been filled.
    * @Post: Calls the Subway_Line_Hash's printStationsInLine(line) function.
    * @Param line: MTA line requested to print.
    */
   void printStationsInLine(string line) const { lines.printStationsInLine(line); }

   /** Prints all the entrances at a given station. This excludes exits.
    * @Pre:  Subway_Station_Hash must've been created and its hastable must've been filled.
    * @Post: Calls the Subway_Station_Hash's printEntrancesAtStation(station).
    * @Param station: Requested station to be printed.
    */
   void printEntrancesAtStation(string station) const { stations.printEntrancesAtStation(station); }

   /** Prints out the closest station to the given coordinates.
    * @Pre:  Subway_System array must've been created and filled.
    * @Post: Returns the station name of the closest station to the coordinates.
    */
   void findNearestStation(double lat, double lng);

   /** Prints out the line of the closest entrance to the given coordinates.
    * @Pre:  Subway_System array must've been created and filled.
    * @Post: Returns the line of the closest entrance to the coordinates.
    */
   void findNearestLine(double lat, double lng);

   /** Prints out the closest entrance to the given coordinates.
    * @Pre:  Subway_System array must've been created and filled.
    * @Post: Returns the entrance name closest to the given coordinates.
    */
   void findNearestEntrance(double lat, double lng);

   /** Computes an approximate distance between two coordinates (took this func from 
    *  the Assignment 3 PDF).
    * @Pre:  None.
    * @Post: Distance in double.
    */
   double haversine(double lat1, double lon1, double lat2, double lon2);

private:
   vector<Subway_Entrance*> _system;
   Subway_Station_Hash stations;
   Subway_Line_Hash lines;
};

#endif // ___SUBWAY_SYSTEM_H___