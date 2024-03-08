#ifndef BETTER_GAME_ENGINE_WINDOW_H
#define BETTER_GAME_ENGINE_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Define Window class
class Window {
    private:
        GLFWwindow * window;
        static void ResizeWindow(GLFWwindow * w, int width, int height);
    public:
        Window();
        void Run(void (* Start)(), void (* Update)());
};

// Window constructor, called when a new window is instantiated
Window::Window() {
    // Set up GLFW for window creation
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3),
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    window = glfwCreateWindow(800, 800, "Game", NULL, NULL);

    // Terminate GLFW if the window cannot be created
    if (window == NULL) {
        std::cout << "Could not create GLFW Window" << std::endl;
        glfwTerminate();
        return;
    }

    // Configure the rest of GLFW
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, ResizeWindow);

    // Initialize GLAD as it manages function pointers for OpenGL, and if it fails terminate the window creation
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Could not initialize GLAD" << std::endl;
        return;
    }

    // Configure OpenGL
    glViewport(0, 0, 800, 800);
}

// Framebuffer resize callback, called every time the window is resized
void Window::ResizeWindow(GLFWwindow * w, int width, int height) {
    glViewport(0, 0, width, height);
}

// Run method, called to start the window frame loop
void Window::Run(void (* Start)(), void (* Update)()) {
    // Call pre-loop code
    Start();

    // Start the window frame loop
    while (!glfwWindowShouldClose(window)) {
        // Call in-loop code
        Update();

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate the window once it should be closed
    glfwTerminate();
}

#endif
