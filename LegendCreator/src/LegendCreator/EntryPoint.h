#pragma once

#include "Graphics/GraphicsEngine/interface/EngineFactory.h"
#include "Common/interface/RefCntAutoPtr.hpp"
#include "Graphics/GraphicsEngine/interface/RenderDevice.h"
#include "Graphics/GraphicsEngine/interface/Shader.h"
#include "Graphics/GraphicsEngine/interface/DeviceContext.h"
#include "Graphics/GraphicsEngine/interface/SwapChain.h"
#include "Common/interface/BasicMath.hpp"
#include "Graphics/GraphicsEngine/interface/PipelineState.h"

namespace Diligent
{
	GraphicsPipelineStateCreateInfo PSOCreateInfo;
	ShaderCreateInfo ShaderCI;

}

#ifdef LC_PLATFORM_WINDOWS

extern LegendCreator::Application* LegendCreator::CreateApplication();

int main(int argc, char** argv)
{
	LegendCreator::Log::init();
	LC_CORE_WARN("Initialized Log!");

	auto app = LegendCreator::CreateApplication();
	app->Run();
	delete app;

	Diligent::PSOCreateInfo.PSODesc.Name = "Simple triangle PSO";
	
}
#endif