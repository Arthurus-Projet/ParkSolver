#include <iostream>
#include "Headers/ParkingClass.h"
#include <utility>
#include <algorithm>



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
    
    rows(6),
    cols(10)


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

    int dirs_x[] = {-1, 1, 0, 0}; 
    int dirs_y[] = {0, 0, -1, 1}; 
    // find where is the car :
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (parking[i][j] == 9) {
                std::pair<uint8_t, uint8_t> pos(i, j);
                p.first = pos;

                for (int cpt = 0; cpt < 4; cpt++) {
                    if (i + dirs_x[cpt] >= 0 && i + dirs_x[cpt] <= rows && i + dirs_y[cpt] >= 0 && i + dirs_y[cpt] <= cols)
                        if (parking[i + dirs_x[cpt]][j + dirs_y[cpt]] == 8) {
                                std::pair<uint8_t, uint8_t> pos_2(i + dirs_x[cpt], j + dirs_y[cpt]);
                                p.first = pos;
                                p.second = pos_2;
                                return p;
                            }
                    }
            }
        }
    }
    return p;
}




Result ParkingClass::findTheFirstPlaceToPark(uint8_t parking[6][10], int cpt, int x, int y) {
    
    int dirs_x[] = {-1, 1, 0, 0};
    int dirs_y[] = {0, 0, -1, 1}; 
    

    for (int i = 0; i < 4; i++) {

        if (x + dirs_x[i] >= 0 && x + dirs_x[i] <= rows && y + dirs_y[i] >= 0 && y + dirs_y[i] <= cols) {
            if (parking[y + dirs_y[i]][x + dirs_x[i]] == 0) {
                return std::min(findTheFirstPlaceToPark(parking, cpt + 1, x + dirs_x[i], y + dirs_y[i]).second);
            }

            if (parking[y + dirs_y][x + dirs_x] == 1) {
                std::pair<uint8_t[6][10], int> a;
                a.first = parking;
                a.second = cpt;
                return a;
            } 

        }

        
    }


    return Result;

}