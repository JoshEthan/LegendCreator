#include "lcpch.h"
#include "Application.h"

#include "LegendCreator/Events/ApplicationEvent.h"
#include "LegendCreator/Log.h"

namespace LegendCreator
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			LC_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			LC_TRACE(e);
		}

		while (true);
	}
}