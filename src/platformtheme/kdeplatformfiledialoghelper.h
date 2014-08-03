/*  This file is part of the KDE libraries
 *  Copyright 2013 Aleix Pol Gonzalez <aleixpol@blue-systems.com>
 *
 *  This library is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2 of the License or ( at
 *  your option ) version 3 or, at the discretion of KDE e.V. ( which shall
 *  act as a proxy as in section 14 of the GPLv3 ), any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#ifndef KDEPLATFORMFILEDIALOGHELPER_H
#define KDEPLATFORMFILEDIALOGHELPER_H

#include <qpa/qplatformdialoghelper.h>
#include "kdeplatformfiledialogbase_p.h"

class KFileWidget;
class QDialogButtonBox;
class KDEPlatformFileDialog : public KDEPlatformFileDialogBase
{
    Q_OBJECT
public:
    friend class KDEPlatformFileDialogHelper;

    explicit KDEPlatformFileDialog();
    QUrl directory();
    void selectNameFilter(const QString &filter);
    void setDirectory(const QUrl &directory);
    void selectFile(const QUrl &filename);
    void setViewMode(QFileDialogOptions::ViewMode view);
    void setFileMode(QFileDialogOptions::FileMode mode);
    QString selectedNameFilter();
    QList<QUrl> selectedFiles();

protected:
    KFileWidget *m_fileWidget;
};

class KDEPlatformFileDialogHelper : public QPlatformFileDialogHelper
{
public:
    KDEPlatformFileDialogHelper();
    virtual ~KDEPlatformFileDialogHelper();

    void initializeDialog();

    virtual bool defaultNameFilterDisables() const Q_DECL_OVERRIDE;
    virtual QUrl directory() const Q_DECL_OVERRIDE;
    virtual QList<QUrl> selectedFiles() const Q_DECL_OVERRIDE;
    virtual QString selectedNameFilter() const Q_DECL_OVERRIDE;
    virtual void selectNameFilter(const QString &filter) Q_DECL_OVERRIDE;
    virtual void selectFile(const QUrl &filename) Q_DECL_OVERRIDE;
    virtual void setFilter() Q_DECL_OVERRIDE;
    virtual void setDirectory(const QUrl &directory) Q_DECL_OVERRIDE;
    virtual bool isSupportedUrl(const QUrl& url) const Q_DECL_OVERRIDE;

    virtual void exec() Q_DECL_OVERRIDE;
    virtual void hide() Q_DECL_OVERRIDE;
    virtual bool show(Qt::WindowFlags windowFlags, Qt::WindowModality windowModality, QWindow *parent) Q_DECL_OVERRIDE;

private:
    KDEPlatformFileDialogBase *m_dialog;
};

#endif // KDEPLATFORMFILEDIALOGHELPER_H