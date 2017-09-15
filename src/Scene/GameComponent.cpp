#include "GameComponent.h"

NAMESPACE_BEGIN(Scene)

		GameComponent::GameComponent():
			GameComponent(nullptr)
		{

		}

		GameComponent::GameComponent(GameObject* owner):
			m_pOwner(owner)
		{

		}

		GameComponent::~GameComponent()
		{
			m_pOwner = nullptr;
		}

		const GameObject* GameComponent::GetOwner() const
		{
			return m_pOwner;
		}

NAMESPACE_END

