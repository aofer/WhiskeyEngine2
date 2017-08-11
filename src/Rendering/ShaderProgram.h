#pragma once
#include <common/WECommon.h>
#include <string>
NAMESPACE_BEGIN(Rendering)

enum class SHADER_TYPE
{
	VERTEX,
	FRAGMENT,
	GEOMETRY,
	TESSELATION
};

static std::string ReadFileIntoString(const std::string& filename);

class ShaderProgram
{
private:
	std::string m_progName;
};

NAMESPACE_END