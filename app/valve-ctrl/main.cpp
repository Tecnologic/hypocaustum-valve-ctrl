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
#include <modm/board.hpp>
#include <modm/debug.hpp>
#include <modm/processing.hpp>
#include <modm/platform.hpp>


// ----------------------------------------------------------------------------
using namespace modm::literals;
// ----------------------------------------------------------------------------
int
main()
{
	Board::initialize();


	while (true)
	{
		Board::LedGreen::set();
		modm::delay_ms(500);
		Board::LedGreen::reset();
		modm::delay_ms(500);
	}

	return 0;
}