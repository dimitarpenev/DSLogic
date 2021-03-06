/*
 * This file is part of the DSLogic-gui project.
 * DSLogic-gui is based on PulseView.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 * Copyright (C) 2013 DreamSourceLab <dreamsourcelab@dreamsourcelab.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include <assert.h>

#include "signaldata.h"

namespace pv {
namespace data {

SignalData::SignalData(int num_probes) :
    _samplerate(0),
    _start_time(0),
    _num_probes(num_probes)
{
    assert(num_probes >= 0);
}

double SignalData::samplerate() const
{
	return _samplerate;
}

void SignalData::set_samplerate(double samplerate)
{
    assert(samplerate > 0);
    _samplerate = samplerate;
    clear();
}

double SignalData::get_start_time() const
{
	return _start_time;
}

int SignalData::get_num_probes() const
{
    return _num_probes;
}

void SignalData::set_num_probes(int num)
{
    assert(num >= 0);
    _num_probes = num;
}

} // namespace data
} // namespace pv
