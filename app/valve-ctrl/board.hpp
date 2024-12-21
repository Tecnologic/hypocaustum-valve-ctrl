/*
//////////////////////////////////////////////////////////////////////
// _   _                                       _                    //
//| | | |_   _ _ __   ___   ___ __ _ _   _ ___| |_ _   _ _ __ ___   //
//| |_| | | | | '_ \ / _ \ / __/ _` | | | / __| __| | | | '_ ` _ \  //
//|  _  | |_| | |_) | (_) | (_| (_| | |_| \__ \ |_| |_| | | | | | | //
//|_| |_|\__, | .__/ \___/ \___\__,_|\__,_|___/\__|\__,_|_| |_| |_| //
//       |___/|_|                                                   //
//////////////////////////////////////////////////////////////////////

A under floor heating control system for DC-Mootor Vales like HmIP VDMOT
This project is based on the modm library.

Copyright(C) 2024 Alexander Evers

This program is free software;
you can redistribute it and / or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation;
either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program;
if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110 - 1301, USA
*/
// ----------------------------------------------------------------------------

#ifndef MODM_VALVE_CTRL_BOARD_HPP
#define MODM_VALVE_CTRL_BOARD_HPP

#include <modm/platform.hpp>
#include <modm/architecture/interface/clock.hpp>

using namespace modm::platform;

// ----------------------------------------------------------------------------
// Set the log level
#undef MODM_LOG_LEVEL
#define MODM_LOG_LEVEL modm::log::INFO

// ----------------------------------------------------------------------------
namespace Board
{
/// @ingroup modm_board_disco_f407vg
/// @{
using namespace modm::literals;

/// STM32F407 running at 168MHz generated from the external 8MHz crystal
struct SystemClock
{
	static constexpr uint32_t Frequency = 168_MHz;
	static constexpr uint32_t Ahb = Frequency;
	static constexpr uint32_t Apb1 = Frequency / 4;
	static constexpr uint32_t Apb2 = Frequency / 2;

	static constexpr uint32_t Adc = Apb2;

	static constexpr uint32_t Can1   = Apb1;
	static constexpr uint32_t Can2   = Apb1;

	static constexpr uint32_t Spi1   = Apb2;
	static constexpr uint32_t Spi2   = Apb1;
	static constexpr uint32_t Spi3   = Apb1;
	static constexpr uint32_t Spi4   = Apb2;
	static constexpr uint32_t Spi5   = Apb2;
	static constexpr uint32_t Spi6   = Apb2;

	static constexpr uint32_t Usart1 = Apb2;
	static constexpr uint32_t Usart2 = Apb1;
	static constexpr uint32_t Usart3 = Apb1;
	static constexpr uint32_t Uart4  = Apb1;
	static constexpr uint32_t Uart5  = Apb1;
	static constexpr uint32_t Usart6 = Apb2;
	static constexpr uint32_t Uart7  = Apb1;
	static constexpr uint32_t Uart8  = Apb1;

	static constexpr uint32_t I2c1   = Apb1;
	static constexpr uint32_t I2c2   = Apb1;
	static constexpr uint32_t I2c3   = Apb1;

	static constexpr uint32_t Apb1Timer = Apb1 * 2;
	static constexpr uint32_t Apb2Timer = Apb2 * 2;
	static constexpr uint32_t Timer1  = Apb2Timer;
	static constexpr uint32_t Timer2  = Apb1Timer;
	static constexpr uint32_t Timer3  = Apb1Timer;
	static constexpr uint32_t Timer4  = Apb1Timer;
	static constexpr uint32_t Timer5  = Apb1Timer;
	static constexpr uint32_t Timer6  = Apb1Timer;
	static constexpr uint32_t Timer7  = Apb1Timer;
	static constexpr uint32_t Timer8  = Apb2Timer;
	static constexpr uint32_t Timer9  = Apb2Timer;
	static constexpr uint32_t Timer10 = Apb2Timer;
	static constexpr uint32_t Timer11 = Apb2Timer;
	static constexpr uint32_t Timer12 = Apb1Timer;
	static constexpr uint32_t Timer13 = Apb1Timer;
	static constexpr uint32_t Timer14 = Apb1Timer;

	static constexpr uint32_t Usb = 48_MHz;
	static constexpr uint32_t Iwdg = Rcc::LsiFrequency;

	static bool inline
	enable()
	{
		Rcc::enableExternalCrystal();	// 8MHz
		const Rcc::PllFactors pllFactors{
			.pllM = 4,		// 8MHz / M=4 -> 2MHz
			.pllN = 168,	// 2MHz * N=168 -> 336MHz
			.pllP = 2,		// 336MHz / P=2 -> 168MHz = F_cpu
			.pllQ = 7		// 336MHz / Q=7 ->  48MHz = F_usb
		};
		Rcc::enablePll(Rcc::PllSource::ExternalCrystal, pllFactors);
		// set flash latency for 168MHz
		Rcc::setFlashLatency<Frequency>();
		// switch system clock to PLL output
		Rcc::enableSystemClock(Rcc::SystemClockSource::Pll);
		Rcc::setAhbPrescaler(Rcc::AhbPrescaler::Div1);
		// APB1 has max. 42MHz
		// APB2 has max. 84MHz
		Rcc::setApb1Prescaler(Rcc::Apb1Prescaler::Div4);
		Rcc::setApb2Prescaler(Rcc::Apb2Prescaler::Div2);
		// update frequencies for busy-wait delay functions
		Rcc::updateCoreFrequency<Frequency>();

		return true;
	}
};

using Button = GpioInputA0;
using ClockOut = GpioOutputA8;
using SystemClockOut = GpioOutputC9;

using LedOrange = GpioOutputD13;	// User LED 3
using LedGreen  = GpioOutputD12;	// User LED 4
using LedRed    = GpioOutputD14;	// User LED 5
using LedBlue   = GpioOutputD15;	// User LED 6

using Leds = SoftwareGpioPort< LedGreen, LedBlue, LedRed, LedOrange >;
/// @}


namespace usb
{
/// @ingroup modm_board_disco_f407vg
/// @{
using Vbus = GpioInputA9;	// VBUS_FS: USB_OTG_HS_VBUS
using Id = GpioA10;			// OTG_FS_ID: USB_OTG_FS_ID
using Dm = GpioA11;			// OTG_FS_DM: USB_OTG_FS_DM
using Dp = GpioA12;			// OTG_FS_DP: USB_OTG_FS_DP

using Overcurrent = GpioInputD5;	// OTG_FS_OverCurrent
using Power = GpioOutputC0;			// OTG_FS_PowerSwitchOn

using Device = UsbFs;
/// @}
}


}

#endif // MODM_VALVE_CTRL_BOARD_HPP
