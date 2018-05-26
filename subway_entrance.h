/******************************************************************************************

   Processing MTA Subway Entrance Data

   Title:         subway_entrance.h
   Author:        Anika Sian
   Created on:    5/10/18
   Description:   Creating a Subway_Entrance object with its subway name and lines.
   Purposes:      To define all subway stops.
   Build with:    Use Makefile from zipfile.
   Modifications: 5/12/18 -- Figured out how to use bitmasks. Created a new private 
                             member that has the bitmask representation of the lines.
                          -- Added _node to represent each vector index as a parent
                             node or the index to its parent node.
                  5/13/18 -- Added _arrIndex to better keep track of the parent node's
                             location in the vector. Easier for me to access the
                             Subway_Entrance object.

******************************************************************************************/


#ifndef ___SUBWAY_ENTRANCE_H___
#define ___SUBWAY_ENTRANCE_H___

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>  // For haversine function.
using namespace std;

struct Coords {

   /** Coords constructor.
    * @Pre:  None.
    * @Post: Creating an empty Coords object.
    */
   Coords() {}

   /** Assigns the private members their data.
    * @Pre:  Coords must've been created.
    * @Post: private members now have the lat and long doubles.
    */
   void setCoords(double lat, double lng) {
      _lat = lat;
      _lng = lng;
   }

   /** Returns the latitude.
    * @Pre:  None.
    * @Post: Returns _lat.
    */
   double getLat() const { return _lat; }

   /** Returns the longitude.
    * @Pre:  None.
    * @Post: Returns _lng;
    */
   double getLong() const { return _lng; }

   double _lat;
   double _lng;
};


class Subway_Entrance {
public:

   /** Subway_Entrance constructor with one param
    * @Pre:  String must have been read from the .csv file.
    * @Post: Subway_Entrance object has been created.
    */
   Subway_Entrance(const string & subwaydata);

   /** Helper functions to turn the entrance's lines into its bitmask respresentation
    *  and assign that bitmask num to the private member _line.
    * @Pre:  Subway_Entrance must have at least one line.
    * @Post: An unsigned long number has been assigned to _line.
    */
   unsigned long assignBits(string line) const;


   ////////////////////////////////   SETTERS   ////////////////////////////////////

   /** Sets the node of an entrance.
    * @Pre:  None.
    * @Post: Either the entrance's node is a negative number (it's a parent node)
    *        or it's a positive number (child or entry in a set).
    */
   void setNodeNum(int node) { _node = node; }

   /** Stores an index of each entrance object.
    * @Pre:  None.
    * @Post: Each entrance will have an index.
    */
   void setArrIndex(int index) { _arrIndex = index; }


   ////////////////////////////////   GETTERS   ////////////////////////////////////

   /** Returns the index of the subway entrance.
    * @Pre:  None.
    * @Post: Returns _arrIndex.
    */
   int getArrIndex() const { return _arrIndex; }

   /** Returns the node number of the entrance.
    * @Pre:  None.
    * @Post: Returns _node and it could be negative or positive.
    */
   int getNodeNum() const { return _node; }

   /** Returns the name of the subway entrance.
    * @Pre:  None.
    * @Post: Returns _subwayName.
    */
   string getSubwayName() const { return _subwayName; }

   /** Returns the latitude of the subway entrance.
    * @Pre:  None.
    * @Post: Returns _lat from Coords object.
    */
   double getLat() const { return _theGeom.getLat(); }

   /** Returns the longitude of the subway entrance.
    * @Pre:  None.
    * @Post: Returns _lng from Coords object.
    */
   double getLong() const { return _theGeom.getLong(); }

   /** Returns the lines string from the .csv file.
    * @Pre:  None.
    * @Post: Returns the last string after the comma from .csv file.
    */
   string getLineStrings() const { return _lineStrings; }

   /** Returns the bitmask representation of the entrance's line.
    * @Pre:  None.
    * @Post: Returns _line.
    */
   unsigned long getLineBitmask() const { return _line; }


private:
   int _arrIndex = 0;
   int _node = -1;
   string _subwayName;
   Coords _theGeom;
   string _lineStrings;
   unsigned long _line;
};


#endif // ___SUBWAY_ENTRANCE_H___
