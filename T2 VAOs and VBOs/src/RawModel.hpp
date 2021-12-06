//
// Created by Yihung Lee on 12/5/21.
//

#ifndef T2_VAOS_AND_VBOS_RAWMODEL_HPP
#define T2_VAOS_AND_VBOS_RAWMODEL_HPP

class RawModel {

private:
    unsigned int vaoID;
    int vertexCount;

public:

    RawModel(unsigned int vaoID, int vertexCount) {
        this->vaoID = vaoID;
        this->vertexCount = vertexCount;
    }

    /**
     * @return The ID of the VAO which contains the data about all the geometry
     *         of this model.
     */

    unsigned int getVaoID() {
        return vaoID;
    }

    /**
     * @return The number of vertices in the model.
     */

    int getVertexCount() {
        return vertexCount;
    }
};

#endif //T2_VAOS_AND_VBOS_RAWMODEL_HPP
