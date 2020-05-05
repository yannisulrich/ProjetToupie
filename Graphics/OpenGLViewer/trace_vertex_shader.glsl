#version 330 core
layout (location = 0) in vec3 sommet;

uniform mat4 projection;
uniform mat4 vue_modele;


void main()
{
  gl_Position = projection * vue_modele * vec4(sommet, 1.0);
}
