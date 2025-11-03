// FfmpegCommand.cpp
#include "FfmpegCommand.h"

QString FfmpegCommand::build(const QString& input, const QString& output, const Profile& p) {
    QStringList args;
    args << "-y" << "-i" << input;
    args << "-vn"; // 無視影片流
    args << "-ar" << QString::number(p.sampleRate);
    args << "-sample_fmt" << p.sampleFmt;
    if (p.mapMetadata) args << "-map_metadata" << "0";
    if (p.channels > 0) args << "-ac" << QString::number(p.channels);
    if (!p.surroundLayout.isEmpty()) args << "-channel_layout" << p.surroundLayout;
    args << "-c:a" << "flac";
    args << output;
    return args.join(' ');
}
