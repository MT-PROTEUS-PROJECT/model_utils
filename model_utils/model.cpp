#include "model.hpp"

namespace vsm
{
    INT model::isdigital(CHAR *pinname)
    {
        return 1;
    }

    BOOL model::indicate(REALTIME time, ACTIVEDATA *newstate)
    {
        return FALSE;
    }

    VOID model::runctrl(RUNMODES mode) {}
    VOID model::actuate(REALTIME time, ACTIVESTATE newstate) {}
    VOID model::callback(ABSTIME time, EVENTID eventid) {}
}
