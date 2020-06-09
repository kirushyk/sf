/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#ifndef ACTOR_HPP
#define ACTOR_HPP

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

#endif
