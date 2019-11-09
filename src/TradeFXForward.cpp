#include "TradeFXForward.h"
#include "PricerFXForward.h"

namespace minirisk {

ppricer_t TradeFXForward::pricer(const string& baseccy) const
{
    return ppricer_t(new PricerFXForward(*this, baseccy));
}

} // namespace minirisk
