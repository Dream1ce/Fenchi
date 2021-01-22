#pragma once

#ifdef FENCHI_PLATFORM_WINDOWS
extern Fenchi::Application* Fenchi::CreateApplication();

int main(int argc, char** argv)
{
	Fenchi::Log::Init();
	FC_CORE_INFO("Initialized Log!");
	FC_CLIENT_WARN("Initialized Log!");
	FC_CLIENT_INFO("Hello var={0}", 5);
	auto app = Fenchi::CreateApplication();
	app->run();
	delete app;
}

#endif // FENCHI_PLATFORM_WINDOWS
