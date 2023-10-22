#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

void ChangeWindowColor(float r, float g, float b, float alpha, GLFWwindow* window) {
    glClearColor(r, g, b, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}

int main() {

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "Hello World!", NULL, NULL);

    if(window == NULL) {
        std::cout << "Failed to create window! ):" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, 800, 800);

    ChangeWindowColor(0.7f, 0.3f, 0.5f, 1.0f, window);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

