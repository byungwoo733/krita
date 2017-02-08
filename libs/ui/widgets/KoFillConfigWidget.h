/* This file is part of the KDE project
 * Made by Tomislav Lukman (tomislav.lukman@ck.tel.hr)
 * Copyright (C) 2012 Jean-Nicolas Artaud <jeannicolasartaud@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef FILLCONFIGWIDGET_H
#define FILLCONFIGWIDGET_H

#include "kritaui_export.h"

#include <QWidget>
#include <QSharedPointer>
#include <KoFlake.h>

class KoCanvasBase;
class KoShapeBackground;
class KoShape;

/// A widget for configuring the fill of a shape
class KRITAUI_EXPORT KoFillConfigWidget : public QWidget
{
    Q_OBJECT
    enum StyleButton {
        None = 0,
        Solid,
        Gradient,
        Pattern
    };

public:
    explicit KoFillConfigWidget(KoFlake::FillVariant fillVariant, QWidget *parent);
    ~KoFillConfigWidget();

    /// Returns the list of the selected shape
    /// If you need to use only one shape, call currentShape()
    virtual QList<KoShape*> currentShapes();

protected:
    void showEvent(QShowEvent *event);

private Q_SLOTS:
    void styleButtonPressed(int buttonId);

    void noColorSelected();

    /// apply color changes to the selected shape
    void colorChanged();

    /// the pattern of the fill changed, apply the changes
    void patternChanged(QSharedPointer<KoShapeBackground> background);

    virtual void shapeChanged();

    void slotUpdateFillTitle();

    void slotCanvasResourceChanged(int key, const QVariant &value);

    void slotSavePredefinedGradientClicked();

    void activeGradientChanged();
    void gradientResourceChanged();

    void slotGradientTypeChanged();
    void slotGradientRepeatChanged();

private:
    /// update the widget with the KoShape background
    void updateWidget(KoShape *shape);

    void uploadNewGradientBackground(const QGradient *gradient);
    void setNewGradientBackgroundToShape();
    void updateGradientSaveButtonAvailability();

    class Private;
    Private * const d;
};

#endif // FILLCONFIGWIDGET_H
