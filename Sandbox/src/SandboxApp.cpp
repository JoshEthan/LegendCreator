#include <LegendCreator.h>

class Sandbox : public LegendCreator::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

LegendCreator::Application* LegendCreator::CreateApplication()
{
	return new Sandbox();
}