/******************************************************************************************

  Processing MTA Subway Entrance Data

   Title:         subway_station_hash.h
   Author:        Anika Sian
   Created on:    5/12/18
   Description:   Creating a hashtable with all of Subway_Entrance objects and their keys
                  being the station with all of its entrances.
   Purposes:      To define all stations in MTA.
   Build with:    Use Makefile from zipfile.
   Modifications: 5/13/18 -- Changed functions so Subway_System can call them and to
                             better encapsulate the Subway_Station_Hash object.

******************************************************************************************/


#ifndef ___SUBWAY_STATION_HASH_H___
#define ___SUBWAY_STATION_HASH_H___

#include "subway_entrance.h"

class Subway_Station_Hash {
public:

   /** Constructor.
    * @Pre:  None.
    * @Post: Object has been created.
    */
   Subway_Station_Hash() {}

   /** Destructor.
    * @Pre:  Object must have been created.
    * @Post: Clears all nodes in list and clears all entries in vector.
    */
   ~Subway_Station_Hash();

   /** Inserts all of the Subway_Entrance objects from Subway_System into
    *  the Subway_Station_Hash's hashtable. Keys are now the main stations and
    *  their nodes are all the entrances and exits in the station.
    * @Pre:  Subway_System array must have been created.
    * @Post: The hashtable has been rearranged with its keys as stations.
    * @Param vec: The array representation of parent tree from Subway_System.
    */
   void setHash(vector<Subway_Entrance*> vec);

   /** Returns the vector representing the hashtable.
    * @Pre:  There must be entries in the hashtable.
    * @Post: Returns subHashTable.
    */
   vector<list<Subway_Entrance*>> getHash() { return subHashTable; }

   /** Prints all the stations in the MTA.
    * @Pre:  There must be negative numbers in the Subway_System array. That
    *        declares that the entrance is actually the parent of a set.
    * @Post: Prints all names of entries with a negative nodeNum.
    */
   void printAllStations() const;

   /** Prints all the entrances in a station.
    * @Pre:  Station must exist.
    * @Post: Prints all the nodes in the index of the vector. Index is representing
    *        the name of the requested subway station.
    * @Param station: Requested station.
    */
   void printEntrancesAtStation(string station) const;
   
private:
   vector<list<Subway_Entrance*>> subHashTable;
};


#endif // ___SUBWAY_STATION_HASH_H___