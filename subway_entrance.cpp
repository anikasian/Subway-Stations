#include "subway_entrance.h"

Subway_Entrance::Subway_Entrance(const string & subwaydata) {
   stringstream ss(subwaydata);
   vector<string> vec;
   string token;


   while (getline(ss, token)) {
      /*
         isQuote is FALSE if 
            1) a quotation mark hasn't been read or 
            2) the quotation mark and its ending pair has been read.
         isQuote is TRUE if there has only been one quotation mark read before 
            we read its pair.
      */
      string item;
      bool isQuote = false;
      /*
         Char pointer i will iterate through the string.
         
         If the pointer lands on a quotation mark, it will check:
            1) if isQuote is FALSE, then it will check if its next quote is
         a quotation mark. If yes, store the string in item. If not, keep going.
         
         If the pointer lands on a comma and isQuote is TRUE then it will add
         the string to item and add item to the vector. Clear item so it can collect
         a new string from token.

         If the the pointer lands on a comma & isQuote is FALSE then it will
         add whatever item accumilated to the vector.  

      */
      for (const char *i = token.c_str(); *i; ++i) {
         if (*i == '"') {
            if (isQuote) {
               if (i[1] == '"')
                  item += *++i;
               else
                  isQuote = false;
            }
            else
            isQuote = true;
         }  
         else if (*i == ',' && !isQuote) {
            vec.push_back(item);
            item.clear();
         }
         else
            item += *i;
      }
      vec.push_back(item);
   }

   /////////////////// Initializing my private members ///////////////////

   _subwayName = vec.at(2);
  
   // Converting the lines into a 32-bit binary number.
   _lineStrings = vec.at(4);
   _line = assignBits(_lineStrings);


   // Parsing through POINTS (long, lat) string.
   istringstream iss(vec.at(3));
   vector<string> stringParse;
   string tkn;
   while(iss >> tkn)
      stringParse.push_back(tkn);

   string temp = stringParse.at(2);
   // Erasing the last paranthesis from the lat number.
   string latStr = temp.erase(temp.size() - 1);

   double latitude, longitude;
   // Converting the strings to doubles.
   longitude = stod((stringParse.at(1)).c_str(), 0);
   latitude = stod(latStr.c_str(), 0);

   // Setting the coords to _theGeom.
   _theGeom.setCoords(latitude, longitude);

}


unsigned long Subway_Entrance::assignBits(string line) const {
   // Separate the lines from the dashses.
   stringstream ss(line);
   vector<string> vec;

   while (ss.good()) {
      string tempstr;
      getline(ss, tempstr, '-');
      vec.push_back(tempstr);
   }

   // Starting off with all 0s.
   unsigned long totalBits = 1UL << -1;

   // Updating totalBits with letter lines.
   for (int i = 0; i < vec.size(); ++i) {
      if (vec[i] == "1") {
         unsigned long mask_k = 1UL << 1;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "2") {
         unsigned long mask_k = 1UL << 2;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "3") {
         unsigned long mask_k = 1UL << 3;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "4") {
         unsigned long mask_k = 1UL << 4;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "5") {
         unsigned long mask_k = 1UL << 5;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "6") {
         unsigned long mask_k = 1UL << 6;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "7") {
         unsigned long mask_k = 1UL << 7;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "A") {
         unsigned long mask_k = 1UL << 8;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "B") {
         unsigned long mask_k = 1UL << 9;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "C") {
         unsigned long mask_k = 1UL << 10;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "D") {
         unsigned long mask_k = 1UL << 11;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "E") {
         unsigned long mask_k = 1UL << 12;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "F") {
         unsigned long mask_k = 1UL << 13;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "G") {
         unsigned long mask_k = 1UL << 14;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "J") {
         unsigned long mask_k = 1UL << 15;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "L") {
         unsigned long mask_k = 1UL << 16;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "M") {
         unsigned long mask_k = 1UL << 17;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "N") {
         unsigned long mask_k = 1UL << 18;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "Q") {
         unsigned long mask_k = 1UL << 19;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "R") {
         unsigned long mask_k = 1UL << 20;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "S") {
         unsigned long mask_k = 1UL << 21;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "W") {
         unsigned long mask_k = 1UL << 22;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "Z") {
         unsigned long mask_k = 1UL << 23;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "GS") {
         unsigned long mask_k = 1UL << 24;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "SIR") {
         unsigned long mask_k = 1UL << 25;
         totalBits = (totalBits | mask_k);
      }
      else if (vec[i] == "FS") {
         unsigned long mask_k = 1UL << 26;
         totalBits = (totalBits | mask_k);
      }
   }

   return totalBits;

}