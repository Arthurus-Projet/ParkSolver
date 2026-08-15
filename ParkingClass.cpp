#include <iostream>
#include "Headers/ParkingClass.h"
#include <utility>



ParkingClass::ParkingClass() : 

    parking {

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
        }, 
    
    rows{6},
    cols{10}


    {}

void ParkingClass::displayParking() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << static_cast<int>(parking[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}


std::pair<std::pair<uint8_t, uint8_t>, std::pair<uint8_t, uint8_t>> ParkingClass::findTheCarToPark() {

    std::pair<std::pair<uint8_t, uint8_t>, std::pair<uint8_t, uint8_t>> p;

    // find where is the car :
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (parking[i][j] == 9) {
                std::pair<uint8_t, uint8_t> pos(i, j);
                p.first = pos;
                if (i + 1 <= rows) 
                    if (parking[i + 1][j] == 8) {
                        std::pair<uint8_t, uint8_t> pos_2(i + 1, j);
                        p.first = pos;
                        p.second = pos_2;
                        return p;
                        }

                if (i - 1 >= 0) {
                    if (parking[i - 1][j] == 8) {
                        std::pair<uint8_t, uint8_t> pos_2(i - 1, j);
                        p.second = pos_2;
                        return p;
                        }

                    }

                if (j + 1 <= cols) {
                    if (parking[i][j + 1] == 8) {   
                        std::pair<uint8_t, uint8_t> pos_2(i, j + 1);
                        p.second = pos_2;
                        return p;
                        }

                    }

                if (j - 1 >= 0) {
                    if (parking[i][j - 1] == 8) {
                        std::pair<uint8_t, uint8_t> pos_2(i, j - 1);
                        p.second = pos_2;
                        return p;
                        }

                    }

                }
        }
    }

    return p;
    

}