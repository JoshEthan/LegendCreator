#include "lcpch.h"
#include "Application.h"

#include "LegendCreator/Events/ApplicationEvent.h"
#include "LegendCreator/Log.h"

namespace LegendCreator
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}