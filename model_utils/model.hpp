#pragma once

#include "pin.hpp"

#include <vsm.hpp>
#if __cplusplus >= 202002L
#include <ranges>
#endif

namespace vsm
{
    class model : public IDSIMMODEL
    {
    protected:
        IINSTANCE *_instance = nullptr;

    public:
        INT isdigital(CHAR *pinname) override;
        VOID runctrl(RUNMODES mode) override;
        VOID actuate(REALTIME time, ACTIVESTATE newstate) override;
        BOOL indicate(REALTIME time, ACTIVEDATA *newstate) override;
        VOID callback(ABSTIME time, EVENTID eventid) override;
#if __cplusplus >= 202002L
        template <std::ranges::output_range<const vsm::pin &> Rng>
        static void init_pins(IINSTANCE *instance, Rng &&rng, std::string prefix, size_t start_value = 0)
        {
            size_t i = 0;
            for (auto &pin : rng)
                pin.init(instance, prefix + std::to_string((i++) + start_value));
        }

        template <std::ranges::output_range<const vsm::pin &> Rng>
        static uint32_t make_number(Rng &&r)
        {
            uint32_t res = 0;
            for (auto it = std::ranges::rbegin(r); it != std::ranges::rend(r); ++it)
            {
                res <<= 1;
                res += *it;
            }

            return res;
        }
#else
        template <typename Container>
        static void init_pins(IINSTANCE *instance, Container &&container, std::string prefix, size_t start_value = 0)
        {
            size_t i = 0;
            for (auto &pin : container)
                pin.init(instance, prefix + std::to_string((i++) + start_value));
        }

        template <typename Container>
        static uint32_t make_number(Container &&container)
        {
            uint32_t res = 0;
            for (auto it = container.rbegin(); it != container.rend(); ++it)
            {
                res <<= 1;
                res += *it;
            }

            return res;
        }
#endif
    public:
        model() = default;

        virtual ~model() = default;
    };
}
