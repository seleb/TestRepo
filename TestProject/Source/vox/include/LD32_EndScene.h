#pragma once

#include <Scene.h>

class LD32_EndScene : public Scene{
public:
	LD32_EndScene(Game * _game);

	void update(Step * _step) override;
};