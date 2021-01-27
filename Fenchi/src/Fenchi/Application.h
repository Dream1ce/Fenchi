#pragma once
#include"core.h"
#include"Events/Event.h"
#include"Events/ApplicationEvent.h"

#include"Window.h"
namespace Fenchi
{
	class FENCHI_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be define in client
	Application* CreateApplication();
}

