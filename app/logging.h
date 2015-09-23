#include <QApplication>

#include <cstdio>
#include <chrono>
#include <ctime>
#include <algorithm>

std::string timeString(std::chrono::system_clock::time_point time) {
    std::time_t cTime = std::chrono::system_clock::to_time_t(time);
    std::string timeString = std::ctime(&cTime);

    timeString.erase(std::find_if(timeString.rbegin(), timeString.rend(),
        std::ptr_fun<int, int>(std::isgraph)).base(), timeString.end());

    return timeString;
}

QString messageToString(QtMsgType type, const char *msg) {
    QString logTime(timeString(std::chrono::system_clock::now()).c_str());
    QString logMsg(msg);
    QString logType;

    switch (type) {
    case QtDebugMsg:
        logType = QString("Debug");
        break;
    case QtWarningMsg:
        logType = QString("Warning");
        break;
    case QtCriticalMsg:
        logType = QString("Critical");
        break;
    case QtFatalMsg:
        logType = QString("Fatal");
        break;
    }

    return QString("[%1][%2] %3").arg(logType, logTime, logMsg);
}

void fileHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QByteArray localMsg = msg.toLocal8Bit();

    // TODO use messageToString
    // TODO write to a log file (generic path depending on system)
}

#ifdef QT_DEBUG
void consoleHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QByteArray localMsg = msg.toLocal8Bit();

    fprintf(stderr, "%s\n", messageToString(type, localMsg.constData()).toStdString().c_str());
}
#endif

// TODO implement errorLogHandler
void guiHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QByteArray localMsg = msg.toLocal8Bit();

    switch (type) {
    case QtDebugMsg:
        break;
    case QtWarningMsg:
        break;
    case QtCriticalMsg:
        break;
    case QtFatalMsg:
        break;
    }
}
