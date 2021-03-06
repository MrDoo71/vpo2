/************************************************************************
 **
 **  @file   adddetnode.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   15 6, 2014
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2013-2015 Valentina project
 **  <https://github.com/valentina-project/vpo2> All Rights Reserved.
 **
 **  Valentina is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Valentina is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Valentina.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef ADDDETNODE_H
#define ADDDETNODE_H

#include <qcompilerdetection.h>
#include <QDomElement>
#include <QMetaObject>
#include <QObject>
#include <QString>
#include <QtGlobal>

#include "vundocommand.h"

class AddDetNode : public VUndoCommand
{
    Q_OBJECT
public:
    AddDetNode(const QDomElement &xml, VAbstractPattern *doc, const QString &drawName, QUndoCommand *parent = nullptr);
    virtual ~AddDetNode() Q_DECL_OVERRIDE;
    virtual void undo() Q_DECL_OVERRIDE;
    virtual void redo() Q_DECL_OVERRIDE;
private:
    Q_DISABLE_COPY(AddDetNode)

    QString m_drawName;

    QDomElement GetModelingSection() const;
};

#endif // ADDDETNODE_H
