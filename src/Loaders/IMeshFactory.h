#pragma once
#include <string>
#include "Common\WECommon.h"

NAMESPACE_BEGIN(Loaders)

class SimpleMesh;

class IMeshFactory
{

public:

	virtual SimpleMesh* CreateMesh(const std::string& path) = 0;
};
NAMESPACE_END