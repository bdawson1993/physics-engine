#pragma once

class GameObject
{
public:
	GameObject()
	{

	};

protected:
	virtual void Update();
	virtual void KeyPress(char key);
	virtual void KeyRelase(char key);
	virtual void KeyHold(char key);
};
