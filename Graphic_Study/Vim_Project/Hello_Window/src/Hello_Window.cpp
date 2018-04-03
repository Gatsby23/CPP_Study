#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// 为什么要在这里声明回调函数,有什么好处?
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
	// 配置OpenGL初始化
	glfwInit();
	// 配置OpenGL的主版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// 配置OpenGL的次版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//说明这里的使用的是核心模式
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//如果是apple的话,需要补充这一句
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// 创建一个窗口对象
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

	if(window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	//这里glfwSetFrameCallback回调函数主要是用来设置调整窗口大小
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	// glad: 用来管理OpenGL的函数指针, 所以调用任何OpenGL的函数之前都需要初始化GLAD，这里GLFW定义的指针函数是: glfwGetProcAddress
	// 这里留个疑问: 为什么每次都需要将opengl的函数库初始化？
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 提供渲染循环，保证GLFW在退出前一直保持运行.
	// glfwWindowShouldClose函数在每次循环开始前检查一次GLFW是否要求被退出
	while(!glfwWindowShouldClose(window)){
		// 输入
		processInput(window);

		// 渲染指令->这里是不断用一个颜色填充屏幕
		// glClear用来清屏
		// 这里glClearColor相当于一个状态设置函数
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		// 这里用glClear作用是清空颜色缓冲，实际上相当于一个状态使用函数
		glClear(GL_COLOR_BUFFER_BIT);

		//glfwSwapBuffers函数交换颜色缓冲,存储GLFW窗口每一个颜色值的大缓冲,在这一迭代中被用来绘制，并且输出到屏幕上,这里用的是双缓冲，双缓冲在消除不真实感中很有用　
		glfwSwapBuffers(window);
		//glfwPollEvents检查有没有触发什么事件(比如键盘输入、鼠标移动)、更新窗口状态,并调用对应的回调函数
		glfwPollEvents();
	}
	return 0;
}

//　这里定义这个回调函数原因:需要使用glViewport中定义的位置和宽高进行2D坐标的转换,将OpenGL中的位置坐标转换成屏幕中的坐标,处理过得OpenGL的坐标范围只有-1到1.
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window){
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
}
