#ifndef QVLCPLAYER_H
#define QVLCPLAYER_H

#include <QObject>
#include <QWindow>
#include <QQuickItem>
#ifdef WIN32
#include <Windows.h>
#define ssize_t SSIZE_T
#endif
#include <vlc/vlc.h>

class QVLCPlayer : public QObject
{
    Q_OBJECT
public:
    explicit QVLCPlayer(QObject *parent = nullptr);
    ~QVLCPlayer();

    // 设置渲染区域
    void setRect(QQuickItem* r);


signals:

public slots:
    // 调整窗口大小
    void resizewnd();

    int play(const QString& uri);
    int stop();

private:
    QWindow wnd_;
    QQuickItem* rect_ = nullptr;

    libvlc_instance_t* inst_ = nullptr;
    libvlc_media_t* media_ = nullptr;
    libvlc_media_player_t* player_ = nullptr;
};

#endif // QVLCPLAYER_H
