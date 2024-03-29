/*
 * (c) 2009, 2010 Kyrylo V. Polezhaiev
 *
 * Strange fruits
 *
 */

#pragma once

class World
{
    public:
        explicit                  World();
        void                      Iteration(uint32_t _ElapsedTime);
                                  ~World();
        Vector                    ScreenCenter;
        float                     Width,
                                  Height;
        Color                     Background;
        uint32_t                  AmountOfObjects,
                                  ElapsedTime;
        std::list<Root *>         Objects;
        std::list<Actor *>        Actors;
        float                     Gravity;
};
