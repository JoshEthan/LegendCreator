#pragma once
#include "LegendCreator/Core.h"
#include "Layer.h"

#include <vector>

namespace LegendCreator {

	class LEGENDCREATOR_API LayerStack
	{
	public:
		LayerStack();
		virtual ~LayerStack();

		virtual void PushLayer(Layer* layer);
		virtual void PushOverlay(Layer* overlay);
		virtual void PopLayer(Layer* layer);
		virtual void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	protected:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};


}