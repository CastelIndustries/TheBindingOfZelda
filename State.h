//
// Created by frangio on 23/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_STATE_H
#define THEBINDINGOFZELDAPROJECT_STATE_H

class State
{
public:
    virtual void Init() = 0;

    virtual void HandleInput() = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw(float dt) = 0;

    virtual void Pause() { }
    virtual void Resume() { }
};


#endif //THEBINDINGOFZELDAPROJECT_STATE_H
