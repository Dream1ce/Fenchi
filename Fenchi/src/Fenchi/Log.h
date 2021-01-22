#pragma once
#include"Core.h"
#include"spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include<memory>

namespace Fenchi {
	class FENCHI_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log Macros

#define FC_CORE_ERROR(...)	::Fenchi::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FC_CORE_WARN(...)	::Fenchi::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FC_CORE_INFO(...)	::Fenchi::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FC_CORE_TRACE(...)	::Fenchi::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FC_CORE_FATAL(...)	::Fenchi::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log Macros
#define FC_CLIENT_ERROR(...)	::Fenchi::Log::GetClientLogger()->error(__VA_ARGS__)
#define FC_CLIENT_WARN(...)		::Fenchi::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FC_CLIENT_INFO(...)		::Fenchi::Log::GetClientLogger()->info(__VA_ARGS__)
#define FC_CLIENT_TRACE(...)	::Fenchi::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FC_CLIENT_FATAL(...)	::Fenchi::Log::GetClientLogger()->fatal(__VA_ARGS__)