/*
 * MPlayer backend for the Phonon library
 * Copyright (C) 2007-2008  Tanguy Krotoff <tkrotoff@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PHONON_MPLAYER_AUDIOOUTPUT_H
#define PHONON_MPLAYER_AUDIOOUTPUT_H

#include <phonon/audiooutputinterface.h>

#include <QtCore/QObject>

namespace Phonon
{
namespace MPlayer
{

/**
 *
 *
 * @author Tanguy Krotoff
 */
class AudioOutput : public QObject, public AudioOutputInterface {
	Q_OBJECT
	Q_INTERFACES(Phonon::AudioOutputInterface)
public:

	AudioOutput(QObject * parent);
	~AudioOutput();

	qreal volume() const;
	void setVolume(qreal volume);

	int outputDevice() const;
	bool setOutputDevice(int);

signals:

	void volumeChanged(qreal volume);

private slots:

	void volumeChangedSlotInternal(int volume);

private:

	qreal _volume;
};

}}	//Namespace Phonon::MPlayer

#endif	//PHONON_MPLAYER_AUDIOOUTPUT_H
