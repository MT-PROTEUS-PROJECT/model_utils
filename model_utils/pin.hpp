#pragma once

#include <vsm.hpp>
#include <string>

namespace vsm
{
    class pin final
    {
    private:
        std::string _name;
        IDSIMPIN2 *_pin = nullptr;

    public:
        pin() = default;
        pin(IINSTANCE *instance, std::string name, BOOL required = true);

        void init(IINSTANCE *instance, std::string name, BOOL required = true);

        void set(STATE state);
        void set(ABSTIME time, RELTIME tgq, STATE state);

        STATE get() const;

        operator bool() const;

        ~pin() = default;
    };
}
