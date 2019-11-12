#pragma once
#include "ICurve.h"
#include <map>

namespace minirisk {

struct Market;

typedef std::map<unsigned, double> disc_rates_t;

struct CurveDiscount : ICurveDiscount
{
    virtual string name() const { return m_name; }

    CurveDiscount(Market *mkt, const Date& today, const string& curve_name);

    // compute the discount factor
    double df(const Date& t) const;

    virtual Date today() const { return m_today; }

private:
    Date   m_today;
    string m_name;
    // double m_rate;
	disc_rates_t m_rates;
};

} // namespace minirisk
