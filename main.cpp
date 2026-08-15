
#include <iostream>
#include "Headers/ParkingClass.h"

   

int main() {

    ParkingClass parkingClass;
    parkingClass.displayParking();
    std::pair<std::pair<uint8_t, uint8_t>, std::pair<uint8_t, uint8_t>>  p = parkingClass.findTheCarToPark();
    std::cout << "x " << static_cast<int>(p.first.first) << " y " << static_cast<int>(p.first.second) << std::endl;
    std::cout << "x2 " << static_cast<int>(p.second.first) << " y2 " << static_cast<int>(p.second.second) << std::endl;
                       
    return 0;
}



