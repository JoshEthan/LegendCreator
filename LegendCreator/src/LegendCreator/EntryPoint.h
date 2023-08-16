#pragma once

#ifdef LC_PLATFORM_WINDOWS

extern LegendCreator::Application* LegendCreator::CreateApplication();

int main(int argc, char** argv)
{
	printf("Legend Creator Engine starting...");
	auto app = LegendCreator::CreateApplication();
	app->Run();
	delete app;
}

#endif