#ifndef PARKINGCLASS_H
#define PARKINGCLASS_H

#include <cstdint>

class ParkingClass {

public:
    ParkingClass();
    void displayParking();
    std::pair<std::pair<uint8_t, uint8_t>, std::pair<uint8_t, uint8_t>>  findTheCarToPark();

private:
    uint8_t parking[6][10];
    int rows;
    int cols;
};

#endif