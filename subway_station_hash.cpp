#include "subway_station_hash.h"

Subway_Station_Hash::~Subway_Station_Hash() {
   // Clearing all the contents in each list.
   for (int i = 0; i < subHashTable.size(); ++i)
      subHashTable.at(i).clear();

   // Clearing the vector of lists.
   subHashTable.clear();
}


void Subway_Station_Hash::setHash(vector<Subway_Entrance*> vec) {
   for (int i = 0; i < vec.size(); ++i) {
      // If the node's number is a negative number, it is a parent node of a set.
      if (vec.at(i)->getNodeNum() < 0) {
         list<Subway_Entrance*> newCell;
         newCell.push_back(vec.at(i));
         subHashTable.push_back(newCell);
      }
      // If node's number is not -1, it is part of a set.
      else {
         // Iterating through all lists in the vector to assign the subwaystation to its set. 
         for(int j = 0; j < subHashTable.size(); ++j)
            // Only need to check the front() of the list since it will be the parent node.
            if(subHashTable.at(j).front()->getArrIndex() == vec.at(i)->getNodeNum())
               subHashTable.at(j).push_back(vec.at(i));
      }
   } // endof for-loop
}

void Subway_Station_Hash::printAllStations() const {
   cout << "All " << subHashTable.size() << " stations:" << endl;
   for (size_t i = 0; i < subHashTable.size(); ++i)
      cout << subHashTable.at(i).front()->getSubwayName() << endl;
}


void Subway_Station_Hash::printEntrancesAtStation(string station) const{
   string exitOnly("(exit only)");

   for(int i = 0; i < subHashTable.size(); ++i) {
      // Looking for the hash key that matches the 'station'.
      if(subHashTable[i].front()->getSubwayName() == station) {
         // Iterate through that list.
         list<Subway_Entrance*>::const_iterator it;
         for (it = subHashTable[i].begin(); it != subHashTable[i].end(); ++it) {
            string temp = (*it)->getSubwayName();

            // If the string doesn't contains "(exit only)", print.
            if (temp.find(exitOnly) == string::npos)
               cout << (*it)->getSubwayName() << endl; 

         } // endof list for-loop
      }
   } // endof vector for-loop
}