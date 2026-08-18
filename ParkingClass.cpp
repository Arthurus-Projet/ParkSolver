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




Result ParkingClass::findTheFirstPlaceToPark(Grid parking, int cpt, int x, int y) {

    if (x < 0 || x >= cols || y < 0 || y >= rows || parking[y][x] == 7)
        return {parking, INT_MAX};

    if (parking[y][x] == 1)
        return {parking, cpt};

    if (parking[y][x] != 0)
        return {parking, INT_MAX};

    parking[y][x] = 7;

    return std::min({
        findTheFirstPlaceToPark(parking, cpt + 1, x - 1, y),
        findTheFirstPlaceToPark(parking, cpt + 1, x + 1, y),
        findTheFirstPlaceToPark(parking, cpt + 1, x, y - 1),
        findTheFirstPlaceToPark(parking, cpt + 1, x, y + 1)
    }, [](const Result& a, const Result& b) {
        return a.second < b.second;
    });
}