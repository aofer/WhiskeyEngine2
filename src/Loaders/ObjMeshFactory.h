#pragma once
#include "IMeshFactory.h"
#include <assimp\Importer.hpp> 
#include <assimp\scene.h>       // Output data structure
#include <assimp\postprocess.h> // Post processing flags
#include "Common\WECommon.h"

NAMESPACE_BEGIN(Loaders)

		class ObjMeshFactory : public IMeshFactory
		{
			friend class Rendering::Models::SimpleMesh;
		public:
			virtual Rendering::Models::SimpleMesh* CreateMesh(const std::string& path);

		private:
			Rendering::Models::SimpleMesh* InitFromScene(const aiScene* pScene, const std::string& Filename);
			void InitMesh(unsigned int Index, const aiMesh* paiMesh, Rendering::Models::SimpleMesh* mesh);
		};

NAMESPACE_END
