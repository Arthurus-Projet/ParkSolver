
#include <iostream>
#include "Headers/ParkingClass.h"

   

int main() {

    ParkingClass parkingClass;
    parkingClass.displayParking();
    std::pair<uint8_t, uint8_t> p = parkingClass.findTheFirstPlace();
    std::cout << "x " << static_cast<int>(p.first) << " y " << static_cast<int>(p.second) << std::endl;
                       
    return 0;
}



