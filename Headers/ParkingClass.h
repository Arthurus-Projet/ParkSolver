#ifndef PARKINGCLASS_H
#define PARKINGCLASS_H

#include <cstdint>

using Grid = std::array<std::array<uint8_t, 10>, 6>;
using Result = std::pair<Grid, int>;

class ParkingClass {

public:
    ParkingClass();
    void displayParking();
    std::pair<std::pair<uint8_t, uint8_t>, std::pair<uint8_t, uint8_t>>  findTheCarToPark();
    Result findTheFirstPlaceToPark(uint8_t parking[6][10], int cpt, int x, int y);

private:
    uint8_t parking[6][10];
    int rows;
    int cols;
};

#endif