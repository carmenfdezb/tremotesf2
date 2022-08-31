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

#ifndef TREMOTESF_TEXTINPUTDIALOG_H
#define TREMOTESF_TEXTINPUTDIALOG_H

#include <QDialog>

class QLineEdit;
class QPlainTextEdit;

namespace tremotesf
{
    class TextInputDialog : public QDialog
    {
        Q_OBJECT

    public:
        explicit TextInputDialog(const QString& title,
                                 const QString& labelText,
                                 const QString& text,
                                 const QString& okButtonText,
                                 bool multiline,
                                 QWidget* parent = nullptr);
        QSize sizeHint() const override;
        QString text() const;

    private:
        QLineEdit* mLineEdit = nullptr;
        QPlainTextEdit* mPlainTextEdit = nullptr;
    };
}

#endif
