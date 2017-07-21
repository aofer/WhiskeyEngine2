#pragma once
#include <Common/WECommon.h>
#include "ApplicationSettings.h"
NAMESPACE_BEGIN(AppInit)

class Application
{
private:
	ApplicationSettings m_settings;

public:
	int Init(ApplicationSettings settings);
};

NAMESPACE_END
