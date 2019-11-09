#pragma once
#include "ICurve.h"

namespace minirisk {

struct Market;

struct CurveFXForward : ICurveFXForward
{
    virtual string name() const { return m_name; }

	CurveFXForward(Market *mkt, const Date& today, const string& curve_name);

    virtual Date today() const { return m_today; }

	virtual double fwd(const Date& t) const;

private:
    Date   m_today;
    string m_name;
	ptr_fxspot_curve_t m_fx_curve;
	ptr_disc_curve_t m_disc_curve_1;
	ptr_disc_curve_t m_disc_curve_2;
};

} // namespace minirisk
