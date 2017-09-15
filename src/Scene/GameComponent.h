#pragma once
#include <Common/WECommon.h>

NAMESPACE_BEGIN(Scene)

	class GameObject;


		enum class ComponentType
		{
			MESHES,
			RENDERING,
			LIGHTING,
			PHYSICS,
			CAMERAS
		};

		//typedef unsigned int gc_id;


		class GameComponent
		{
		public:
			GameComponent(); //A hack to keep stuff compling - will be removed soon
			GameComponent(GameObject* owner);
			virtual ~GameComponent();
			virtual const ComponentType GetFamilyType() = 0 ;
			const GameObject* GetOwner() const;

			virtual void Update(float dt) = 0;

		private:
			GameObject* m_pOwner;

		};

NAMESPACE_END