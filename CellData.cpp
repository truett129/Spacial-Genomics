/*
 * CellData.h
 *
 *  Created on: Nov 9, 2021
 *      Author: student
 */

#include <iostream>
#include <string>
#include <sstream>
#include "CellData.h"

using std::cout;
using std::string;
using std::stringstream;
using std::stoi;

CellData::CellData(): id("-1"), fov(-1), volume(-1), center_x(-1), center_y(-1), min_x(-1), min_y(-1), max_x(-1), max_y(-1) {} //initialize everything

CellData::CellData(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
: id(id), fov(fov), volume(volume), center_x(center_x), center_y(center_y), min_x(min_x), min_y(min_y), max_x(max_x), max_y(max_y) {} //initialize everything


CellData::~CellData() {} // You should not need to implement this

bool CellData::operator<(const CellData& b) {
	// Implement this
    // iterate through string and if 1 num is bigger than other than its bigger 
    int idA;
    int idB;
    
    if (fov < b.fov ) {
        return true;
    } else if (fov == b.fov) {
    } else {
        return false;
    }
    for (unsigned int i = 0; i < id.size(); i++) {
        idA = id.at(i) - '0';
        idB = b.id.at(i) - '0';
        if (idA < idB) {
            return true;
        } else if (idB == idA) {
            continue;
        } else {
            break;
        }
    }

    return false;
}

bool CellData::operator==(const CellData& b)
{
    // Implement this
    if ((id == b.id) && (fov == b.fov) && (volume == b.volume) && (center_x == b.center_x) && (center_y == b.center_y) && (min_x == b.min_x) && (min_y == b.min_y) && (max_x == b.max_x) && (max_y == b.max_y)) {
        return true;
    }  

    return false;

}

