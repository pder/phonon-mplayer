/*
 * VLC and MPlayer backends for the Phonon library
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

#include "VideoWidget.h"

#ifdef PHONON_VLC
	#include "vlc_loader.h"
	#include "vlc_symbols.h"
#endif	//PHONON_VLC

#ifdef PHONON_MPLAYER
	#include <mplayer/MPlayerProcess.h>
	#include <mplayer/MPlayerLoader.h>
#endif	//PHONON_MPLAYER

#include <QtGui/QWidget>
#include <QtCore/QtDebug>

namespace Phonon
{
namespace VLC_MPlayer
{

WId VideoWidget::_videoWidgetId = 0;

VideoWidget::VideoWidget(QWidget * parent)
	: QObject(parent) {

	_widget = new QWidget(parent);

	_videoWidgetId = _widget->winId();

	_aspectRatio = Phonon::VideoWidget::AspectRatioAuto;
	_brightness = 0;
	_scaleMode = Phonon::VideoWidget::FitInView;
	_contrast = 0;
	_hue = 0;
	_saturation = 0;
}

VideoWidget::~VideoWidget() {
}

Phonon::VideoWidget::AspectRatio VideoWidget::aspectRatio() const {
#ifdef PHONON_VLC
	if (_vlcCurrentMediaPlayer) {
		const char * aspectRatio = p_libvlc_video_get_aspect_ratio(_vlcCurrentMediaPlayer, _vlcException);
		qDebug() << "VideoWidget::aspectRatio():" << aspectRatio;
	}
#endif	//PHONON_VLC

	return _aspectRatio;
}

void VideoWidget::setAspectRatio(Phonon::VideoWidget::AspectRatio aspectRatio) {
	_aspectRatio = aspectRatio;

	switch(aspectRatio) {
	case Phonon::VideoWidget::AspectRatioAuto:
		break;
	case Phonon::VideoWidget::AspectRatioWidget:
		break;
	case Phonon::VideoWidget::AspectRatio4_3:
		break;
	case Phonon::VideoWidget::AspectRatio16_9:
		break;
	default:
		qCritical() << __FUNCTION__ << "error: unsupported AspectRatio:" << aspectRatio;
	}
}

qreal VideoWidget::brightness() const {
	return _brightness;
}

void VideoWidget::setBrightness(qreal brightness) {
	_brightness = brightness;

#ifdef PHONON_MPLAYER
	MPlayerProcess * process = MPlayerLoader::getCurrentMPlayerProcess();
	if (process) {
		process->writeToStdin("brightness " + QString::number(_brightness * 100) + " 1");
	}
#endif	//PHONON_MPLAYER
}

Phonon::VideoWidget::ScaleMode VideoWidget::scaleMode() const {
	return _scaleMode;
}

void VideoWidget::setScaleMode(Phonon::VideoWidget::ScaleMode scaleMode) {
	_scaleMode = scaleMode;

	switch (_scaleMode) {
	case Phonon::VideoWidget::FitInView:
		break;
	case Phonon::VideoWidget::ScaleAndCrop:
		break;
	default:
		qWarning() << __FUNCTION__ << "unknow Phonon::VideoWidget::ScaleMode:" << _scaleMode;
	}
}

qreal VideoWidget::contrast() const {
	return _contrast;
}

void VideoWidget::setContrast(qreal contrast) {
	_contrast = contrast;

#ifdef PHONON_MPLAYER
	MPlayerProcess * process = MPlayerLoader::getCurrentMPlayerProcess();
	if (process) {
		process->writeToStdin("contrast " + QString::number(_contrast * 100) + " 1");
	}
#endif	//PHONON_MPLAYER
}

qreal VideoWidget::hue() const {
	return _hue;
}

void VideoWidget::setHue(qreal hue) {
	_hue = hue;

#ifdef PHONON_MPLAYER
	MPlayerProcess * process = MPlayerLoader::getCurrentMPlayerProcess();
	if (process) {
		process->writeToStdin("hue " + QString::number(_hue * 100) + " 1");
	}
#endif	//PHONON_MPLAYER
}

qreal VideoWidget::saturation() const {
	return _saturation;
}

void VideoWidget::setSaturation(qreal saturation) {
	_saturation = saturation;

#ifdef PHONON_MPLAYER
	MPlayerProcess * process = MPlayerLoader::getCurrentMPlayerProcess();
	if (process) {
		process->writeToStdin("saturation " + QString::number(_saturation * 100) + " 1");
	}
#endif	//PHONON_MPLAYER
}

QWidget * VideoWidget::widget() {
	return _widget;
}

}}	//Namespace Phonon::VLC_MPlayer