#pragma once
#include <string>
#include "Common\WECommon.h"
#include "Rendering\Models\SimpleMesh.h"
NAMESPACE_BEGIN(Loaders)

class IMeshFactory
{

public:

	virtual Rendering::Models::SimpleMesh* CreateMesh(const std::string& path) = 0;
};
NAMESPACE_END