//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_BSP_H
#define HLM2PROCEDUREMAPGENERATOR_BSP_H

#include "../Interior/Room.h"

const int WALL_ALIGN_FACTOR = 16;

vector<Room> *bsp(Rectangle rect,
                  int minRoomArea,
                  double minRoomAreaMultiplyFactor,
                  double continuityProbability,
                  int maxTreeDepth);

#endif //HLM2PROCEDUREMAPGENERATOR_BSP_H
