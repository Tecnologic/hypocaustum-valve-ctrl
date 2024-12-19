/*
 * Copyright (c) 2013, Fabian Greif
 * Copyright (c) 2013, Kevin Läufer
 * Copyright (c) 2014-2018, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------
#include <modm/board.hpp>
#include <modm/debug.hpp>
#include <modm/processing.hpp>
#include <modm/platform.hpp>


// ----------------------------------------------------------------------------
// Set the log level
#undef MODM_LOG_LEVEL
#define MODM_LOG_LEVEL modm::log::INFO

Rtt rtt(0);
modm::IODeviceObjectWrapper<Rtt, modm::IOBuffer::DiscardIfFull> rtt_device(rtt);
// Set all four logger streams to use RTT
modm::log::Logger modm::log::debug(rtt_device);
modm::log::Logger modm::log::info(rtt_device);
modm::log::Logger modm::log::warning(rtt_device);
modm::log::Logger modm::log::error(rtt_device);

// ----------------------------------------------------------------------------
using namespace modm::literals;
// ----------------------------------------------------------------------------
int
main()
{
	Board::initialize();

	Board::LedOrange::setOutput();
	Board::LedGreen::setOutput();
	Board::LedBlue::setOutput();
	Board::LedRed::setOutput();
	
	Board::Button::setInput();

	Adc1::connect<GpioC0::In10>();
	Adc1::initialize<Board::SystemClock, 21_MHz, 0.1f>();

	MODM_LOG_INFO << "Current Control Test" << modm::endl;


	while (true)
	{

	}

	return 0;
}