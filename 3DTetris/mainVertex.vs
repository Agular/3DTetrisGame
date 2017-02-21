
#version 420 core  // 450, 330 core , compatibility
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;
out vec4 Color;

void main(){

	vec4 worldPosition = model * vec4(vPosition, 1.0f);
	gl_Position = projection * view * worldPosition;
	Color = vec4(vColor,1.0f);
}
