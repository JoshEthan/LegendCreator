#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace LegendCreator {

	class LEGENDCREATOR_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define LC_CORE_TRACE(...)	::LegendCreator::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LC_CORE_INFO(...)	::LegendCreator::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LC_CORE_WARN(...)	::LegendCreator::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LC_CORE_ERROR(...)	::LegendCreator::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LC_CORE_FATAL(...)	::LegendCreator::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define LC_TRACE(...)		::LegendCreator::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LC_INFO(...)		::LegendCreator::Log::GetClientLogger()->info(__VA_ARGS__)
#define LC_WARN(...)		::LegendCreator::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LC_ERROR(...)		::LegendCreator::Log::GetClientLogger()->error(__VA_ARGS__)
#define LC_FATAL(...)		::LegendCreator::Log::GetClientLogger()->fatal(__VA_ARGS__)