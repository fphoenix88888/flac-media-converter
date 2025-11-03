#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

// ProfileManager.h
#pragma once
#include <QVector>
#include "Profile.h"

class ProfileManager {
public:
    static QVector<Profile> loadBuiltins();
    static QVector<Profile> loadUserProfiles();
    static bool saveUserProfiles(const QVector<Profile>& profiles);
};


#endif // PROFILEMANAGER_H
