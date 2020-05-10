#version 410 core
out vec4 FragColor;

in vec3 normal;
in vec3 position;

in VS_OUT {
    vec3 FragPos;
    vec4 FragPosLightSpace;
} fs_in;

uniform sampler2D shadowMap;

uniform vec3 lightPos;
uniform vec3 lightIntensity;
uniform vec3 viewPos;

// Material information
uniform vec3 Ka;
uniform vec3 Kd;
uniform vec3 Ks;
uniform float shininess;

uniform bool drawShadows;


float ShadowCalculation(vec4 fragPosLightSpace)
{
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap, projCoords.xy).r;
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // calculate bias (based on depth map resolution and slope)
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    float bias = max(0.005 * (1.0 - dot(normal, lightDir)), 0.0005);
    // check whether current frag pos is in shadow
    // float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;
    // PCF
    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;
        }
    }
    shadow /= 9.0;

    // keep the shadow at 0.0 when outside the far_plane region of the light's frustum.
    if(projCoords.z > 1.0)
    shadow = 0.0;

    return shadow;
}

void main()
{
    // Calculate light direction
    vec3 s = normalize( lightPos - position);

    // Calculate the vector from the fragment to eye position
    vec3 v = normalize( -position.xyz );

    // Reflect the light using the normal
    vec3 r = reflect( -s, normal);

    // Calculate the diffuse contribution
    vec3 diffuseIntensity = vec3( max( dot( s, normal), 0.0) );

    // Calculate specular contribution
    vec3 specularIntensity = vec3(0.0);
    if( dot( s, normal) > 0.0 )
    specularIntensity = vec3( pow( max( dot(r, v), 0.0), shininess));

    float shadow = 0;
    if(drawShadows) {
        shadow = ShadowCalculation(fs_in.FragPosLightSpace);
    }
    // Calculate final color
    vec3 lighting = lightIntensity * (Ka + (1 - shadow) * (Kd * diffuseIntensity + Ks * specularIntensity));

    FragColor = vec4(lighting, 1.0);
    //FragColor = vec4(1, 0,0,1);
   // FragColor = vec4(closestDepth, 0,0,1);
}
