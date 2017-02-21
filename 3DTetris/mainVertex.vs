
#version 420 core  // 450, 330 core , compatibility
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec2 vTexture;
layout(location = 2) in vec3 vNormal;
out vec2 Texture;

void main(){

	vec4 worldPosition = model * vec4(vPosition, 1.0f);
	gl_Position = projection * view * worldPosition;
	Texture = vTexture;
}
