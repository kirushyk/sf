/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
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
