#pragma once

#ifdef LC_PLATFORM_WINDOWS

extern LegendCreator::Application* LegendCreator::CreateApplication();

int main(int argc, char** argv)
{
	LegendCreator::Log::init();
	LC_CORE_WARN("Initialized Log!");
	int a = 5;
	LC_INFO("Hello! Var = {0}", a);

	printf("Legend Creator Engine starting...");
	auto app = LegendCreator::CreateApplication();
	app->Run();
	delete app;
}

#endif