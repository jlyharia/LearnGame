//
// Created by Yihung Lee on 12/4/21.
//

#ifndef PBR2_3_DISPLAYMANAGER_HPP
#define PBR2_3_DISPLAYMANAGER_HPP

#include "../lib/glad/glad.h"
#include <GLFW/glfw3.h>
#include <string>

const static int WIDTH = 1280;
const static int HEIGHT = 720;
static bool firstMouse = true;
static double lastX = WIDTH / 2.0;
static double lastY = HEIGHT / 2.0;

class DisplayManager {
public:
    /**
     * Creates a display window on which we can render our game. The dimensions
     * of the window are determined by setting the display mode. By using
     * "glViewport" we tell OpenGL which part of the window we want to render
     * our game onto. We indicated that we want to use the entire window.
     */
    int createDisplay();

    /**
     * This method is used to update the display at the end of every frame. When
     * we have set up a rendering process this method will display whatever
     * we've been rendering onto the screen. The "sync" method is used here to
     * cap the frame rate. Without this the computer would just try to run the
     * game as fast as it possibly can, doing more work than it needs to.
     */

    void updateDisplay();

    /**
     * This closes the window when the game is closed.
     */

    void closeDisplay();

    GLFWwindow *getGLFwindow() {
        return this->window;
    }

private:

    const int FPS_CAP = 60;
    const char *const TITLE = "Our First Display";
    GLFWwindow *window;

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    static void mouse_callback(GLFWwindow *window, double xpos, double ypos);

    static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
};


#endif //PBR2_3_DISPLAYMANAGER_HPP
