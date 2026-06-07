#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include "FramebufferSizeCallBacks.h"
#include "InputController.h"

int main()
{
	glfwInit();//初始化GLFW库
	//设置GLFW版本为v3.3，并使用核心模式
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//设置OpenGL版本为3.X
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//设置OpenGL版本为X.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//设置OpenGL为核心模式
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	//创建主窗口
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Renderer", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);//将窗口的上下文设置为当前窗口
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//注册窗口大小调整回调函数

	//在主窗口创建后再对GLAD进行初始化,因为GLAD需要一个有效的OpenGL上下文来加载函数指针
	//在调用任何OpenGL的函数之前我们需要初始化GLAD
	//初始化GLAD，加载OpenGL函数指针
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	//设置视口大小
	glViewport(0, 0, 800 / 2, 600 / 2); //前两个参数控制窗口左下角的位置,第三个和第四个参数控制渲染窗口的宽度和高度(像素)
	//更小的视口可以将其他元素摆放再空余下来的位置中

	//Render Loop:渲染循环
	while (!glfwWindowShouldClose(window))//每次循环的开始前检查一次GLFW是否被要求退出
	{
		//添加ESC退出
		keyBoardInput(window, GLFW_KEY_ESCAPE, GLFW_PRESS, 
			//Lambda表达式传入当前window
			[window](GLFWwindow* window){
				glfwSetWindowShouldClose(window, true); 
			}
		);//按下ESC键时,调用回调函数设置窗口关闭标志为true

		//若当前为false,表明未退出
		glfwSwapBuffers(window);//交换颜色缓冲:储存着GLFW窗口每一个像素颜色值的大缓冲
		glfwPollEvents();//检查事件触发(键鼠输入等),更新窗口状态,调用对应的回调函数
		/*
			Double Buffer(双缓冲机制) :
				前缓冲用于显示, 后缓冲存储渲染结果
				仅当后缓冲渲染完成后才会被交换到前缓冲显示,避免了显示过程中出现撕裂等问题
		*/

		//每一帧渲染之后刷新当前屏幕的颜色缓冲,防止残留上一帧的图像
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//设置清空屏幕所用的颜色值
		glClear(GL_COLOR_BUFFER_BIT);//清屏函数
	}
	
	//渲染循环结束后,释放资源
	glfwTerminate();//释放函数
	return 0;
}