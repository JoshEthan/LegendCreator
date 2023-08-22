#include <LegendCreator.h>

class ExampleLayer : public LegendCreator::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		LC_INFO("ExampleLayer::Update");
	}

	void OnEvent(LegendCreator::Event& event) override
	{
		LC_TRACE("{0}", event);
	}
};

class Sandbox : public LegendCreator::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

LegendCreator::Application* LegendCreator::CreateApplication()
{
	return new Sandbox();
}