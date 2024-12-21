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

#include "board.hpp"
#include <modm/debug.hpp>
#include <modm/architecture/interface/delay.hpp>
#include <modm/architecture/interface/accessor.hpp>
#include <modm/architecture/interface/assert.hpp>


// ----------------------------------------------------------------------------
// Logging output via RTT
Rtt rtt(0);
modm::IODeviceObjectWrapper<Rtt, modm::IOBuffer::DiscardIfFull> rtt_device(rtt);
// Set all four logger streams to use RTT
modm::log::Logger modm::log::debug(rtt_device);
modm::log::Logger modm::log::info(rtt_device);
modm::log::Logger modm::log::warning(rtt_device);
modm::log::Logger modm::log::error(rtt_device);

// ----------------------------------------------------------------------------
// Board secifiv init code
namespace Board {
void
initialize()
{
	SystemClock::enable();
	SysTickTimer::initialize<SystemClock>();

	Leds::setOutput(modm::Gpio::Low);

	Button::setInput();

	MODM_LOG_INFO << "Board initialized" << modm::endl;
}

inline void
initializeADC()
{
	Adc1::connect<AdcCurIn>();
	Adc1::initialize<Board::SystemClock, 21_MHz, 0.1f>();

}

void
initializeUsbFs(uint8_t priority = 3)
{
	usb::Device::initialize<SystemClock>(priority);
	usb::Device::connect<usb::Dm::Dm, usb::Dp::Dp, usb::Id::Id>();

	usb::Overcurrent::setInput();
	usb::Vbus::setInput();
	// Enable VBUS sense (B device) via pin PA9
	USB_OTG_FS->GCCFG &= ~USB_OTG_GCCFG_NOVBUSSENS;
	USB_OTG_FS->GCCFG |= USB_OTG_GCCFG_VBUSBSEN;
}
} // namespace Board

// ----------------------------------------------------------------------------
// modm fault handler
modm_extern_c void
modm_abandon(const modm::AssertionInfo &info)
{
	(void)info;
	Board::Leds::setOutput();
	for(int times=10; times>=0; times--)
	{
		Board::Leds::write(1);
		modm::delay_ms(20);
		Board::Leds::write(0);
		modm::delay_ms(180);
	}
}
