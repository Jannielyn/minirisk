#include "CurveDiscount.h"
#include "Market.h"
#include "Streamer.h"

#include <cmath>

namespace minirisk {

CurveDiscount::CurveDiscount(Market *mkt, const Date& today, const string& curve_name)
    : m_today(today)
    , m_name(curve_name)
    , m_rates(mkt->get_yield(curve_name.substr(ir_curve_discount_prefix.length(),3)))
{
}

// function df compute the discount factor as per section 5.4 requirement.
// return error when date input is beyond the last tenor or before the anchor date
double  CurveDiscount::df(const Date& t) const
{
    MYASSERT((!(t < m_today)), "Curve " << m_name << ", DF not available before anchor date " << m_today << ", requested "<< t);
	MYASSERT((!(t - m_today > m_rates.rbegin()->first)), "Curve " << m_name << ", DF not available beyond last tenor date " << 
		Date(m_today.get_serial() + m_rates.rbegin()->first)  << ", requested " << t);
	auto r = m_rates.upper_bound(t - m_today);
	unsigned T1 = r->first;
	double rT1 = r->second;
	unsigned T0 = (--r)->first;
	double rT0 = r->second;
	unsigned dt = t - m_today;
    return std::exp(static_cast<double>(-rT0 - (rT1 - rT0) / (T1 - T0) * (dt - T0)) / 365.0);
}
} // namespace minirisk
