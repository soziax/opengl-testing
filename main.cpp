#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
int main()
{
	glfwInit();
	// version of glfw we are using which is 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//we are using coee profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// creates 800 by 800 window
	GLFWwindow* window = glfwCreateWindow(800, 800, "Opengl learning", NULL, NULL);
	// error check if window fails to be made
	if (window == NULL)
	{
		cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}
	// introduces window to current context
	glfwMakeContextCurrent(window);

	// loads glad
	gladLoadGL();

	//loads glad so we can configure opengl window
	//viewport goes  x = 0, y = 0 to x = 800, y = 800
	glViewport(0, 0, 800, 800);
	//what color we want in the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	//cleans the back bufer and gives it new color
	glClear(GL_COLOR_BUFFER_BIT);
	//swaps the back buffer with front buffer
	glfwSwapBuffers(window);

	// while loop so window can stay 
	while (!glfwWindowShouldClose(window))
	{
		// takes in the glfw events
		glfwPollEvents();
	}
	// delelets the window
	glfwDestroyWindow(window);
	// terminates glfw
	glfwTerminate();
	return 0;
}