/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
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
