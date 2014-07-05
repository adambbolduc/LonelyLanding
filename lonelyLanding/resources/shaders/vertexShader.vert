// version of GLSL
#version 330 core

in vec3 vertexCoord;
in vec3 normalCoord;

uniform mat4 MVP;
//uniform vec3 light;

smooth out vec3 fragColor;
out vec4 gl_Position;

void main(){
	vec3 light = vec3(0,-1,0);
	vec3 normalizedNormal = normalize(normalCoord);
	
	vec3 normalizedLightDirection = normalize( light );

	float cosTheta = dot( normalizedNormal, normalizedLightDirection);
	
	cosTheta = clamp(cosTheta,0,1);
	
	fragColor =  cosTheta * vec3(0.5,0.5,0.6) +  0.2*vec3(1,1,1) ;

    gl_Position = MVP * vec4(vertexCoord,1.0) ;

}