#include "subway_line_hash.h"

Subway_Line_Hash::~Subway_Line_Hash() {
   // Clearing all the contents in each list.
   for (int i = 0; i < lineHashTable.size(); ++i)
      lineHashTable.at(i).clear();

   // Clearing the vector of lists.
   lineHashTable.clear();
}


void Subway_Line_Hash::setHash(vector<list<Subway_Entrance*>> listOfStations) {
   // Creating 26 cells since the MTA has 26 lines.
   for (int i = 0; i < 26; ++i) {
      list<Subway_Entrance*> newCell;
      lineHashTable.push_back(newCell);
   }

   // Using bitwise ops to see if the station is stations 1-7, A-Z, SIR, GS & FS
   // If the op doesn't return a 0, it is in that station.
   for (int i = 0; i < listOfStations.size(); ++i) {
      unsigned long checkBits = listOfStations[i].front()->getLineBitmask();

      // If station has a 1 line.
      if ((checkBits & (1UL << 1)) == (1UL << 1)) {
         lineHashTable[0].push_back(listOfStations[i].front());
      }

      // If station has a 2 line.
      if ((checkBits & (1UL << 2)) == (1UL << 2)) {
         lineHashTable[1].push_back(listOfStations[i].front());
      }

      // If station has a 3 line.
      if ((checkBits & (1UL << 3)) == (1UL << 3)) {
         lineHashTable[2].push_back(listOfStations[i].front());
      }

      // If station has a 4 line.
      if ((checkBits & (1UL << 4)) == (1UL << 4)) {
         lineHashTable[3].push_back(listOfStations[i].front());
      }

      // If station has a 5 line.
      if ((checkBits & (1UL << 5)) == (1UL << 5)) {
         lineHashTable[4].push_back(listOfStations[i].front());
      }

      // If station has a 6 line.
      if ((checkBits & (1UL << 6)) == (1UL << 6)) {
         lineHashTable[5].push_back(listOfStations[i].front());
      }

      // If station has a 7 line.
      if ((checkBits & (1UL << 7)) == (1UL << 7)) {
         lineHashTable[6].push_back(listOfStations[i].front());
      }

      // If station has an A line.
      if ((checkBits & (1UL << 8)) == (1UL << 8)) {
         lineHashTable[7].push_back(listOfStations[i].front());
      }

      // If station has a B line.
      if ((checkBits & (1UL << 9)) == (1UL << 9)) {
         lineHashTable[8].push_back(listOfStations[i].front());
      }

      // If station has a C line.
      if ((checkBits & (1UL << 10)) == (1UL << 10)) {
         lineHashTable[9].push_back(listOfStations[i].front());
      }

      // If station has a D line.
      if ((checkBits & (1UL << 11)) == (1UL << 11)) {
         lineHashTable[10].push_back(listOfStations[i].front());
      }

      // If station has an E line.
      if ((checkBits & (1UL << 12)) == (1UL << 12)) {
         lineHashTable[11].push_back(listOfStations[i].front());
      }

      // If station has a F line.
      if ((checkBits & (1UL << 13)) == (1UL << 13)) {
         lineHashTable[12].push_back(listOfStations[i].front());
      }

      // If station has a G line.
      if ((checkBits & (1UL << 14)) == (1UL << 14)) {
         lineHashTable[13].push_back(listOfStations[i].front());
      }

      // If station has a J line.
      if ((checkBits & (1UL << 15)) == (1UL << 15)) {
         lineHashTable[14].push_back(listOfStations[i].front());
      }

      // If station has an L line.
      if ((checkBits & (1UL << 16)) == (1UL << 16)) {
         lineHashTable[15].push_back(listOfStations[i].front());
      }

      // If station has an M line.
      if ((checkBits & (1UL << 17)) == (1UL << 17)) {
         lineHashTable[16].push_back(listOfStations[i].front());
      }

      // If station has a N line.
      if ((checkBits & (1UL << 18)) == (1UL << 18)) {
         lineHashTable[17].push_back(listOfStations[i].front());
      }

      // If station has a Q line.
      if ((checkBits & (1UL << 19)) == (1UL << 19)) {
         lineHashTable[18].push_back(listOfStations[i].front());
      }

      // If station has a R line.
      if ((checkBits & (1UL << 20)) == (1UL << 20)) {
         lineHashTable[19].push_back(listOfStations[i].front());
      }

      // If station has a S line.
      if ((checkBits & (1UL << 21)) == (1UL << 21)) {
         lineHashTable[20].push_back(listOfStations[i].front());
      }

      // If station has a W line.
      if ((checkBits & (1UL << 22)) == (1UL << 22)) {
         lineHashTable[21].push_back(listOfStations[i].front());
      }

      // If station has a Z line.
      if ((checkBits & (1UL << 23)) == (1UL << 23)) {
         lineHashTable[22].push_back(listOfStations[i].front());
      }

      // If station has a GS line.
      if ((checkBits & (1UL << 24)) == (1UL << 24)) {
         lineHashTable[23].push_back(listOfStations[i].front());
      }

      // If station has a SIR line.
      if ((checkBits & (1UL << 25)) == (1UL << 25)) {
         lineHashTable[24].push_back(listOfStations[i].front());
      }

      // If station has a FS line.
      if ((checkBits & (1UL << 26)) == (1UL << 26)) {
         lineHashTable[25].push_back(listOfStations[i].front());
      }
   } // endof for-loop
}


void Subway_Line_Hash::printStationsInLine(string line) const {

   // Checking which bits the line belongs to.
   int indexOfCell = 0;
   if (line == "1") 
      indexOfCell = 0;
   else if(line == "2")
      indexOfCell = 1;
   else if(line == "3")
      indexOfCell = 2;
   else if(line == "4")
      indexOfCell = 3;
   else if(line == "5")
      indexOfCell = 4;
   else if(line == "6")
      indexOfCell = 5;
   else if(line == "7")
      indexOfCell = 6;
   else if(line == "A")
      indexOfCell = 7;
   else if(line == "B")
      indexOfCell = 8;
   else if(line == "C")
      indexOfCell = 9;
   else if(line == "D")
      indexOfCell = 10;
   else if(line == "E")
      indexOfCell = 11;
   else if(line == "F")
      indexOfCell = 12;
   else if(line == "G")
      indexOfCell = 13;
   else if(line == "J")
      indexOfCell = 14;
   else if(line == "L")
      indexOfCell = 15;
   else if(line == "M")
      indexOfCell = 16;
   else if(line == "N")
      indexOfCell = 17;
   else if(line == "Q")
      indexOfCell = 18;
   else if(line == "R")
      indexOfCell = 19;
   else if(line == "S")
      indexOfCell = 20;
   else if(line == "W")
      indexOfCell = 21;
   else if(line == "Z")
      indexOfCell = 22;
   else if(line == "GS")
      indexOfCell = 23;
   else if(line == "SIR")
      indexOfCell = 24;
   else if(line == "FS")
      indexOfCell = 25;

   // Find the cell in the list hash table and print all of its contents.
   list<Subway_Entrance*>::const_iterator it;
      for (it = lineHashTable[indexOfCell].begin(); it != lineHashTable[indexOfCell].end(); ++it)
          cout << (*it)->getSubwayName() << endl; 
}