/*
 * Copyright (c) 2017-2018, 2021, Niklas Hauser
 * Copyright (c) 2022, Andrey Kunitsyn
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#pragma once

#include "base.hpp"
#include "data.hpp"
#include "static.hpp"

namespace modm::platform
{

/// @ingroup modm_platform_gpio
using GpioUnused = GpioStatic<detail::DataUnused>;
/**
 * Dummy implementation of an I/O pin.
 *
 * This class can be used when a pin is not required. All functions
 * are dummy functions which do nothing. `read()` will always
 * return `false`.
 *
 * For example when creating a software SPI with the modm::SoftwareSimpleSpi
 * class and the return channel (MISO - Master In Slave Out) is not needed,
 * a good way is to use this class as a parameter when defining the
 * SPI class.
 *
 * Example:
 * @code
 * #include <modm/architecture/platform.hpp>
 *
 * namespace pin
 * {
 *     typedef GpioOutputD7 Clk;
 *     typedef GpioOutputD5 Mosi;
 * }
 *
 * modm::SoftwareSpiMaster< pin::Clk, pin::Mosi, GpioUnused > Spi;
 *
 * ...
 * Spi::write(0xaa);
 * @endcode
 *
 * @author	Fabian Greif
 * @author	Niklas Hauser
 * @ingroup	modm_platform_gpio
 */
template<>
class GpioStatic<detail::DataUnused> : public Gpio, public ::modm::GpioIO
{
public:
	using Output = GpioUnused;
	using Input = GpioUnused;
	using IO = GpioUnused;
	using Type = GpioUnused;
	using Data = detail::DataUnused;
	static constexpr bool isInverted = false;
	static constexpr Port port = Port(-1);
	static constexpr uint8_t pin = uint8_t(-1);
	static constexpr uint16_t mask = 0;
protected:
	static void setAlternateFunction(uint8_t) {}
	static void setAlternateFunction() {}
	static void setAnalogInput() {}
public:
	// GpioOutput
	static void setOutput() {}
	static void setOutput(bool) {}
	static void setOutput(OutputType, OutputSpeed = OutputSpeed::MHz50) {}
	static void configure(OutputType, OutputSpeed = OutputSpeed::MHz50) {}
	static void set() {}
	static void set(bool) {}
	static void reset() {}
	static bool isSet() { return false; }
	static void toggle() {}

	// GpioInput
	static void setInput() {}
	static void setInput(InputType) {}
	static void configure(InputType) {}
	static bool read() { return false; }

