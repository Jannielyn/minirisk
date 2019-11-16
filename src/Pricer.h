#pragma once

#include "IPricer.h"

namespace minirisk {

// Pricer class for final ccy conversion
struct Pricer : IPricer
{
protected:
	Pricer(const string& baseccy) : m_baseccy(baseccy) {}
	string m_baseccy;
};

} // namespace minirisk
