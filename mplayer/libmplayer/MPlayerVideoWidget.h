/*
 * MPlayer backend for the Phonon library
 * Copyright (C) 2006-2008  Ricardo Villalba <rvm@escomposlinux.org>
 * Copyright (C) 2007-2010  Tanguy Krotoff <tkrotoff@gmail.com>
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

#ifndef PHONON_MPLAYER_MPLAYERVIDEOWIDGET_H
#define PHONON_MPLAYER_MPLAYERVIDEOWIDGET_H

#include "WidgetNoPaintEvent.h"

#include <QtGui/QWidget>

class QResizeEvent;

namespace Phonon
{
namespace MPlayer
{

class MPlayerLayer : public WidgetNoPaintEvent {
	Q_OBJECT
public:
	MPlayerLayer(QWidget * parent);
	~MPlayerLayer();

	void playingStarted();
	void playingStopped();

protected:
	virtual void paintEvent(QPaintEvent *e);

private:
	bool playing;
};

/**
 * Widget where to show the MPlayer video.
 *
 * @see VideoWidget
 * @author Tanguy Krotoff
 */
class MPlayerVideoWidget : public WidgetNoPaintEvent {
	Q_OBJECT
public:

	MPlayerVideoWidget(QWidget * parent);
	~MPlayerVideoWidget();

	void setVideoSize(const QSize & videoSize);
	void setAspectRatio(double aspectRatio);
	void setScaleAndCropMode(bool scaleAndCrop);

	WId winId() const;

	QSize sizeHint() const;

	MPlayerLayer * _videoLayer;

private:

	void updateVideoWindow() const;

	void resizeEvent(QResizeEvent * event);


	double _aspectRatio;

	/** Scale and crop mode. */
	bool _scaleAndCrop;

	/** Original size of the video, needed for sizeHint(). */
	QSize _videoSize;
};

}}	//Namespace Phonon::MPlayer

#endif	//PHONON_MPLAYER_MPLAYERVIDEOWIDGET_H
