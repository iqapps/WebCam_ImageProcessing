#pragma once

#include "Processors.h"

class Threshold : public Processor
{
public:
	Threshold(olc::PixelGameEngine* gameArg) : Processor(gameArg, "Threshold") { }

	static Registrar<Threshold> registrar;

	void ProcessKeys(float fElapsedTime)
	{
		if (game->GetKey(olc::Key::DOWN).bHeld) fThresholdValue -= 0.1f * fElapsedTime;
		if (game->GetKey(olc::Key::UP).bHeld) fThresholdValue += 0.1f * fElapsedTime;
		if (fThresholdValue > 1.0f) fThresholdValue = 1.0f;
		if (fThresholdValue < 0.0f) fThresholdValue = 0.0f;
	}

	void ProcessImage(float fElapsedTime, frame& input, frame& output)
	{
		// Perform threshold per pixel
		for (int i = 0; i < nFrameWidth; i++)
		{
			for (int j = 0; j < nFrameHeight; j++)
			{
				output.set(i, j, input.get(i, j) >= fThresholdValue ? 1.0f : 0.0f);
			}
		}
	}

	void DrawUI(int x, int y, int stepy)
	{
		game->DrawString(x, y, "Change threshold bias with arrow UP and DOWN");
		game->DrawString(x, y + stepy, "Current value = " + std::to_string(fThresholdValue));
	}

private:
	float fThresholdValue = 0.5f;
};

Registrar<Threshold> Threshold::registrar(ProcessorInfo { "Threshold", Processor::Create<Threshold> });