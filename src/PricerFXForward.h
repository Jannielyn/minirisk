#pragma once

#include "Pricer.h"
#include "TradeFXForward.h"

namespace minirisk {

struct PricerFXForward : Pricer
{
    PricerFXForward(const TradeFXForward& trd, const string& baseccy);

    virtual double price(Market& m, const FixingDataServer& fds) const;

private:
    double m_amt;
    Date m_ft;
	Date m_st;
	double m_s;
	string m_ccy1;
    string m_ccy2;
};

} // namespace minirisk

