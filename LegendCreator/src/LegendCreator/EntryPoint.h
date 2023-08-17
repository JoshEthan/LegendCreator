#pragma once

#ifdef LC_PLATFORM_WINDOWS

extern LegendCreator::Application* LegendCreator::CreateApplication();

int main(int argc, char** argv)
{
	LegendCreator::Log::init();
	LC_CORE_WARN("Initialized Log!");

	auto app = LegendCreator::CreateApplication();
	app->Run();
	delete app;
}

#endif