#version 330 core
in vec3 vColor;
in vec2 TexCoord;
out vec4 fColor;
//uniform sampler2D texture1;
//uniform sampler2D texture2;
uniform vec3 objectColor;
uniform vec3 lightColor;
void main(){
	fColor = vec4(lightColor * objectColor, 1.0);;
}