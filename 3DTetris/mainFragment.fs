
#version 420 core  // 450, 330 core , compatibility

layout(location=0) out vec4 fColor;
uniform sampler2D tex;

in vec2 Texture;

void main() {
	fColor = texture(tex, Texture);
 }
