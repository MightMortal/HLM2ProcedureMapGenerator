//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_BSP_H
#define HLM2PROCEDUREMAPGENERATOR_BSP_H

#include "../Interior/Room.h"

const int DIVISION_DIRECTION_HORIZONTAL = 0;
const int DIVISION_DIRECTION_VERTICAL = 1;
const int CORRIDOR_WIDTH = WALL_ALIGN_FACTOR * 3;

vector<Room> *bsp(Rectangle rect,
                  int minRoomArea,
                  double minRoomAreaMultiplyFactor,
                  double continuityProbability,
                  int maxTreeDepth,
                  int generateCorridor = 4,
                  int corridorWidth = CORRIDOR_WIDTH,
                  int divisionDirection = 2);

#endif //HLM2PROCEDUREMAPGENERATOR_BSP_H
