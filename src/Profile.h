#ifndef PROFILE_H
#define PROFILE_H

// Profile.h
#pragma once
#include <QString>

struct Profile {
    QString name;
    int sampleRate = 48000;
    QString sampleFmt = "s24";
    bool mapMetadata = true;
    int channels = 2;
    QString surroundLayout; // optional
    QString notes;
    int version = 1;
};


#endif // PROFILE_H
