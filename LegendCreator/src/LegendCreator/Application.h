#pragma once

#include "Window.h"
#include "LegendCreator/LayerStack.h"
#include "LegendCreator/Events/Event.h"
#include "LegendCreator/Events/ApplicationEvent.h"


namespace LegendCreator
{
	class LEGENDCREATOR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }

		inline Window& GetWindow() { return *m_Window;  }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in the client
	Application* CreateApplication();

}

