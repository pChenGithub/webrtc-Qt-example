#ifndef PEERCLIENTUI_H
#define PEERCLIENTUI_H

#include <QtWidgets/QMainWindow>
#include <QtCore\qstringlistmodel.h>
#include <QtCore\qelapsedtimer.h>
#include <QtCore\qstring.h>
#include <qtimezone.h>
#include <thread>
#include <regex>
#include <string>
#include <deque>
#include <thread>
#include "ui_peerclientui.h"
#include  "PeerConductor.h"
#include "VCWnd.h"

namespace render
{
	class VCWnd;
	class UiObserver;
}


// 自定义了一个客户端，是一个qt主界面
class PeerClientUI : 
	public QMainWindow,
	public render::UiObserver

{
	Q_OBJECT

public:

	PeerClientUI(QWidget *parent = 0);
	~PeerClientUI();
	
	void SetUIstatus(PeerStatus status);
// 初始化对等连接
	void InitializeClient();
// 初始化UI
	void initUi();
// 开始远端接收,视频
	virtual void StartLocalRenderer(webrtc::VideoTrackInterface* local_video);
	virtual void StopLocalRenderer();
// 开始远端接收,音频
	virtual void StartRemoteRenderer(webrtc::VideoTrackInterface* remote_video);
// 停止远端接收，音频
	virtual void StopRemoteRenderer();
// 更新对等列表客户端列表
	virtual void RefreshPeerList(Json::Value peers);
// 窗口关闭事件
	virtual void closeEvent(QCloseEvent* event);
// 定时器事件
	virtual void timerEvent(QTimerEvent *event);
// 日志打印
	virtual void log(LogType type, QString* log,bool onconsl);
// 消息提示
	virtual void msgbox(LogType type, QString* log);
private:
// 对等连接客户端，来自示例
	PeerConnectionClient* client_;
// 也是示例的一个类,修改了
	talk_base::scoped_refptr<PeerConductor> conductor_;
// 服务地址
	std::string server_;
// 端口
	int port_;
// 标记是否连接
	bool is_connected_;
// 对等连接的客户端，应该是名称
	QStringList peers_;
// 显示列表用的应该
	QStringListModel* model_;
// 定时器
	QElapsedTimer timer_;
	int timer_id_;
	int pending_timer_;
	
private slots:
// 连接
	void OnConnect();
// 断开连接
	void OnDisconnect();
	void OnTalk();
	void OnClear();
	void OnListClicked(const QModelIndex &index);
};

#endif // PEERCLIENTUI_H
