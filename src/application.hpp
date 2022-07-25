/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

typedef class Application
{
    public:
                                  Application();
        int                       Run();
        virtual int               Init();
        virtual int               MainLoop();
        virtual int               Release();
        virtual                   ~Application();
} *PApplication;

#endif
