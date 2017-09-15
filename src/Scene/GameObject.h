#pragma once
#include <Common/WECommon.h>
#include <vector>
#include <glm\glm.hpp>
#include <glm\gtx\quaternion.hpp>
#include <memory>
#include <map>
#include "GameComponent.h"

NAMESPACE_BEGIN(Scene)

typedef std::shared_ptr<GameObject> GameObjectPtr;
typedef std::shared_ptr<GameComponent> GameComponentPtr;


	class GameObject {

	public:
		GameObject();
		GameObject(GameObject* parent);
		virtual ~GameObject();

		const glm::mat4& GetModelMatrix() const;
		const glm::vec3& GetPosition() const;
		const float& GetScale() const;
		const glm::quat& GetOrientation() const;
		const std::string& GetGOName() const;

		void SetOrientation(const glm::quat& orient);
		void SetPosition(const glm::vec3& position);
		void SetScale(const float& scale);
		void SetParent(GameObject* parent);
		GameObject* GetParent() const;
		void AddChild(GameObject* child);
		void Update(float dt);
		void AddGameComponent(const ComponentType& familyType, GameComponentPtr* component);


	private:
		void UpdateModelMatrix();
		std::string m_goName;
		//go_id		m_goId;
		glm::mat4 m_modelMatrix;
		glm::vec3 m_position;
		glm::quat m_orientation;
		float m_scale;

		GameObject* m_pParent;
		std::vector<GameObject*> m_children;
		std::map<const ComponentType, GameComponentPtr*> m_gameComponents;
	};

NAMESPACE_END
