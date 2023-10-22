#include<iostream>
#include<vector>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

class ApplicationWindow {
    public:
        GLFWwindow* window;

        void setApplicationName(char* appName) {
            ApplicationName = appName;
        }

        char* getApplicationName() {
            return ApplicationName;
        }

        void setDimensions (int NewHeight, int NewWidth) {
            height = NewHeight;
            width = NewWidth;
        }

        std::vector<int> getDimensions() {
            std::vector<int> vect { width, height };
            return vect;
        }

        void CreateWindow() {
            window = glfwCreateWindow(height, width, ApplicationName, NULL, NULL);
        }

        void ChangeWindowColor(float r, float g, float b, float alpha, GLFWwindow* window) {
            glClearColor(r, g, b, alpha);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
        }

    private:
        char* ApplicationName;

        int height;
        int width;

};

int main() {

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    ApplicationWindow applicationWindow;
    
    applicationWindow.setApplicationName("Hello World!");
    applicationWindow.setDimensions(640, 480);

    applicationWindow.CreateWindow();

    if(applicationWindow.window == NULL) {
        std::cout << "Failed to create window! ):" << std::endl;
        glfwTerminate();
        return -1;
    }

    // In case I forgor
    //std::vector vect = applicationWindow.getDimensions();

    glfwMakeContextCurrent(applicationWindow.window);

    gladLoadGL();

    glViewport(0, 0, 800, 800);

    applicationWindow.ChangeWindowColor(0.7f, 0.3f, 0.5f, 1.0f, applicationWindow.window);

    // Loop until application is up and running
    while(!glfwWindowShouldClose(applicationWindow.window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(applicationWindow.window);
    glfwTerminate();
    return 0;
}

