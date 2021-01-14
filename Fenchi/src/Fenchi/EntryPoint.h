#pragma once

#ifdef FENCHI_PLATFORM_WINDOWS
extern Fenchi::Application* Fenchi::CreateApplication();

int main(int argc, char** argv)
{
	printf("Fenchi Engine\n");
	auto app = Fenchi::CreateApplication();
	app->run();
	delete app;
}

#endif // FENCHI_PLATFORM_WINDOWS
