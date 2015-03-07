#version 330 core

in vec2 texCoords;

out vec4 color;

uniform sampler2D glyphAtlas;

void main() {
    color = vec4(vec3(1.0), texture(glyphAtlas, texCoords).r);
}