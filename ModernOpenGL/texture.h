#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL\glew.h>
#include <GL\glut.h>
#include <GLFW\glfw3.h>

#include "stb_image.h"
#include <string>
#include <iostream>

class Texture {
public:
	unsigned int ID;
	Texture(const char* texturePath, GLenum format = GL_RGB, bool flip = false) {
		int width, height, nrChannels;
		
		stbi_set_flip_vertically_on_load(flip);
		unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, ID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cerr << "Failed to load texture" << std::endl;
		}
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(data);
	}
};

#endif // !TEXTURE_H_
