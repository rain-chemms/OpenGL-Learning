#pragma once
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>


extern unsigned int vertexShader;//顶点着色器对象
extern char* vertexShaderSource;//顶点着色器源码
void LinkVertexAttribute(int vertexAttribute,int attributeSize,int dataType,int normalized,int stride,int offset);//连接顶点属性
void SetVertexShaderShource(char* source);//设置顶点着色器源码


extern unsigned int fragmentShader;//片段着色器对象
extern char* fragmentShaderSource;//片段着色器源码
void SetFragmentShaderShource(char* source);//设置片段着色器源码


extern unsigned int shaderProgram;//最终的着色器程序
void RelinkShaderProgram();//重新链接着色器程序

void InitShadersSystem();//初始化着色器系统
void DeleteShadersSystem();//清空着色器系统