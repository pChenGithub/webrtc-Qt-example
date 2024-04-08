#ifndef VCWND_H
#define VCWND_H
#pragma once
#include "QtWidgets\qmainwindow.h"
#include "QtGui\qpainter.h"
#include "UiObserver.h"
#include "QtCore\qpoint.h"
namespace render
{
	class UiObserver;
}
namespace render
{
// 现实视频的窗口
	class VCWnd :
		public QMainWindow
	{
	public:
// 主UI，是否本地
		explicit VCWnd(render::UiObserver* UI, bool islocal);
		~VCWnd();
	protected:
		void paintEvent(QPaintEvent* event);
		void closeEvent(QCloseEvent* event);
	private:
		void LocalFrameRenderer();
		void RemoteFrameRenderer();
		bool is_local_;
		static QPoint wnd_location_;
// 主UI
		render::UiObserver* UI_;
	};
}

#endif

