class Button
{
private:
    bool wasPressed = false;

public:
    Button()
    {
    }
    /**
     * If the button is being pressed and was not previously, returns true
     */
    bool operator()(bool isPressing)
    {
        bool returnval = false;
        if (isPressing && !wasPressed)
        {
            returnval = true;
        }
        wasPressed = isPressing;
        return returnval;
    }
};