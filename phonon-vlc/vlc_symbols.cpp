/*
 * VLC backend for the Phonon library
 * Copyright (C) 2007-2008  Tanguy Krotoff <tkrotoff@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "vlc_symbols.h"

#include <QtCore/QCoreApplication>

const char * getLibVLCFilename() {
	QString vlcDll(QCoreApplication::applicationDirPath() + "/libvlc-control");
	return vlcDll.toAscii().constData();
}

static LibLoader * libVLC = new LibLoader(getLibVLCFilename(), "libvlc_exception_init");

void * resolve(const char * name) {
	return libVLC->resolve(name);
}

void unloadLibVLC() {
	delete libVLC;
	libVLC = NULL;
}
