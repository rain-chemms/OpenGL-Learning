#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>

//缓冲对象管理器
extern unsigned int VBO;//Vertex Buffer Object 顶点缓冲对象
extern unsigned int VAO;//Vertex Array Object 顶点数组对象

void InitBufferSystem();//初始化缓冲对象
void BufferDataAdd(int bufferCategory, int dataSize,void* data, int manageType);