#include "Button.h"
#include <functional>

class Toggleable
{
private:
    Button pressing;
    bool toggle = false;

public:
    Toggleable(bool toggle) : toggle{toggle} {}
    /**
     * If the button is being pressed and was not previously,runs the lambda
     */
    bool calc(bool isPressing, std::function<void(bool)> run)
    {
        bool ispressing = pressing(isPressing);
        if (ispressing)
        {
            run(toggle);
            toggle = !toggle;
        }
        return ispressing;
    }
    bool getState()
    {
        return toggle;
    }
};