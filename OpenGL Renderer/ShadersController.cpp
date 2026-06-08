#include"ShadersController.h"

unsigned int fragmentShader;//片段着色器对象
char* fragmentShaderSource;//片段着色器源码
unsigned int vertexShader;//顶点着色器对象
char* vertexShaderSource;//顶点着色器源码
unsigned int shaderProgram;//最终的着色器程序

void SetVertexShaderShource(char* source)//设置顶点着色器源码
{
	//设置当前顶点着色器源码
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//编译着色器源代码
	glCompileShader(vertexShader);
	//检测着色器编译是否成功
	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

void LinkVertexAttribute(int vertexAttribute, int attributeSize, int dataType, int normalized, int stride, int offset)//连接顶点属性
{
	//设置顶点属性指针
	//设置样例glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glVertexAttribPointer(vertexAttribute, attributeSize, dataType, normalized, stride, (void*)offset);
	//激活相应的设置
	glEnableVertexAttribArray(0);
}

void SetFragmentShaderShource(char* source)//设置片段着色器源码
{
	//设置当前片段着色器源码
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//编译着色器源代码
	glCompileShader(fragmentShader);
	//检测着色器编译是否成功
	int  success;
	char infoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

void RelinkShaderProgram()//重新链接着色器程序
{
	//链接着色器程序
	glAttachShader(shaderProgram, vertexShader);//链接顶点着色器
	glAttachShader(shaderProgram, fragmentShader);//链接片段着色器
	//你也可以链接新增的其他着色器
	glLinkProgram(shaderProgram);//开始链接
	//检测着色器程序链接是否成功
	int  success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

void InitShadersSystem()
{
	//初始化顶点着色器
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//默认着色器设置
	vertexShaderSource = (char*)"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	SetVertexShaderShource(vertexShaderSource);
	//初始化片段着色器
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//默认着色器设置
	fragmentShaderSource = (char*)"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";
	SetFragmentShaderShource(fragmentShaderSource);
	//初始化着色器程序
	shaderProgram = glCreateProgram();
	RelinkShaderProgram();
	//链接着色器程序
	return ;
}

void DeleteShadersSystem()//清空着色器系统
{
	glDeleteShader(vertexShader);//删除顶点着色器对象
	glDeleteShader(fragmentShader);//删除片段着色器对象
	glDeleteProgram(shaderProgram);//删除着色器程序对象
}