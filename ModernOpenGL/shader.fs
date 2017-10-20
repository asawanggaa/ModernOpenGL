#version 330 core
in vec3 vColor;
in vec2 TexCoord;
out vec4 fColor;
uniform sampler2D texture1;
uniform sampler2D texture2;
void main(){
	fColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
}