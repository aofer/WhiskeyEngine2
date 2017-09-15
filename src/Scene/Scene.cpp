#include "Scene.h"
#include "Rendering/Camera.h"
#include <memory>

NAMESPACE_BEGIN(Scene)

Scene::Scene(): m_pRoot(nullptr)
{
	m_pActiveCamera = std::make_shared<Rendering::Camera>();
}


Scene::~Scene()
{
	//delete m_pActiveCamera;
}


void Scene::AddGameObject(GameObjectPtr gameObject)
{
	m_gameObjectsFlat.push_back(gameObject);
}

void Scene::RemoveGameObject(GameObjectPtr gameObject)
{
	//m_gameObjectsFlat.erase(gameObject);
}

void Scene::SetRootGameObject(GameObjectPtr gameObject)
{
	m_pRoot = gameObject;
}

CameraPtr Scene::GetActiveCamera() const {
	return m_pActiveCamera;
}

NAMESPACE_END