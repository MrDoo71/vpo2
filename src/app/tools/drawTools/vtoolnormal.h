/************************************************************************
 **
 **  @file   vtoolnormal.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   November 15, 2013
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2013 Valentina project
 **  <https://bitbucket.org/dismine/valentina> All Rights Reserved.
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

#ifndef VTOOLNORMAL_H
#define VTOOLNORMAL_H

#include "vtoollinepoint.h"

/**
 * @brief The VToolNormal class tool for creation point on normal. Normal begin from first point of line.
 */
class VToolNormal : public VToolLinePoint
{
    Q_OBJECT
public:
                   /**
                    * @brief VToolNormal constructor.
                    * @param doc dom document container.
                    * @param data container with variables.
                    * @param id object id in container.
                    * @param typeLine line type.
                    * @param formula string with formula normal length.
                    * @param angle additional angle.
                    * @param firstPointId id first line point.
                    * @param secondPointId id second line point.
                    * @param typeCreation way we create this tool.
                    * @param parent parent object.
                    */
                   VToolNormal(VPattern *doc, VContainer *data, const quint32 &id, const QString &typeLine,
                               const QString &formula, const qreal &angle, const quint32 &firstPointId,
                               const quint32 &secondPointId, const Valentina::Sources &typeCreation,
                               QGraphicsItem * parent = nullptr);
    /**
     * @brief setDialog set dialog when user want change tool option.
     */
    virtual void   setDialog();
    /**
     * @brief Create help create tool from GUI.
     * @param dialog dialog.
     * @param scene pointer to scene.
     * @param doc dom document container.
     * @param data container with variables.
     */
    static void    Create(DialogTool *dialog, VMainGraphicsScene  *scene, VPattern *doc, VContainer *data);
    /**
     * @brief Create help create tool.
     * @param _id tool id, 0 if tool doesn't exist yet.
     * @param formula string with formula normal length.
     * @param firstPointId id first line point.
     * @param secondPointId id second line point.
     * @param typeLine line type.
     * @param pointName point name.
     * @param angle additional angle.
     * @param mx label bias x axis.
     * @param my label bias y axis.
     * @param scene pointer to scene.
     * @param doc dom document container.
     * @param data container with variables.
     * @param parse parser file mode.
     * @param typeCreation way we create this tool.
     */
    static void    Create(const quint32 _id, QString &formula, const quint32 &firstPointId,
                          const quint32 &secondPointId, const QString &typeLine, const QString &pointName,
                          const qreal angle, const qreal &mx, const qreal &my, VMainGraphicsScene  *scene,
                          VPattern *doc, VContainer *data, const Document::Documents &parse,
                          const Valentina::Sources &typeCreation);
    /**
     * @brief FindPoint return normal point.
     * @param firstPoint first line point.
     * @param secondPoint second line point.
     * @param length normal length.
     * @param angle additional angle.
     * @return normal point.
     */
    static QPointF FindPoint(const QPointF &firstPoint, const QPointF &secondPoint, const qreal &length,
                             const qreal &angle = 0);
    static const QString ToolType;
public slots:
    /**
     * @brief FullUpdateFromFile update tool data form file.
     */
    virtual void   FullUpdateFromFile();
    /**
     * @brief SetFactor set current scale factor of scene.
     * @param factor scene scale factor.
     */
    virtual void   SetFactor(qreal factor);
    /**
     * @brief ShowContextMenu show context menu.
     * @param event context menu event.
     */
    virtual void   ShowContextMenu(QGraphicsSceneContextMenuEvent *event);
protected:
    /**
     * @brief contextMenuEvent handle context menu events.
     * @param event context menu event.
     */
    virtual void   contextMenuEvent ( QGraphicsSceneContextMenuEvent * event );
    /**
     * @brief AddToFile add tag with informations about tool into file.
     */
    virtual void   AddToFile();
    /**
     * @brief RefreshDataInFile refresh attributes in file. If attributes don't exist create them.
     */
    virtual void   RefreshDataInFile();
    /**
     * @brief RemoveReferens decrement value of reference.
     */
    virtual void   RemoveReferens();
    /**
     * @brief SaveDialog save options into file after change in dialog.
     */
    virtual void   SaveDialog(QDomElement &domElement);
private:
    /**
     * @brief secondPointId id second line point.
     */
    quint32         secondPointId;
};

#endif // VTOOLNORMAL_H
