//
// Created by Yihung Lee on 12/5/21.
//

#ifndef LEARNGAME_T2_LOADER_HPP
#define LEARNGAME_T2_LOADER_HPP

#include <vector>
#include "RawModel.hpp"

class Loader {
private:
    std::vector<unsigned int> vaos;
    std::vector<unsigned int> vbos;

    unsigned int createVAO();

    void unbindVAO();

    void storeDataInAttributeList(int attributeNumber, std::vector<float> &data);

public:
    RawModel loadToVAO(std::vector<float> &positions);

    void cleanUp();
};


#endif //LEARNGAME_T2_LOADER_HPP
