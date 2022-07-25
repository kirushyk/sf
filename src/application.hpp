/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#pragma once

class Application
{
    public:
                                  Application();
        int                       Run();
        virtual int               Init();
        virtual int               MainLoop();
        virtual int               Release();
        virtual                   ~Application();
};
