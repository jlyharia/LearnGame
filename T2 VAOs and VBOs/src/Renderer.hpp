//
// Created by Yihung Lee on 12/5/21.
//

#ifndef LEARNGAME_T2_RENDERER_HPP
#define LEARNGAME_T2_RENDERER_HPP


#include "RawModel.hpp"

class Renderer {
public:
    void prepare();

    void render(RawModel model);
};


#endif //LEARNGAME_T2_RENDERER_HPP
