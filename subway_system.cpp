#include "subway_system.h"

Subway_System::~Subway_System() { 
   for (int i = 0; i < _system.size(); ++i)
      delete _system.at(i);
   _system.clear();
}

void Subway_System::insert(Subway_Entrance & obj) {
   Subway_Entrance * temp = new Subway_Entrance(obj);
   int checkSet = isPartOfSet(temp);
   if(checkSet == -1) {
      _system.push_back(temp);
      _system.at(_system.size() - 1)->setArrIndex(_system.size() - 1);
   }
   else {
      temp->setNodeNum(checkSet);
      int currNodeNum = _system.at(checkSet)->getNodeNum();
      _system.at(checkSet)->setNodeNum(currNodeNum - 1);
      _system.push_back(temp);
      _system.at(_system.size() - 1)->setArrIndex(_system.size() - 1);
   }
}


void Subway_System::createHashes() {
   stations.setHash(_system);
   lines.setHash(stations.getHash());
}


int Subway_System::isPartOfSet(Subway_Entrance * obj) {
   if(_system.empty())
      return -1;

   double min = .28;

   for (int i = 0; i < _system.size(); ++i) {
      // Checks if the OR of the two bitmask equals itself and if the distance between two stations is less than .28
      if (((obj->getLineBitmask() | _system.at(i)->getLineBitmask()) == _system.at(i)->getLineBitmask())
          && haversine(obj->getLat(), obj->getLong(), _system.at(i)->getLat(), _system.at(i)->getLong()) <= min) {
         // returns index of the station that belongs with obj's station.
         return i;
      }
   }

   // If there is no other node matching this one, keep it -1.
   return -1;
}


void Subway_System::findNearestStation(double lat, double lng) {
   if (lng > 0)
      lng *= -1;
   double minDistance = haversine(_system[0]->getLat(), _system[0]->getLong(), lat, lng);
   int index = 0;
   for (int i = 1; i < _system.size(); ++i) {
      if (minDistance > haversine(_system[i]->getLat(), _system[i]->getLong(), lat, lng)) {
         minDistance = haversine(_system[i]->getLat(), _system[i]->getLong(), lat, lng);
         index = i;
      }
   }
   int parentIndex = _system[index]->getNodeNum();

   cout << "The closest station to point (" << lng << "," << lat << ") is ";
   if (parentIndex < 0)
      cout << _system[index]->getSubwayName();
   else
      cout << _system[parentIndex]->getSubwayName();
}


void Subway_System::findNearestLine(double lat, double lng) {
   if (lng > 0)
      lng *= -1;
   double minDistance = haversine(_system[0]->getLat(), _system[0]->getLong(), lat, lng);
   int index = 0;
   for (int i = 1; i < _system.size(); ++i) {
      if (minDistance > haversine(_system[i]->getLat(), _system[i]->getLong(), lat, lng)) {
         minDistance = haversine(_system[i]->getLat(), _system[i]->getLong(), lat, lng);
         index = i;
      }
   }

   string temp = _system[index]->getLineStrings();
   transform(temp.begin(), temp.end(), temp.begin(), [](char ch) { return ch == '-' ? ' ' : ch; });

   cout << "The closest subway line to point (" << lng << "," << lat << ") is the ";
   cout << temp;
}


void Subway_System::findNearestEntrance(double lat, double lng) {
   if (lng > 0)
      lng *= -1;
   double minDistance = haversine(_system[0]->getLat(), _system[0]->getLong(), lat, lng);
   int index = 0;
   for (int i = 1; i < _system.size(); ++i) {
      if (minDistance > haversine(_system[i]->getLat(), _system[i]->getLong(), lat, lng)) {
         minDistance = haversine(_system[i]->getLat(), _system[i]->getLong(), lat, lng);
         index = i;
      }
   }
   cout << "The closest entrance to point (" << lng << "," << lat << ") is ";
   cout << _system[index]->getSubwayName();
}


double Subway_System::haversine(double lat1, double lon1, double lat2, double lon2) {
      lat1 = TO_RAD * lat1;
      lat2 = TO_RAD * lat2;
      lon1 = TO_RAD * lon1;
      lon2 = TO_RAD * lon2;
      double dLat = (lat2 - lat1)/2;
      double dLon = (lon2 - lon1)/2;
      double a = sin(dLat);
      double b = sin(dLon);
      return 2 * R * asin(sqrt(a * a + cos(lat1) * cos(lat2) * b * b));
}