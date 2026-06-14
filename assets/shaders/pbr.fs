#version 330

in vec3 fragPosition;
in vec2 fragTexCoord;
in vec3 fragNormal;

uniform vec4 colDiffuse;
uniform sampler2D texture0;

out vec4 finalColor;

// Simulação simplificada de PBR (Lambertian + Rim Light simples)
void main() {
    vec3 lightPos = vec3(10.0, 10.0, 10.0);
    vec3 lightDir = normalize(lightPos - fragPosition);
    float diff = max(dot(fragNormal, lightDir), 0.2); // Ambient base 0.2
    
    vec4 texColor = texture(texture0, fragTexCoord);
    finalColor = texColor * colDiffuse * diff;
}
