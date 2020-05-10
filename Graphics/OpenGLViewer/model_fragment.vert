#version 410 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 normal;
out vec3 position;

out VS_OUT {
    vec3 FragPos;
    vec4 FragPosLightSpace;
} vs_out;

uniform mat4 model;
uniform mat4 lightSpaceMatrix;

uniform mat4 MV;
uniform mat3 N;
uniform mat4 MVP;

void main()
{
    normal = normalize( N * aNormal );
    position = vec3( MV * vec4( aPos, 1.0 ) );
    vs_out.FragPos = vec3(model * vec4(aPos, 1.0));
    vs_out.FragPosLightSpace = lightSpaceMatrix * vec4(vs_out.FragPos, 1.0);
    gl_Position = MVP * vec4(aPos, 1.0);
}