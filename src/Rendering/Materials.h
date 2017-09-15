#pragma once
#include <Common/WECommon.h>
#include <GL/glew.h>
#include <glm\glm.hpp>
NAMESPACE_BEGIN(Rendering)

struct SimplePBRMaterial
{
	glm::vec3	diffuseColor;
	float		metallic;
	float		specular;
	float		roughness;
};
struct BlinnPhongMaterial
{
	glm::vec3	diffuseColor;
	float		kd;
	float		ks;
};
NAMESPACE_END