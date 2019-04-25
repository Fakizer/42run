#include "42run.hpp"

bool animate = false;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    std::cerr << "key_callback(" << window << ", " << key << ", " << scancode << ", " << action << ", " << mode << ");" << std::endl;
    if (GLFW_RELEASE == action) {
        return;
    }
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        animate = !animate;
    }
}

int setup_window(GLFWwindow* &window, int width, int height) {
    std::cerr << "Starting GLFW context, OpenGL 4.0" << std::endl;
    if (!glfwInit())
        std::cout << "Failed to init GLFW" << std::endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(width, height, "OpenGL starter pack", NULL, NULL);
    glfwMakeContextCurrent(window);
    // glfwGetFramebufferSize(window, &width, &height);
    std::cout << "-------------" << std::endl;
	// glViewport(0, 0, width, height);
    std::cout << "-------------" << std::endl;
	// glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
    
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    return 0;
}

void	looper(void)
{
	glfwPollEvents();
	glClearColor(0.09f, 0.08f, 0.15f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int main(void) {
    std::cout << "ky" << std::endl;
    GLFWwindow* window;
    GLFW_manager manager;

    manager.run_manager();
    const int width = 1280, height = 1024;
    setup_window(window, width, height);
    while (!glfwWindowShouldClose(window))
	{
		looper();
        glfwSwapBuffers(window);
	}
    return (0);
}
