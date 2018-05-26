/******************************************************************************************

   Processing MTA Subway Entrance Data

   Title:         subway_line_hash.h
   Author:        Anika Sian
   Created on:    5/12/18
   Description:   Creating a hashtable with all of the Subway_Entrance objects where they
                  keys are all of the subway lines.
   Purposes:      To define all stops per line.
   Build with:    Use Makefile from zipfile.
   Modifications: 5/13/18 -- Changed functions so Subway_System can call them and to
                             better encapsulate the Subway_Line_Hash object.
                          -- Added one more line. Found that 'FS' is a line.

******************************************************************************************/


#ifndef ___SUBWAY_LINE_HASH_H___
#define ___SUBWAY_LINE_HASH_H___

#include "subway_station_hash.h"

class Subway_Line_Hash {
public:

   /** Constructor.
    * @Pre:  None.
    * @Post: Initializes an object.
    */
   Subway_Line_Hash() {}

   /** Destructor.
    * @Pre:  There must be entries in the hashtable.
    * @Post: Clears all the list entries and then clears the vector's entries.
    */
   ~Subway_Line_Hash();

   /** Inserts all of the Subway_Entrance objects from Subway_Station_Hash into
    *  the Subway_Line_hash's hashtable. Keys are now subway lines and the nodes
    *  for each key are the stations belonging to that MTA line.
    * @Pre:  Subway_Station_Hash must have been created.
    * @Post: The hashtable has been rearranged with its keys as lines and nodes
    *        are Subway_Entrance objects.
    * @Param listOfStations: The hashtable from Subway_Station_Hash.
    */
   void setHash(vector<list<Subway_Entrance*>> listOfStations);

   /** Prints all the subway stations in the specified MTA line.
    * @Pre:  None.
    * @Post: Prints all of the Subway_Entrance objects in specified key.
    * @Param line: Requested line to print.
    */
   void printStationsInLine(string line) const;

private:
   // According to the dataset, there are 26 lines.
   vector<list<Subway_Entrance*>> lineHashTable;
};


#endif // ___SUBWAY_LINE_HASH_H___