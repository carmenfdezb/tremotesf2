 /*
 * Tremotesf
 * Copyright (C) 2015-2019 Alexey Rochev <equeim@gmail.com>
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

#ifndef TREMOTESF_IPCCLIENT_H
#define TREMOTESF_IPCCLIENT_H

#include <memory>
#include <QStringList>

namespace tremotesf
{
    class IpcClient
    {
    public:
        static std::unique_ptr<IpcClient> createInstance();

        IpcClient() = default;

        Q_DISABLE_COPY(IpcClient)

        IpcClient(IpcClient&&) = delete;
        IpcClient& operator=(IpcClient&&) = delete;

        virtual ~IpcClient() = default;
        virtual bool isConnected() const = 0;
        virtual void activateWindow() = 0;
        virtual void addTorrents(const QStringList& files, const QStringList& urls) = 0;
    };
}

#endif // TREMOTESF_IPCCLIENT_H
