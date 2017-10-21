#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL\glew.h>
#include <GL\glut.h>
#include <GLFW\glfw3.h>

#include <string>
#include <iostream>

class Texture {
public:
	unsigned int ID;
	Texture(const char* texturePath, bool flip=false);
};


#endif // !TEXTURE_H_
