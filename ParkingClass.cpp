#include <iostream>
#include "Headers/ParkingClass.h"

ParkingClass::ParkingClass() : parking{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
} {}

void ParkingClass::displayParking() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << static_cast<int>(parking[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}