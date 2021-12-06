//
// Created by Yihung Lee on 12/5/21.
//
#include "../lib/glad/glad.h"
#include "Loader.hpp"


/**
     * Creates a VAO and stores the position data of the vertices into attribute
     * 0 of the VAO.
     *
     * @param positions
     *            - The 3D positions of each vertex in the geometry (in this
     *            example a quad).
     * @return The loaded model.
*/

RawModel Loader::loadToVAO(std::vector<float> &positions) {
    unsigned int vaoID = createVAO();
    glBindVertexArray(vaoID);
    storeDataInAttributeList(0, positions);
    unbindVAO();
    return {vaoID, static_cast<int>(positions.size() / 3)};
}

/**
 * Deletes all the VAOs and VBOs when the game is closed. VAOs and VBOs are
 * located in video memory.
 */

void Loader::cleanUp() {
    glDeleteVertexArrays(vaos.size(), &vaos[0]);
    glDeleteVertexArrays(vbos.size(), &vbos[0]);
}

/**
 * Creates a new VAO and returns its ID. A VAO holds geometry data that we
 * can render and is physically stored in memory on the GPU, so that it can
 * be accessed very quickly during rendering.
 *
 * Like most objects in OpenGL, the new VAO is created using a "gen" method
 * which returns the ID of the new VAO. In order to use the VAO it needs to
 * be made the active VAO. Only one VAO can be active at a time. To make
 * this VAO the active VAO (so that we can store stuff in it) we have to
 * bind it.
 *
 * @return The ID of the newly created VAO.
 */
unsigned int Loader::createVAO() {
    unsigned int vaoID;
    glGenVertexArrays(1, &vaoID);
    vaos.push_back(vaoID);
    return vaoID;
}

/**
 * Stores the position data of the vertices into attribute 0 of the VAO. To
 * do this the positions must first be stored in a VBO. You can simply think
 * of a VBO as an array of data that is stored in memory on the GPU for easy
 * access during rendering.
 *
 * Just like with the VAO, we create a new VBO using a "gen" method, and
 * make it the active VBO (so that we do stuff to it) by binding it.
 *
 * We then store the positions data in the active VBO by using the
 * glBufferData method. We also indicate using GL_STATIC_DRAW that this data
 * won't need to be changed. If we wanted to edit the positions every frame
 * (perhaps to animate the quad) then we would use GL_DYNAMIC_DRAW instead.
 *
 * We the connect the VBO to the VAO using the glVertexAttribPointer()
 * method. This needs to know the attribute number of the VAO where we want
 * to put the data, the number of floats used for each vertex (3 floats in
 * this case, because each vertex has a 3D position, an x, y, and z value),
 * the type of data (in this case we used floats) and then some other more
 * complicated stuff for storing the data in more fancy ways. Don't worry
 * about the last 3 parameters for now, we don't need them here.
 *
 * Now that we've finished using the VBO we can unbind it. This isn't
 * totally necessary, but I think it's good practice to unbind the VBO when
 * you're done using it.
 *
 * @param attributeNumber
 *            - The number of the attribute of the VAO where the data is to
 *            be stored.
 * @param data
 *            - The geometry data to be stored in the VAO, in this case the
 *            positions of the vertices.
 */

void Loader::storeDataInAttributeList(int attributeNumber, std::vector<float> &data) {
    unsigned int vboID;
    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(std::vector<float>) * data.size(), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, false, 0, 0);

    glEnableVertexAttribArray(0);
    // bind to default buffer at the end
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * Unbinds the VAO after we're finished using it. If we want to edit or use
 * the VAO we would have to bind it again first.
 */

void Loader::unbindVAO() {
    glBindVertexArray(0);
}
