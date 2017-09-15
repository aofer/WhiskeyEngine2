#pragma once
#include <Common/WECommon.h>
#include <vector>
#include <memory>

NAMESPACE_BEGIN(Rendering)
class Camera; 
class BaseLight;
NAMESPACE_END

NAMESPACE_BEGIN(Scene)
	
class GameObject;
typedef std::shared_ptr<GameObject> GameObjectPtr;
typedef std::shared_ptr<Rendering::Camera>	CameraPtr;


	class Scene {
	private:
		std::vector<GameObjectPtr> m_gameObjectsFlat;
		std::vector<Rendering::BaseLight*>	m_lights;
		GameObjectPtr m_pRoot;
		CameraPtr m_pActiveCamera;
		

	public:
		Scene();
		~Scene();
		void AddGameObject(GameObjectPtr gameObject);
		void RemoveGameObject(GameObjectPtr gameObject);
		void SetRootGameObject(GameObjectPtr gameObject);
		CameraPtr GetActiveCamera() const;
	};

NAMESPACE_END
