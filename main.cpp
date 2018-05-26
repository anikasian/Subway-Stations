#include "subway_system.h"

int main(int argc, char *argv[]) {
   ifstream csvFile, commandFile;
   string line;

   if (argc > 3) {
      cout << "Usage: " <<  argv[0] << " csvfile.csv commandfile" << endl;
      exit(1);
   }
   else if (argc < 3) {
      cout << "Usage: " <<  argv[0] << " csvfile.csv commandfile" << endl;
      exit(1);
   }
   else {
      csvFile.open(argv[1]);
      commandFile.open(argv[2]);

      // Checking if the csv and command files are able to open.
      if (!csvFile.is_open()) {
         cout << "Could not open " << argv[1] << endl;
         exit(1);
      }     
      if (!commandFile.is_open()) {
         cout << "Could not open " << argv[2] << endl;
         exit(1);
      }

      Subway_System subSystem;
      while(getline(csvFile, line)) {
         Subway_Entrance subwayStr(line);
         subSystem.insert(subwayStr);
      }

      subSystem.createHashes();

      // Expected commands
      string lineSt("list_line_stations"); // line
      string allSt("list_all_stations"); 
      string entr("list_entrances"); // station_name
      string nearSt("nearest_station"); // long lat
      string nearLine("nearest_lines");  // long lat
      string nearEntr("nearest_entrance"); // long lat
      
      while(getline(commandFile, line)) {

         // If line contains 'list_line_stations'.
         if (line.find(lineSt) != string::npos) {
            string tempLine;

            // Removing extra whitespace.
            unique_copy (line.begin(), line.end(), back_insert_iterator<string>(tempLine), [](char a,char b){ return isspace(a) && isspace(b);});
            string lineRequest = tempLine.substr(19, string::npos);

            cout << endl;
            cout << endl;
            cout << "Stations of the " << lineRequest << " line:" << endl;
            subSystem.printStationsInLine(lineRequest);

            // Clearing strings.
            tempLine.clear();
            lineRequest.clear();

         }

         // If line contains 'list_all_stations'.
         else if (line.find(allSt) != string::npos) {
            cout << endl;
            cout << endl;
            subSystem.printAllStations();
         }

         // If line contains 'list_entrances'.
         else if (line.find(entr) != string::npos) {
            string tempLine;

            // Removing extra whitespace.
            unique_copy (line.begin(), line.end(), back_insert_iterator<string>(tempLine), [](char a,char b){ return isspace(a) && isspace(b);});
            string locRequest = tempLine.substr(15, string::npos);

            cout << endl;
            cout << endl;
            cout << "Entrances at station \"" << locRequest << "\":" << endl;
            subSystem.printEntrancesAtStation(locRequest);

            // Clearing strings.
            tempLine.clear();
            locRequest.clear();
         }

         // If line contains 'nearest_station'.
         else if (line.find(nearSt) != string::npos) {
            string stLine;
            double latRequest;
            double lngRequest;

            // Removing extra whitespace.
            unique_copy (line.begin(), line.end(), back_insert_iterator<string>(stLine), [](char a,char b){ return isspace(a) && isspace(b);});
            string coordRequest = stLine.substr(17, string::npos);

            // Grabbing the string after the command which should be LONG LAT.
            istringstream iss(coordRequest);
            iss >> lngRequest;
            iss >> latRequest;

            cout << endl;
            subSystem.findNearestStation(latRequest, lngRequest);
            cout << endl;

            // Clearing strings.
            stLine.clear();
            iss.str("");
         }

         // If line contains 'nearest_lines'.
         else if (line.find(nearLine) != string::npos) {
            string l_Line;
            double latRequest;
            double lngRequest;

            // Removing extra whitespace.
            unique_copy (line.begin(), line.end(), back_insert_iterator<string>(l_Line), [](char a,char b){ return isspace(a) && isspace(b);});
            string coordRequest = l_Line.substr(14, string::npos);

            // Grabbing the string after the command which should be LONG LAT.
            istringstream ss(coordRequest);
            ss >> lngRequest;
            ss >> latRequest;

            cout << endl;          
            subSystem.findNearestLine(latRequest, lngRequest); 
            cout << endl;
            
            // Clearing strings.
            l_Line.clear();
            ss.str("");
         }

         // If line contains 'nearest_entrance'.
         else if (line.find(nearEntr) != string::npos) {
            string entrLine;
            double latRequest;
            double lngRequest;

            // Removing extra whitespace.
            unique_copy (line.begin(), line.end(), back_insert_iterator<string>(entrLine), [](char a,char b){ return isspace(a) && isspace(b);});
            string coordRequest = entrLine.substr(17, string::npos);

            // Grabbing the string after the command which should be LONG LAT.
            istringstream ssi(coordRequest);
            ssi >> lngRequest;
            ssi >> latRequest;

            cout << endl;
            subSystem.findNearestEntrance(latRequest, lngRequest);
            cout << endl;

            // Clearing strings.
            entrLine.clear();
            ssi.str("");
         }

      } //end while-loop
  
   }

}