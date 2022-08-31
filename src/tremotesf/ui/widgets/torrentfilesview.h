/*
 * Tremotesf
 * Copyright (C) 2015-2018 Alexey Rochev <equeim@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TREMOTESF_TORRENTFILESVIEW_H
#define TREMOTESF_TORRENTFILESVIEW_H

#include <functional>

#include "basetreeview.h"

namespace tremotesf
{
    class BaseTorrentFilesModel;
    class LocalTorrentFilesModel;
    class Rpc;
    class TorrentFilesModel;
    class TorrentFilesProxyModel;

    class TorrentFilesView : public BaseTreeView
    {
        Q_OBJECT

    public:
        explicit TorrentFilesView(LocalTorrentFilesModel* model, Rpc* rpc, QWidget* parent = nullptr);
        explicit TorrentFilesView(TorrentFilesModel* model,
                                  Rpc* rpc,
                                  QWidget* parent = nullptr);
        ~TorrentFilesView() override;

        static void showFileRenameDialog(const QString& fileName, QWidget* parent, const std::function<void(const QString&)>& onAccepted);

    private:
        void init();
        void onModelReset();
        void showContextMenu(QPoint pos);

    private:
        bool mLocalFile;
        BaseTorrentFilesModel* mModel;
        TorrentFilesProxyModel* mProxyModel;
        Rpc* mRpc;
    };
}

#endif // TREMOTESF_TORRENTFILESVIEW_H
