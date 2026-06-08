#include"GlBuffersController.h"

unsigned int VBO;//Vertex Buffer Object 顶点缓冲对象
unsigned int VAO;//Vertex Array Object 顶点数组对象

void InitBufferSystem()
{
	//VBO初始化
	//使用glGenBuffers函数生成一个带有缓冲ID的VBO对象
	glGenBuffers(1, &VBO);
	//顶点缓冲对象的缓冲类型是GL_ARRAY_BUFFER
	//将新创建的VBO绑定到GL_ARRAY_BUFFER目标上
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//绑定缓冲
	//VAO初始化
	//使用glGenVertexArrays函数生成一个带有缓冲ID的VAO对象
	glGenVertexArrays(1, &VAO);
	// 1. 绑定顶点数组对象
	// 将新创建的VAO绑定到GL_VERTEX_ARRAY目标上
	glBindVertexArray(VAO);
}

void BufferDataAdd(int bufferCategory, int dataSize,void* data, int manageType)
{
	glBufferData(bufferCategory, dataSize, data, manageType);//将用户定义的数据复制到当前绑定的缓冲中
}