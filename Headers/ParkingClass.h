#ifndef PARKINGCLASS_H
#define PARKINGCLASS_H

#include <cstdint>

class ParkingClass {

public:
    ParkingClass();
    void displayParking();

private:
    uint8_t parking[6][10];
};

#endif