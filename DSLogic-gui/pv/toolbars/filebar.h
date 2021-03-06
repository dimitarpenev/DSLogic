/*
 * This file is part of the DSLogic-gui project.
 * DSLogic-gui is based on PulseView.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 * Copyright (C) 2013 DreamSourceLab <dreamsourcelab@dreamsourcelab.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */


#ifndef DSLOGIC_PV_TOOLBARS_FILEBAR_H
#define DSLOGIC_PV_TOOLBARS_FILEBAR_H

#include <QToolBar>
#include <QToolButton>
#include <QAction>

#include "../sigsession.h"

namespace pv {
namespace toolbars {

class FileBar : public QToolBar
{
    Q_OBJECT

public:
    explicit FileBar(SigSession &session, QWidget *parent = 0);

    void enable_toggle(bool enable);

private:

    void session_error(
        const QString text, const QString info_text);
    void show_session_error(
        const QString text, const QString info_text);

signals:
    void load_file(QString);
    void save();
    void on_screenShot();

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionCapture_triggered();

private:
    bool _enable;
    SigSession& _session;

    QToolButton _file_button;

    QAction *_action_open;
    QAction *_action_save;
    QAction *_action_capture;

};

} // namespace toolbars
} // namespace pv

#endif // DSLOGIC_PV_TOOLBARS_FILEBAR_H
