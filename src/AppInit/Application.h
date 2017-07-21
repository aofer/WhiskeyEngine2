#include "../Common/WECommon.h"
#include "ApplicationSettings.h"
NAMESPACE_BEGIN(AppInit)

class Application
{
private:
	ApplicationSettings m_settings;

public:
	void Init(ApplicationSettings settings);
};

NAMESPACE_END
