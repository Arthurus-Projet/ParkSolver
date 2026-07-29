#include <iostream>
#include "Headers/ParkingClass.h"



ParkingClass::ParkingClass() : parking{

    // 1: Place to park
    // 6: Obstacle

    // 9: Front of the car
    // 8: Back of the car

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 6, 0, 9, 6, 1, 1, 1},
    {1, 1, 1, 6, 0, 8, 6, 1, 1, 1}
} {}

void ParkingClass::displayParking() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << static_cast<int>(parking[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}