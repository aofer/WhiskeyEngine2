#pragma once
#include <Common/WECommon.h>
#include <glm/glm.hpp>
#include "Scene/GameComponent.h"

NAMESPACE_BEGIN(Rendering)

struct BaseLight : public Scene::GameComponent
	{
		glm::vec3 m_color;
		float m_ambientIntensity;
		float m_diffuseIntensity;
		bool  m_produceShadows;

		virtual void Update(float dt)
		{

		}

		const Scene::ComponentType GetFamilyType()
		{
			return Scene::ComponentType::LIGHTING;
		}

		BaseLight()
		{
			m_produceShadows = false;
			m_color = glm::vec3(0.0f, 0.0f, 0.0f);
			m_ambientIntensity = 0.0f;
			m_diffuseIntensity = 0.0f;
		}
	};

	struct DirectionalLight : public BaseLight
	{
		glm::vec3 m_direction;

		DirectionalLight()
		{
			m_direction = glm::vec3(0.0f, 0.0f, 0.0f);
		}
	};

	struct PointLight : public BaseLight
	{
		glm::vec3 m_position;

		struct
		{
			float Constant;
			float Linear;
			float Exp;
		} Attenuation;

		PointLight()
		{
			m_position = glm::vec3(0.0f, 0.0f, 0.0f);
			Attenuation.Constant = 0.0f;
			Attenuation.Linear = 0.0f;
			Attenuation.Exp = 0.0f;
		}
	};

	struct SpotLight : public PointLight
	{
		glm::vec3 m_direction;
		float m_cutoff;

		SpotLight()
		{
			m_direction = glm::vec3(0.0f, 0.0f, 0.0f);
			m_cutoff = 0.0f;
		}
	};
NAMESPACE_END