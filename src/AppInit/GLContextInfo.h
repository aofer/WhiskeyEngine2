#pragma once
#include <Common/WECommon.h>

NAMESPACE_BEGIN(AppInit)
//OpenGL versions
	struct GLContextInfo
	{
		int major_version, minor_version;
		bool core;

		GLContextInfo()
		{
			major_version = 3;
			minor_version = 3;
			core = true;
		}

		GLContextInfo(int major_version, int minor_version, bool core)
		{
			this->major_version = major_version;
			this->minor_version = minor_version;
			this->core = core;
		}

		void operator= (const GLContextInfo &info)
		{
			major_version = info.major_version;
			minor_version = info.minor_version;
			core = info.core;
		}
	};
NAMESPACE_END