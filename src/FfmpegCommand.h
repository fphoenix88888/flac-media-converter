#ifndef FFMPEGCOMMAND_H
#define FFMPEGCOMMAND_H

// FfmpegCommand.h
#pragma once
#include <QString>
#include "Profile.h"

namespace FfmpegCommand {
QString build(const QString& input, const QString& output, const Profile& p);
}


#endif // FFMPEGCOMMAND_H
