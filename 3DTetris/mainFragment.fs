
#version 420 core  // 450, 330 core , compatibility
layout(location=0) out vec4 fColor;
in vec4 Color;

void main() {
	fColor = Color;
 }
