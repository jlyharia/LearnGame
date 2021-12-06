//
// Created by Yihung Lee on 12/5/21.
//

#include "Renderer.hpp"
#include "../lib/glad/glad.h"

/**
	 * This method must be called each frame, before any rendering is carried
	 * out. It basically clears the screen of everything that was rendered last
	 * frame (using the glClear() method). The glClearColor() method determines
	 * the colour that it uses to clear the screen. In this example it makes the
	 * entire screen red at the start of each frame.
	 */
void Renderer::prepare() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 0, 0, 1);
}

/**
 * Renders a model to the screen.
 *
 * Before we can render a VAO it needs to be made active, and we can do this
 * by binding it. We also need to enable the relevant attributes of the VAO,
 * which in this case is just attribute 0 where we stored the position data.
 *
 * The VAO can then be rendered to the screen using glDrawArrays(). We tell
 * it what type of shapes to render and the number of vertices that it needs
 * to render.
 *
 * After rendering we unbind the VAO and disable the attribute.
 *
 * @param model
 *            - The model to be rendered.
 */
void Renderer::render(RawModel model) {
    glBindVertexArray(model.getVaoID());
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}