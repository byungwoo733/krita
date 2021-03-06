/*
 *  Copyright (c) 2009 Boudewijn Rempt <boud@valdyas.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef KIS_TOOL_UTILS_H
#define KIS_TOOL_UTILS_H

#include <QPoint>

#include <KoColor.h>
#include <kis_types.h>
#include <kritaui_export.h>
#include <kis_selection.h>


namespace KisToolUtils {

struct KRITAUI_EXPORT ColorPickerConfig {
    ColorPickerConfig();

    bool toForegroundColor;
    bool updateColor;
    bool addPalette;
    bool normaliseValues;
    bool sampleMerged;
    int radius;

    void save(bool defaultActivation = true) const;
    void load(bool defaultActivation = true);
private:
    static const QString CONFIG_GROUP_NAME;
};

/**
 * return the color at the given position on the given paint device.
 */
bool KRITAUI_EXPORT pick(KisPaintDeviceSP dev, const QPoint& pos, KoColor *color, int radius = 1);

/**
 * Recursively search a node with a non-transparent pixel
 */
KisNodeSP KRITAUI_EXPORT findNode(KisNodeSP node, const QPoint &point, bool wholeGroup, bool editableOnly = true);

/**
 * return true if success
 * Clears the image. Selection is optional, use 0 to clear everything.
 */
bool KRITAUI_EXPORT clearImage(KisImageSP image, KisNodeSP node, KisSelectionSP selection);
}

#endif // KIS_TOOL_UTILS_H
