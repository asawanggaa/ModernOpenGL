#version 330 core
in vec2 TexCoord;

out vec4 fColor;

uniform sampler2D texture1;

void main(){
	fColor = texture(texture1, TexCoord);
}