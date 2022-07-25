/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#pragma once

typedef class Actor: public Sprite
{
    public:
        explicit                  Actor(World *_Owner);
        virtual void              Iteration();
        virtual void              Act();
        bool                      CanMoveLeft();
        bool                      CanMoveRight();
        bool                      CanFallLeft();
        bool                      CanFallRight();
        bool                      OnTheFloor();
        Vector                    Speed;
        bool                      Ricochet;
} *PActor;
