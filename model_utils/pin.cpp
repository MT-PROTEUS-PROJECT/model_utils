#include "pin.hpp"

namespace vsm
{
    pin::pin(IINSTANCE *instance, std::string name, BOOL required) : _name(std::move(name)), _pin(instance->getdsimpin(_name.data(), required))
    {
        _pin->setstate(SLO);
    }

    void pin::init(IINSTANCE *instance, std::string name, BOOL required)
    {
        if (_pin)
            return;

        _name = std::move(name);
        _pin = instance->getdsimpin(_name.data(), required);
        set(SLO);
    }

    void pin::set(STATE state)
    {
        _pin->setstate(state);
    }

    void pin::set(ABSTIME time, RELTIME tgq, STATE state)
    {
        _pin->setstate(time, tgq, state);
    }

    STATE pin::get() const
    {
        return _pin->getstate();
    }

    pin::operator bool() const
    {
        return _pin->isactive();
    }
}
