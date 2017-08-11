#pragma once
#include <Common/WECommon.h>
#include <string>
#include "spdlog/spdlog.h"
NAMESPACE_BEGIN(Logger)

#define DEFAULT_LOGGER_PATH "log.txt"

class WELogger {

private:

	std::string m_loggerFile;
	WELogger(void) {}
	std::shared_ptr<spdlog::logger> m_consoleLogger;
public:

	static WELogger& GetInstance()
	{
		static WELogger    instance; // Guaranteed to be destroyed.
										  // Instantiated on first use.
		
		return instance;
	}
	WELogger(WELogger const&) = delete;
	void operator=(WELogger const&) = delete;

	void Init();

	void LogDebug(std::string msg);
	void LogError(std::string msg);
	void LogWarning(std::string msg);
};


#define LOG_DEBUG(msg) Logger::WELogger::GetInstance().LogDebug(msg)
#define LOG_ERROR(msg) Logger::WELogger::GetInstance().LogError(msg)
#define LOG_WARNING(msg) Logger::WELogger::GetInstance().LogWarning(msg)

NAMESPACE_END
