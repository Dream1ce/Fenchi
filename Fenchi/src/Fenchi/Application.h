#pragma once
#include"core.h"
namespace Fenchi
{
	class FENCHI_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	};

	//To be define in client
	Application* CreateApplication();
}

