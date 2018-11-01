#pragma once
#include <iostream>

class InputHandler
{
private:
	InputHandler() {}
	static InputHandler* s_pInstance;
public:
	

	void Update();
	void clean();
	void instaliseJoystick();
	
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
			return s_pInstance;
		}
		return s_pInstance;
	}

};

typedef InputHandler TheInputHandler;
