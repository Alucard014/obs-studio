/******************************************************************************
    Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <wx/window.h>
#include <wx/msgdlg.h>
#include <obs.h>
#include "wx-wrappers.hpp"

gs_window WxToGSWindow(const wxWindow *wxwin)
{
	gs_window window;
#ifdef __APPLE__
	window.view     = (id)wxwin->GetHandle();
#elif _WIN32
	window.hwnd     = wxwin->GetHandle();
#else
	/* TODO: linux stuff */
#endif
	return window;
}

void OBSErrorBox(wxWindow *parent, const char *message, ...)
{
	va_list args;
	char output[4096];

	va_start(args, message);
	vsnprintf(output, 4095, message, args);
	va_end(args);

	wxMessageBox(message, "Error");
	blog(LOG_ERROR, "%s", output);
}
