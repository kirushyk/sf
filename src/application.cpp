/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#include "sf.hpp"

Application::Application()
{
}

int Application::Init()
{
    return 0;
}

int Application::MainLoop()
{
    return 0;
}

int Application::Release()
{
    return 0;
}

int Application::Run()
{
    Init();
    MainLoop();
    Release();
    return 0;
}

Application::~Application()
{
}
