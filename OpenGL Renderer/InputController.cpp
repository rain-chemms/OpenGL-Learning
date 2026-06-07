#include "InputController.h"


void keyBoardInput(GLFWwindow* window, int key, int checkAction,const std::function<void(GLFWwindow*)>& callback)//处理键盘输入
{
	if (glfwGetKey(window, key) == checkAction)//若按下按键触发了相应事件,则调用回调函数
	{
		callback(window);//回调函数的参数为当前窗口,以便在回调函数中对窗口进行操作
	}
}