	// GpioIO
	static Direction getDirection() { return Direction::In; }
	static void lock() {}
	static void disconnect() {}

public:
	struct BitBang
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::BitBang;
	};
	struct A16
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::A16;
	};
	struct A17
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::A17;
	};
	struct A18
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::A18;
	};
	struct A19
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::A19;
	};
	struct A20
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::A20;
	};
	struct A21
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::A21;
	};
	struct A22
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::A22;
	};
	struct A23
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::A23;
	};
	struct Af1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Af1;
	};
	struct Ale
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ale;
	};
	struct Bkin
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Bkin;
	};
	struct Ch1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ch1;
	};
	struct Ch1n
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ch1n;
	};
	struct Ch2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ch2;
	};
	struct Ch2n
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ch2n;
	};
	struct Ch3
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ch3;
	};
	struct Ch3n
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ch3n;
	};
	struct Ch4
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ch4;
	};
	struct Ck
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ck;
	};
	struct Ckin
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ckin;
	};
	struct Cle
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Cle;
	};
	struct Clk
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Clk;
	};
	struct Cmd
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Cmd;
	};
	struct Col
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Col;
	};
	struct Crs
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Crs;
	};
	struct Cts
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Cts;
	};
	struct D0
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D0;
	};
	struct D1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D1;
	};
	struct D10
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D10;
	};
	struct D11
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D11;
	};
	struct D12
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D12;
	};
	struct D13
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D13;
	};
	struct D14
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D14;
	};
	struct D15
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D15;
	};
	struct D2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D2;
	};
	struct D3
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D3;
	};
	struct D4
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D4;
	};
	struct D5
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D5;
	};
	struct D6
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D6;
	};
	struct D7
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D7;
	};
	struct D8
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D8;
	};
	struct D9
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::D9;
	};
	struct Da0
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da0;
	};
	struct Da1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da1;
	};
	struct Da10
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da10;
	};
	struct Da11
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da11;
	};
	struct Da12
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da12;
	};
	struct Da13
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da13;
	};
	struct Da14
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da14;
	};
	struct Da15
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da15;
	};
	struct Da2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da2;
	};
	struct Da3
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da3;
	};
	struct Da4
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da4;
	};
	struct Da5
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da5;
	};
	struct Da6
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da6;
	};
	struct Da7
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da7;
	};
	struct Da8
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da8;
	};
	struct Da9
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Da9;
	};
	struct Dm
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Dm;
	};
	struct Dp
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Dp;
	};
	struct Etr
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Etr;
	};
	struct Extsd
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Extsd;
	};
	struct Hsync
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Hsync;
	};
	struct Id
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Id;
	};
	struct In0
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In0;
	};
	struct In1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In1;
	};
	struct In10
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In10;
	};
	struct In11
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In11;
	};
	struct In12
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In12;
	};
	struct In13
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In13;
	};
	struct In14
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In14;
	};
	struct In15
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In15;
	};
	struct In2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In2;
	};
	struct In3
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In3;
	};
	struct In4
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In4;
	};
	struct In5
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In5;
	};
	struct In6
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In6;
	};
	struct In7
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In7;
	};
	struct In8
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In8;
	};
	struct In9
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::In9;
	};
	struct Jtck
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Jtck;
	};
	struct Jtdi
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Jtdi;
	};
	struct Jtdo
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Jtdo;
	};
	struct Jtms
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Jtms;
	};
	struct Jtrst
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Jtrst;
	};
	struct Mck
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Mck;
	};
	struct Mco1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Mco1;
	};
	struct Mco2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Mco2;
	};
	struct Mdc
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Mdc;
	};
	struct Mdio
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Mdio;
	};
	struct Miso
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Miso;
	};
	struct Mosi
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Mosi;
	};
	struct Nbl0
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Nbl0;
	};
	struct Nbl1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Nbl1;
	};
	struct Nce2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Nce2;
	};
	struct Ne1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ne1;
	};
	struct Nl
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Nl;
	};
	struct Noe
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Noe;
	};
	struct Nss
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Nss;
	};
	struct Nwait
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Nwait;
	};
	struct Nwe
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Nwe;
	};
	struct Osc32in
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Osc32in;
	};
	struct Osc32out
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Osc32out;
	};
	struct Oscin
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Oscin;
	};
	struct Oscout
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Oscout;
	};
	struct Out1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Out1;
	};
	struct Out2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Out2;
	};
	struct Pixclk
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Pixclk;
	};
	struct Ppsout
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ppsout;
	};
	struct Rcccrsdv
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rcccrsdv;
	};
	struct Refclk
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Refclk;
	};
	struct Refin
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Refin;
	};
	struct Rts
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rts;
	};
	struct Rx
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rx;
	};
	struct Rxclk
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rxclk;
	};
	struct Rxd0
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rxd0;
	};
	struct Rxd1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rxd1;
	};
	struct Rxd2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rxd2;
	};
	struct Rxd3
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rxd3;
	};
	struct Rxdv
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rxdv;
	};
	struct Rxer
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Rxer;
	};
	struct Sck
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Sck;
	};
	struct Scl
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Scl;
	};
	struct Sd
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Sd;
	};
	struct Sda
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Sda;
	};
	struct Smba
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Smba;
	};
	struct Sof
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Sof;
	};
	struct Swclk
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Swclk;
	};
	struct Swdio
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Swdio;
	};
	struct Swo
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Swo;
	};
	struct Traceclk
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Traceclk;
	};
	struct Traced0
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Traced0;
	};
	struct Traced1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Traced1;
	};
	struct Traced2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Traced2;
	};
	struct Traced3
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Traced3;
	};
	struct Tx
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Tx;
	};
	struct Txclk
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Txclk;
	};
	struct Txd0
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Txd0;
	};
	struct Txd1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Txd1;
	};
	struct Txd2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Txd2;
	};
	struct Txd3
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Txd3;
	};
	struct Txen
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Txen;
	};
	struct Ulpick
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpick;
	};
	struct Ulpid0
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpid0;
	};
	struct Ulpid1
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpid1;
	};
	struct Ulpid2
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpid2;
	};
	struct Ulpid3
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpid3;
	};
	struct Ulpid4
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpid4;
	};
	struct Ulpid5
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpid5;
	};
	struct Ulpid6
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpid6;
	};
	struct Ulpid7
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpid7;
	};
	struct Ulpidir
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpidir;
	};
	struct Ulpinxt
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpinxt;
	};
	struct Ulpistp
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ulpistp;
	};
	struct Vbus
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Vbus;
	};
	struct Vsync
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Vsync;
	};
	struct Wkup
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Wkup;
	};
	struct Ws
	{
		using Data = detail::DataUnused;
		static constexpr platform::Gpio::Signal Signal = platform::Gpio::Signal::Ws;
	};
};

} // namespace modm::platform