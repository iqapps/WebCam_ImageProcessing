#pragma once

#include "Processor.h"

class Adaptive : public Processor
{
public:
	Adaptive(olc::PixelGameEngine* gameArg) : Processor(gameArg, "Adaptive") { }

	static Registrar<Adaptive> registrar;

	void ProcessKeys(float fElapsedTime)
	{
		// Respond to user input
		if (game->GetKey(olc::Key::DOWN).bHeld) fAdaptiveBias -= 0.1f * fElapsedTime;
		if (game->GetKey(olc::Key::UP).bHeld) fAdaptiveBias += 0.1f * fElapsedTime;
		if (fAdaptiveBias > 1.5f) fAdaptiveBias = 1.5f;
		if (fAdaptiveBias < 0.5f) fAdaptiveBias = 0.5f;
	}

	void ProcessImage(float fElapsedTime, frame& input, frame& output)
	{
		for (int i = 0; i < nFrameWidth; i++)
		{
			for (int j = 0; j < nFrameHeight; j++)
			{
				float fRegionSum = 0.0f;

				for (int n = -2; n < +3; n++)
				{
					for (int m = -2; m < +3; m++)
					{
						fRegionSum += input.get(i + n, j + m);
					}
				}

				fRegionSum /= 25.0f;
				output.set(i, j, input.get(i, j) > (fRegionSum * fAdaptiveBias) ? 1.0f : 0.0f);
			}
		}
	}

	virtual void DrawUI(int x, int y, int stepy)
	{
		game->DrawString(x, y, "Change adaptive threshold bias with arrow UP and DOWN");
		game->DrawString(x, y + stepy, "Current value = " + std::to_string(fAdaptiveBias));
	}

private:
	float fAdaptiveBias = 1.1f;
};

Registrar<Adaptive> Adaptive::registrar(ProcessorInfo { "Adaptive", Processor::Create<Adaptive> });
