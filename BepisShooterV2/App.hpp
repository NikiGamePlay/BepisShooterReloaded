#pragma once

class App {
public:
	virtual void Run() = 0;
	virtual void Init() = 0;
private:
	virtual void mainLoop() = 0;};
