#pragma once
#include "WELogger.h"

NAMESPACE_BEGIN(Logger)

void WELogger::LogDebug(std::string msg)
{
	spdlog::get("console")->debug(msg);
	m_consoleLogger->debug(msg);
}

void WELogger::LogError(std::string msg)
{
	spdlog::get("console")->error(msg);
}

void WELogger::LogWarning(std::string msg)
{
	spdlog::get("console")->warn(msg);
}

void WELogger::Init()
{
	m_consoleLogger = spdlog::stdout_color_mt("console");
}

NAMESPACE_END

